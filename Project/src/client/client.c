#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>

#include "client.h"

int sd;

int login(){

    int choice = 1;
    do
    {

    
        int user_id;
        printf("Enter the user id: ");
        scanf("%d", &user_id);

        char password[30];
        printf("Enter your password: ");
        scanf("%s", password);
        write(sd, &user_id, sizeof(int));
        write(sd, password, 30);

        int result;
        read(sd, &result, sizeof(int));


        if(result == 1){
            printf("Successfully logged in\n");
            return 0;
        }
        else if(result == 2){
            printf("Successfully logged in\n");
            return 1;
        }
        else if(result == 3){
            printf("The account is already logged in from another terminal\n");
        }
        
        if(result == -1){    //else missing. got from checking infeasible prime paths
            printf("Wrong user id\n");
        }
        else if(result == 0){
            printf("Wrong password\n");
        }

        printf("Try again?(1: yes, 0: no)\n");
        scanf("%d", &choice);
    }    
    while(choice == 1);
    
    int disconnect = -1;
    write(sd, &disconnect, sizeof(int));
    close(sd);

    exit(0);
    

}

void balance_enquiry(){

    float balance;
    read(sd, &balance, sizeof(balance));
    printf("Current balance: %f\n", balance);

}

void deposit(){

    float amount;
    int ret;

    printf("Enter the amount to be deposited: ");
    scanf("%f", &amount);

    write(sd, &amount, sizeof(amount));
    read(sd, &ret, sizeof(int));

    
}

void withdraw(){

    float amount;
    int ret;

    printf("Enter the amount to be withdrawn: ");
    scanf("%f", &amount);
    amount = - amount;
    write(sd, &amount, sizeof(amount));
    read(sd, &ret, sizeof(int));

    if(ret == 0){

        printf("Transaction successful\n");

    }
    else{
        printf("Not enough funds");
    }


    

}

void change_password(){

    char password[30];
    printf("Enter the new password: ");
    scanf("%s", password);
    write(sd, password, 30);
    printf("password changed\n");

}

void view_details(){

    int user_id, account_id, number_of_users;
    char name[30], password[30];
    read(sd,&user_id, sizeof(int));
    read(sd,&name, 30);
    read(sd,&account_id, sizeof(int));
    read(sd,&number_of_users, sizeof(int));
    read(sd,&password, 30);

    printf("Details\n");
    printf("User Id: %d\n", user_id);
    printf("Name: %s\n", name);
    printf("Account id: %d\n", account_id);
    printf("Number of users attached to account: %d\n", number_of_users);
    printf("Password: %s\n", password);

}

int menu_loop(){

    int choice;

    do{

        printf("\nMenu\n");
        printf("1:Balance enquiry\n");
        printf("2:Deposit\n");
        printf("3:Withdraw\n");
        printf("4:Change Password\n");
        printf("5:View details\n");
        printf("6:Exit\n");
        scanf("%d", &choice);

        write(sd, &choice, sizeof(int));

        switch(choice){

            case 1:
                balance_enquiry();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                change_password();
                break;
            case 5:
                view_details();
                break;    


        }


    }while(choice != 6);
}

int add_user(){

    user u;
    int account_number;

    printf("Enter the name: ");
    scanf("%s", u.name);
    printf("Enter the password: ");
    scanf("%s", u.password);
    u.type = 'C';
    u.online = 0;
    write(sd, &u, sizeof(user));
    int choice;
    while(1){
        printf("Account Choice\n1:Add new account\n2:Share existing account\n");
        scanf("%d", &choice);
        if(choice == 1){
            
            write(sd, &choice, sizeof(int));
            account a;
            printf("Enter initial deposit amount: ");
            scanf("%f", &a.balance);
            a.number_of_users = 1;
            write(sd, &a, sizeof(account));
            read(sd, &a.account_id, sizeof(int));
            account_number = a.account_id;
            break;
        }
        else if(choice == 2){
            
            write(sd, &choice, sizeof(int));
            int result;
            
            while(1){
                printf("Enter the account number: ");
                scanf("%d", &account_number);
                write(sd, &account_number, sizeof(int));
                read(sd, &result, sizeof(int));

                if(result == -1){
                    printf("The account number does not exist. Try again.\n");
                    continue;
                }
                else{                 
                    break;
                }            
            }
            break;
            
        }
        else{
            printf("Please enter a valid choice. \n");
            continue;
        }

        
    }

    read(sd, &u.user_id, sizeof(int));
    printf("User successfully added.\nUser ID: %d\nAccount ID: %d\n", u.user_id, account_number);
    return 0;
    

}

