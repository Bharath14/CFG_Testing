#ifndef DATABASE_H
#define DATABASE_H

#define USER_DAT "./database/user.dat"
#define ACCOUNT_DAT "./database/account.dat"
#define USER_NDX "./database/user.ndx"
#define ACCOUNT_NDX "./database/account.ndx"
#define USER_LIMIT 100
#define ACCOUNT_LIMIT 100

#define SEM_USER_NDX 0
#define SEM_USER_FD 1
#define SEM_ACCOUNT_NDX 3
#define SEM_ACCOUNT_FD 4


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


struct DB{

    int user_index[USER_LIMIT];
    int account_index[ACCOUNT_LIMIT];
    int user_fd;
    int account_fd;
    int max_user_id;
    int max_account_id;
    int sem_id;

}*db_info;

int create_database();
int load_database();
int close_database();
int sem_lock(int i);
int sem_unlock(int i);
int insert_user(user *u);
int insert_account(account *a);
int get_account_index(int account_id);
int get_user_index(int user_id);
int lock_account(int ndx, int type);
int lock_user(int ndx, int type);
int delete_user(int user_id);
int get_balance(int account_id);
int transaction(int account_id, float amount);
int check_password(int user_id, char password[30]);
int change_password(int user_id, char password[30]);
int search(int user_id, user * u, account * a);
int get_account_id(int user_id);
int attach_new_user(int account_id);
int logout(int user_id);

#endif