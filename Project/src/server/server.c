#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
#include<signal.h>
#include<sys/socket.h>
#include<netinet/in.h>

#include "database.h"

struct args{

    int nsd;

};

void sigint_handler(int signum){

    close_database();
    exit(0);

}

int login(int sd, int *type){

    while(1){
        int user_id;
        char password[30];

        read(sd, &user_id, sizeof(int));
        

        if(user_id == -1){
            return -1;
        }

        read(sd, password, 30);

        int result = check_password(user_id, password);
        write(sd, &result, sizeof(int));
        *type = result;

        if(result == 3){
            return -1;
        }

        if(result != 0)
            return user_id;
    }
}


int customer_interface(int sd, int user_id){

    int choice;

    int account_id = get_account_id(user_id);

    do{

        read(sd, &choice, sizeof(int));

        switch(choice){

            case 1:{
                float balance = get_balance(account_id);
                write(sd,&balance, sizeof(balance));
                break;
            }
            case 2: case 3:{
                int ret; float amount;
                read(sd, &amount, sizeof(amount));
                ret = transaction(account_id, amount);
                write(sd, &ret, sizeof(int));
                break;
            }
            case 4:{
                char password[30];
                read(sd, password, 30);
                change_password(user_id, password);
                break;
            }    
            case 5:{
                user u; account a;
                search(user_id, &u, &a);
                int ndx = get_account_index(a.account_id);
                lock_account(ndx, -1);
                write(sd,&u.user_id, sizeof(int));
                write(sd,&u.name, 30);
                write(sd,&u.account_id, sizeof(int));
                write(sd,&a.number_of_users, sizeof(int));
                write(sd,&u.password, 30);
                break;
            }
            case 6:{
                logout(user_id);
            }

            
        }

    }while(choice != 6);


}

int create_user(int sd){

    printf("entered function\n");
    user u; int choice;

    read(sd, &u, sizeof(user));
    read(sd, &choice, sizeof(int));
    printf("%d\n", choice);
    if(choice == 1){
        account a;
        read(sd, &a, sizeof(account));
        printf("c\n");
        insert_account(&a);
        u.account_id = a.account_id;
        printf("b\n");
        write(sd, &u.account_id, sizeof(int));
    }
    else{

        while(1){
            read(sd, &u.account_id, sizeof(int));       

            if(attach_new_user(u.account_id) == -1){
                int a = -1;
                write(sd, &a, sizeof(int));
            }
            else{
                int a = 1;
                write(sd, &a, sizeof(int));
                break;
            }
        }
        
    }

    insert_user(&u);
    write(sd, &u.user_id, sizeof(int));
    return 0;

}

int add_admin(int sd){

    user u; 

    read(sd, &u, sizeof(user));
    insert_user(&u);
    write(sd, &u.user_id, sizeof(int));

}

int delete_user_server(int sd){

    int user_id;
    read(sd, &user_id, sizeof(int));
    int result = delete_user(user_id);
    write(sd, &result, sizeof(int));

}

int search_user(int sd){

    int user_id;
    int result;
    user u;
    account a;
    read(sd, &user_id, sizeof(int));
    result = search(user_id, &u, &a);

    write(sd, &result, sizeof(int));

    if(result != -1){

        write(sd, &u, sizeof(user));
        write(sd, &a, sizeof(account));

        read(sd, &result, sizeof(int));

        switch(result){

            case 1:case 2:{

                float amount;
                read(sd, &amount, sizeof(float));
                result = transaction(a.account_id, amount);
                write(sd, &result, sizeof(int));
                break;
            }
                
        }


    }

    int ndx = get_account_index(a.account_id);
    lock_account(ndx, -1);
}

int admin_interface(int sd, int user_id){

    int choice;

    int account_id = get_account_id(user_id);

    do{
        printf("waiting for choice\n");
        read(sd, &choice, sizeof(int));
        printf("choice %d\n", choice);

        switch(choice){

            case 1:{
                create_user(sd);
                break;
            }
            case 2:{
                delete_user_server(sd);
                break;
            }
            case 3:{
                search_user(sd);
                break;
            }    
            case 4:{
                char password[30];
                read(sd, password, 30);
                change_password(user_id, password);
                break;
            }
            case 5:{
                add_admin(sd);
                break;
            }
            case 6:{
                
                logout(user_id);
                break;
            }

            
        }

    }while(choice != 6);

    printf("a\n");


}

void thread_function(int sd){

    int type;
    int user_id = login(sd, &type);

    if(user_id == -1){
        exit(0);
    }

    if(type == 1)
        customer_interface(sd, user_id);
    else if(type == 2)
        admin_interface(sd, user_id);
}

int main(){

    // create_database();
    struct sockaddr_in server, client;
    int err;
    int sd = socket(AF_INET, SOCK_STREAM, 0);
    int port_number = 8000;

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(port_number);

    load_database();
    signal(SIGINT, &sigint_handler);

    bind(sd, (struct sockaddr *)&server, sizeof(server));

    listen(sd,1);

    

    int sizeof_client = sizeof(client);
    int nsd;

    char buffer[80];



    while(1){
        
        nsd = accept(sd, (struct sockaddr *)&client, &sizeof_client );
        struct args a;
        a.nsd = nsd;
        if(!fork()){
            thread_function(nsd);
            exit(0);
        } 
    }
    printf("exit\n");
    close_database();


}