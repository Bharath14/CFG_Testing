#include "database.h"
int main()
{
    create_database();
    load_database();
    account a1 = {1, 12000, 1};
    account a2 = {2, 20000, 2};
    account a3 = {3, 30000, 2};
    insert_account(&a1);
    insert_account(&a2);
    transaction(a3.account_id, -2000);
    if(get_balance(a3.account_id) == -1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
    close_database();
}