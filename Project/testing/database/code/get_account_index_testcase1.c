#include "database.h"
int main()
{
    create_database();
    load_database();
    account a1 = {1, 12000, 1};
    insert_account(&a1);

    if(get_account_index(a1.account_id) == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
    close_database();
}