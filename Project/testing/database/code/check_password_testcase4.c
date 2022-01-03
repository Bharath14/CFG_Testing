#include "database.h"

int main()
{
    create_database();
    load_database();
    account a1 = {1, 12000, 1};
    account a2 = {2, 20000, 2};
    account a3 = {3, 30000, 1};

    insert_account(&a1);
    insert_account(&a2);
    insert_account(&a3);

    user u1 = {1, "Jim", "qewy", a1.account_id , 0, 'A'};
    user u2 = {2, "Jom", "qwy", a2.account_id, 0, 'B'};
    user u3 = {3, "Jam", "ewy", a2.account_id, 1, 'B'};
    user u4 = {4, "Jem", "yeq", a3.account_id, 0, 'B'};

    insert_user(&u1);
    insert_user(&u2);
    insert_user(&u3);

    if(check_password(u1.user_id, "qewwwy") == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
    close_database();
}