int delete_user(){

    int user_id, result;
    printf("Enter the user id to delete: ");
    scanf("%d", &user_id);
    write(sd, &user_id, sizeof(int));

    read(sd, &result, sizeof(int));

    if(result == -1){
        printf("User ID doesn't exist\n");
    }
    else{
        printf("User successfully deleted\n");
    }


}

int add_admin(){

    user u;
    int id;

    printf("Enter the name: ");
    scanf("%s", u.name);
    printf("Enter the password: ");
    scanf("%s", u.password);
    u.type = 'A';
    u.online = 0;
    write(sd, &u, sizeof(user));

    read(sd, &id, sizeof(int));

    printf("User Id: %d\n", id);


}

int search_user(){

    int user_id;
    printf("Enter the user ID: ");
    scanf("%d", &user_id);
    write(sd, &user_id, sizeof(int));

    int result;
    read(sd, &result, sizeof(result));

    if(result != -1){
        user u;
        account a;
        
        read(sd, &u, sizeof(user));
        read(sd, &a, sizeof(account));

        printf("Details\n");
        printf("User Id: %d\n", user_id);
        printf("Name: %s\n", u.name);
        printf("Account id: %d\n", u.account_id);
        printf("Password: %s\n", u.password);
        printf("Balance: %f\n",a.balance);
        printf("Number of users attached to account: %d\n", a.number_of_users);

        while(1){

            printf("Change balance?\n1:Deduct Balance\n2:Add Balance\n3:No change\n");
            scanf("%d", &result);
            if(result > 0 & result < 4){
                write(sd, &result, sizeof(int));

                if(result == 1){
                    float amount;
                    printf("Enter the amount to deduct: ");
                    scanf("%f", &amount);
                    amount = -amount;
                    write( sd, &amount, sizeof(float));
                    read(sd, &result, sizeof(int));
                    if(result == 0){
                        printf("Operation successful\n");
                    }
                    else{
                        printf("Not enough balance\n");
                    }
                }

                else if(result == 2){
                    float amount;
                    printf("Enter the amount to add: ");
                    scanf("%f", &amount);
                    write( sd, &amount, sizeof(float));
                    read(sd, &result, sizeof(int));
                    printf("Operation successful\n");
                }

                break;
            }
        }
            
        
        
        
    }
    else{
        printf("User ID doesn't exist\n");
    }

}

int admin_menu_loop(){

    int choice;

    do{

        printf("\nMenu\n");
        printf("1:Add User\n");
        printf("2:Delete User\n");
        printf("3:Search for User\n");
        printf("4:Change Password\n");
        printf("5:Add Admin\n");
        printf("6:Exit\n");
        scanf("%d", &choice);

        write(sd, &choice, sizeof(int));

        switch(choice){

            case 1:
                add_user();
                break;  
            case 2:
                delete_user();
                break;
            case 3:
                search_user();
                break;   
            case 4:
                change_password();
                break;
            case 5:
                add_admin();
                break;    

        }


    }while(choice != 6);
}

int main(){

    struct sockaddr_in server;

    sd = socket(AF_INET, SOCK_STREAM, 0);
    
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    int port_number = 8000;
    server.sin_port = htons(port_number);

    connect(sd, (struct sockaddr *)&server, sizeof(server));

    int login_type = login();    
    if(login_type == 0){
        menu_loop();
    }
    else{
        admin_menu_loop();

    }


}

