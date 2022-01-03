#ifndef CLIENT_H
#define CLIENT_H

typedef struct account{

    int account_id;
    float balance;
    int number_of_users;


}account;

typedef struct user{

    int user_id;
    char name[30];
    char password[30];
    int account_id;
    int online;
    char type;


}user;

#endif