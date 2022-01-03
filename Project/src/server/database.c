#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<sys/stat.h>
#include<sys/sem.h>
#include<sys/shm.h>
#include<sys/ipc.h>

#include "database.h"

int shmid;

int create_database(){

    
    mkdir("./database", 0744);

    user u;
    u.user_id = 0;
    u.type = 'A';
    strcpy(u.name,"Super User");
    strcpy(u.password, "qwerty");
    u.online = 0;

    int fd = open(USER_DAT, O_WRONLY | O_CREAT , 0744);
    write(fd, &u, sizeof(user));
    close(fd);

    int i[USER_LIMIT] = {[0 ... 99] = -1};
    i[0] = 0;
    fd = open(USER_NDX, O_WRONLY | O_CREAT , 0744);
    write(fd, i, USER_LIMIT * sizeof(int));
    write(fd, 0, sizeof(int));
    close(fd);
    


    fd = open(ACCOUNT_DAT, O_CREAT , 0744);
    close(fd);
    
    int j[ACCOUNT_LIMIT] = {[0 ... 99] = -1};
    fd = open(ACCOUNT_NDX, O_WRONLY | O_CREAT , 0744);
    write(fd, j,ACCOUNT_LIMIT * sizeof(int));
    write(fd, 0, sizeof(int));
    close(fd);


}

int load_database(){

    int shmkey = ftok(".",'m');

    shmid = shmget(shmkey, sizeof(struct DB), IPC_CREAT | 0744);
    db_info = shmat(shmid, (void*)0,0);

    int fd = open(USER_NDX, O_RDONLY);
    read(fd, db_info->user_index, USER_LIMIT * sizeof(int));
    read(fd, &db_info->max_user_id, sizeof(int));
    close(fd);


    fd = open(ACCOUNT_NDX, O_RDONLY);
    read(fd, db_info->account_index, ACCOUNT_LIMIT * sizeof(int));
    read(fd, &db_info->max_account_id, sizeof(int));
    close(fd);


    db_info->account_fd = open(ACCOUNT_DAT, O_RDWR);
    db_info->user_fd = open(USER_DAT, O_RDWR);


    union{

        int val;
        struct semid_ds *buf;
        unsigned short int *array;
    }semun;

    int key, semid;

    key = ftok(".",'a');
    semid = semget(key, 4, IPC_CREAT| 0744);
    semun.val = 1;

    for(int i = 0; i < 4; i++){
        semctl(semid, i, SETVAL, semun);
    }

    db_info->sem_id = semid;
    



}

int close_database(){

    int fd = open(USER_NDX, O_WRONLY | O_TRUNC);
    write(fd, db_info->user_index, USER_LIMIT * sizeof(int));
    write(fd, &db_info->max_user_id, sizeof(int));
    close(fd);

    fd = open(ACCOUNT_NDX, O_WRONLY | O_TRUNC);
    write(fd, db_info->account_index, ACCOUNT_LIMIT * sizeof(int));
    write(fd, &db_info->max_account_id, sizeof(int));
    close(fd);

    sem_lock(SEM_USER_FD);

    lseek(db_info->user_fd,0,SEEK_SET);
    user u;

    while(read(db_info->user_fd,&u, sizeof(user))){
        u.online = 0;
        lseek(db_info->user_fd, -sizeof(user), SEEK_CUR);
        write(db_info->user_fd, &u, sizeof(user));
    }

    union{
        int val;
        struct semid_ds *buf;
        unsigned short int *array;
    }semun;

    int key, semid;

    key = ftok(".",'a');
    semid = semget(key, 4, 0);

    for(int i = 0; i < 4; i++)
        semctl(semid, i, IPC_RMID, semun);

    
      

    close(db_info->account_fd);
    close(db_info->user_fd);

    shmdt(db_info);
    shmctl(shmid, IPC_RMID, NULL);
    


}

int sem_lock(int i){

    struct sembuf buf = {i, -1, 0};


    semop(db_info->sem_id, &buf, 1);

}

