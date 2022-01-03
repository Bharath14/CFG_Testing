#include "database.h"
int main()
{
    create_database();
    load_database();
    account a1 = {1, 12000, 1};
    account a2 = {2, 20000, 2};
    account a3 = {3, 30000, 1};
    account a4 = {4, 40000, 1};
    account a5 = {5, 50000, 1};
    account a6 = {6, 60000, 2};
    insert_account(&a1);
    insert_account(&a2);
    insert_account(&a3);
    insert_account(&a4);
    insert_account(&a5);
    int value = insert_account(&a6);
    if(value == -1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
    close_database();
}