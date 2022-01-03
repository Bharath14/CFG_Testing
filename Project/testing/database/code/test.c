#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>

typedef struct user{

    int user_id;
    char name[30];
    char password[30];
    int account_id;
    int online;
    char type;


}user;

int main(){

    user u;
    
    int fd = open("./database/user.ndx", O_RDONLY);
    // read(fd, &u, sizeof(user));
    // read(fd, &u, sizeof(user));

    // printf("%c %d %s", u.type, u.account_id, u.name);

    int i[100] = {-2};

    for(int j = 0; j < 100; j++){

        printf("%d ",i[j]);
    }
    printf("\n");
    read(fd, i, 100 * sizeof(int));

    for(int j = 0; j < 100; j++){

        printf("%d ",i[j]);
    }

    // read(fd, &u, sizeof(u));
    // read(fd, &u, sizeof(u));

    // printf("%d %s\n", u.user_id, u.name);

    close(fd);



}