int sem_unlock(int i){

    struct sembuf buf = {i, 1, 0};


    semop(db_info->sem_id, &buf, 1);  

}

int insert_user(user *u){

    int offset = -1;

    sem_lock(SEM_USER_NDX);

    u->user_id = (++db_info->max_user_id);

    for(int i = 0; i < USER_LIMIT; i++){

        if(db_info->user_index[i] == -1){
            offset = i * sizeof(user);
            db_info->user_index[i] = u->user_id;
            break;
        }

    }

    sem_unlock(SEM_USER_NDX);

    if(offset == -1){
        return -1;
    }


    sem_lock(SEM_USER_FD);

    lseek(db_info->user_fd, offset, SEEK_SET);
    write(db_info->user_fd, u, sizeof(user));

    sem_unlock(SEM_USER_FD);

    return u->user_id;

}

int insert_account(account *a){

    int offset = -1;

    sem_lock(SEM_ACCOUNT_NDX);

    a->account_id = (++db_info->max_account_id);
    for(int i = 0; i < ACCOUNT_LIMIT; i++){

        if(db_info->account_index[i] == -1){
            offset = i * sizeof(account);
            db_info->account_index[i] = a->account_id;
            break;
        }

    }

    sem_unlock(SEM_ACCOUNT_NDX);


    if(offset == -1){
        return -1;
    }

    

    sem_lock(SEM_ACCOUNT_FD);
    lseek(db_info->account_fd, offset, SEEK_SET);
    write(db_info->account_fd, a, sizeof(account));
    sem_unlock(SEM_ACCOUNT_FD);

    return 0;    
}

int get_account_index(int account_id){

    sem_lock(SEM_ACCOUNT_NDX);

    for(int i = 0; i < ACCOUNT_LIMIT; i++){
        printf("%d ",db_info->account_index[i]);
        if(db_info->account_index[i] == account_id){
            sem_unlock(SEM_ACCOUNT_NDX);
            return i;
        }

    }

    sem_unlock(SEM_ACCOUNT_NDX);

    return -1;

}

int get_user_index(int user_id){

    sem_lock(SEM_USER_NDX);

    for(int i = 0; i < USER_LIMIT; i++){

        if(db_info->user_index[i] == user_id){
            sem_unlock(SEM_USER_NDX);
            return i;
        }

    }

    sem_unlock(SEM_USER_NDX);

    return -1;

}

int lock_account(int ndx, int type){

    int offset = ndx * sizeof(account);

    struct flock l1;

    if(type == 0){
        l1.l_type =  F_RDLCK;
    }
    else if(type == 1){
        l1.l_type = F_WRLCK;
        printf("writeLocked\n");
    }
    else if(type == -1){
        l1.l_type = F_UNLCK;
        printf("unlocked\n");
    }

    l1.l_whence = SEEK_SET;
    l1.l_start =  offset;
    l1.l_len = sizeof(account);
    l1.l_pid =  getpid();

    if(type == -1){
        fcntl(db_info->account_fd, F_SETLK, &l1);
    }
    else{
        int i = fcntl(db_info->account_fd, F_SETLKW, &l1);
        printf("i %d %ld\n", offset, l1.l_len);
        perror("fcntl");
    }

    return 0;

}

int lock_user(int ndx, int type){

    int offset = ndx * sizeof(user);

    struct flock l1;

    if(type == 0){
        l1.l_type =  F_RDLCK;
    }
    else if(type == 1){
        l1.l_type = F_WRLCK;
    }
    else if(type == -1){
        l1.l_type = F_UNLCK;
    }

    l1.l_whence = SEEK_SET;
    l1.l_start =  offset;
    l1.l_len = sizeof(user);
    l1.l_pid =  getpid();

    if(type == -1){
        fcntl(db_info->user_fd, F_SETLK, &l1);
    }
    else{
        fcntl(db_info->user_fd, F_SETLKW, &l1);
    }


}

