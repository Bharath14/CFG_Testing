#include "database.h"
int main()
{
    create_database();
    load_database();
    account a1 = {1, 12000, 1};
    account a2 = {2, 20000, 2};
    insert_account(&a1);
    insert_account(&a2);
    if(get_account_index(a2.account_id) == 1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
    close_database();
}