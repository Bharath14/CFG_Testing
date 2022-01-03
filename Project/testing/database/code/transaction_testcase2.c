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
    transaction(a2.account_id, -25000);
    if(get_balance(a2.account_id) == 20000)
    {
        return 0;
    }
    else
    {
        return 1;
    }
    close_database();
}