int delete_user(int user_id){

    int ndx = get_user_index(user_id);
    if(ndx == -1)
        return -1;

    sem_lock(SEM_USER_NDX);

    db_info->user_index[ndx] = -1;

    sem_unlock(SEM_USER_NDX);
    
    int offset = ndx * sizeof(user);

    lock_user(ndx, 1);
    user u;

    sem_lock(SEM_USER_FD);
    lseek(db_info->user_fd, offset, SEEK_SET);
    read(db_info->user_fd, &u, sizeof(u));
    sem_unlock(SEM_USER_FD);

    int acc_ndx = get_account_index(u.account_id);
    int acc_offset = acc_ndx * sizeof(account);
    
    lock_account(acc_ndx, 1);
    account a;

    sem_lock(SEM_ACCOUNT_FD);
    lseek(db_info->account_fd, acc_offset, SEEK_SET);
    read(db_info->account_fd, &a, sizeof(account));
    sem_unlock(SEM_ACCOUNT_FD);

    if(a.number_of_users > 1){
        a.number_of_users -= 1;
    
        sem_lock(SEM_ACCOUNT_FD);
        lseek(db_info->account_fd, acc_offset, SEEK_SET);
        write(db_info->account_fd, &a, sizeof(account));
        sem_unlock(SEM_ACCOUNT_FD);

    }
    else{

        sem_lock(SEM_ACCOUNT_NDX);

        db_info->account_index[acc_ndx] = -1;

        sem_unlock(SEM_ACCOUNT_NDX);

    }

    lock_account(acc_ndx, -1);
    lock_user(ndx, -1);

    return 0;

}

int get_balance(int account_id){

    int ndx = get_account_index(account_id);
    if(ndx == -1)
        return -1;

    lock_account(ndx, 0);
    account a;
    int offset = ndx * sizeof(account);

    sem_lock(SEM_ACCOUNT_FD);
    lseek(db_info->account_fd, offset, SEEK_SET);
    read(db_info->account_fd, &a, sizeof(account));
    sem_unlock(SEM_ACCOUNT_FD);
    
    lock_account(ndx, -1);

    return a.balance;


}

int transaction(int account_id, float amount){

    int ndx = get_account_index(account_id);

    if(ndx == -1){
        return -1;
    }

    lock_account(ndx, 1);
    account a;
    int offset = ndx * sizeof(account);

    sem_lock(SEM_ACCOUNT_FD);
    lseek(db_info->account_fd, offset, SEEK_SET);
    read(db_info->account_fd, &a, sizeof(a));
    sem_unlock(SEM_ACCOUNT_FD);

    if(a.balance + amount > 0){

        printf("%f %f\n",a.balance, amount);
        a.balance += amount;
        printf("%f\n",a.balance);


        sem_lock(SEM_ACCOUNT_FD);
        lseek(db_info->account_fd, offset, SEEK_SET);
        write(db_info->account_fd, &a, sizeof(a));
        sem_unlock(SEM_ACCOUNT_FD);

        lock_account(ndx, -1);

        return 0;

    }
    else{

        lock_account(ndx, -1);
        return -2;
    }



}

int check_password(int user_id, char password[30]){

    int ndx = get_user_index(user_id);

    if(ndx == -1)
        return -1;

    int offset = ndx * sizeof(user);
    lock_user(ndx, 1);
    user u;

    sem_lock(SEM_USER_FD);
    lseek(db_info->user_fd, offset, SEEK_SET);
    read(db_info->user_fd, &u, sizeof(user));


    if(!strcmp(password, u.password)){
        
        if(u.online == 1){
            
            sem_unlock(SEM_USER_FD);
            lock_user(ndx, -1);
            return 3;
        }
        else{
            
            u.online = 1;
            lseek(db_info->user_fd, offset, SEEK_SET);
            write(db_info->user_fd, &u, sizeof(user));
            sem_unlock(SEM_USER_FD);
            
            lock_user(ndx, -1);

            if(u.type == 'A'){
                return 2;
            }
            else{
                return 1;
            }
        }
        
    }
    
    sem_unlock(SEM_USER_FD); 
    lock_user(ndx, -1);
    return 0;    
    

}

int logout(int user_id){

    int ndx = get_user_index(user_id);

    if(ndx == -1)
        return -1;

    int offset = ndx * sizeof(user);
    lock_user(ndx, 1);
    user u;

    sem_lock(SEM_USER_FD);
    lseek(db_info->user_fd, offset, SEEK_SET);
    read(db_info->user_fd, &u, sizeof(user));

    u.online = 0;
    lseek(db_info->user_fd, offset, SEEK_SET);
    write(db_info->user_fd, &u, sizeof(user));
    sem_unlock(SEM_USER_FD);

    lock_user(ndx, -1);

    return 0;

}

int change_password(int user_id, char password[30]){

    int ndx = get_user_index(user_id);

    if(ndx == -1)
        return -1;

    int offset = ndx * sizeof(user);
    lock_user(ndx, 1);
    user u;

    sem_lock(SEM_USER_FD);
    lseek(db_info->user_fd, offset, SEEK_SET);
    read(db_info->user_fd, &u, sizeof(user));

    strcpy(u.password, password);

    lseek(db_info->user_fd, offset, SEEK_SET);
    write(db_info->user_fd, &u, sizeof(user));

    sem_unlock(SEM_USER_FD);

    lock_user(ndx, -1);

}

int search(int user_id, user * u, account * a){

    int ndx = get_user_index(user_id);
    printf("%d\n", ndx);
    if( ndx == -1)
        return -1;

    int offset = ndx * sizeof(user);

    lock_user(ndx, 0);

    sem_lock(SEM_USER_FD);
    lseek(db_info->user_fd, offset, SEEK_SET);
    read(db_info->user_fd, u, sizeof(user));
    sem_unlock(SEM_USER_FD);

    lock_user(ndx, -1);

    int acc_ndx = get_account_index(u->account_id);

    offset = acc_ndx * sizeof(account);

    lock_account(acc_ndx, 1);

    sem_lock(SEM_ACCOUNT_FD);
    lseek(db_info->account_fd, offset, SEEK_SET);
    read(db_info->account_fd, a, sizeof(user));
    sem_unlock(SEM_ACCOUNT_FD);

    // lock_account(ndx,-1);

    return 0;
}

int get_account_id(int user_id){

    int ndx = get_user_index(user_id);
    int offset = ndx * sizeof(user);
    user u;

    lock_user(ndx, 0);

    sem_lock(SEM_USER_FD);
    lseek(db_info->user_fd, offset, SEEK_SET);
    read(db_info->user_fd, &u, sizeof(u));
    sem_unlock(SEM_USER_FD);

    lock_user(ndx, -1);

    return u.account_id;

}

int attach_new_user(int account_id){

    int ndx = get_account_index(account_id);
    
    if(ndx == -1){
        return -1;
    }

    int offset = ndx * sizeof(account);

    

    account a;

    lock_account(ndx,1);

    sem_lock(SEM_ACCOUNT_FD);
    lseek(db_info->account_fd, offset, SEEK_SET);
    read(db_info->account_fd, &a, sizeof(account));
    a.number_of_users++;
    lseek(db_info->account_fd, offset, SEEK_SET);
    write(db_info->account_fd, &a, sizeof(account));

    sem_unlock(SEM_ACCOUNT_FD);

    lock_account(ndx, -1);

    return 0;
    

}
int main(){

    // create_database();
    // user u = {3, "Jim", "qewy", 2, 0, 'A'};
    // account a = {2, 12000, 1};

    // // user u1;
    // // account a1;

    // printf("%d\n", u.user_id);

    load_database();
    // // insert_user(&u);
    // // insert_account(&a);
    // // search(3, &u1, &a1);
    // // transaction(2, -23000);
    // change_password(3, "bleh");
    int b = check_password(0, "qwerty");
    close_database();

    printf("%d\n", b);



}