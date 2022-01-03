cmake_minimum_required(VERSION 3.0.0)
project(Database_testing VERSION 0.1.0)

include(CTest)
enable_testing()

add_library(Database_testing database.c)
add_executable(insert_account_testcase1 insert_account_testcase1.c database.c)
add_test(Tester1 insert_account_testcase1)

add_executable(insert_account_testcase2 insert_account_testcase2.c database.c)
add_test(Tester2 insert_account_testcase2)

add_executable(insert_account_testcase3 insert_account_testcase3.c database.c)
add_test(Tester3 insert_account_testcase3)

add_executable(get_account_index_testcase1 get_account_index_testcase1.c database.c)
add_test(Tester4 get_account_index_testcase1)

add_executable(get_account_index_testcase2 get_account_index_testcase2.c database.c)
add_test(Tester5 get_account_index_testcase2)

add_executable(get_account_index_testcase3 get_account_index_testcase3.c database.c)
add_test(Tester6 get_account_index_testcase3)

add_executable(lock_account_testcase1 lock_account_testcase1.c database.c)
add_test(Tester7 lock_account_testcase1)

add_executable(lock_account_testcase2 lock_account_testcase2.c database.c)
add_test(Tester8 lock_account_testcase2)

add_executable(lock_account_testcase3 lock_account_testcase3.c database.c)
add_test(Tester9 lock_account_testcase3)

add_executable(lock_account_testcase4 lock_account_testcase4.c database.c)
add_test(Tester10 lock_account_testcase4)

add_executable(transaction_testcase1 transaction_testcase1.c database.c)
add_test(Tester11 transaction_testcase1)

add_executable(transaction_testcase2 transaction_testcase2.c database.c)
add_test(Tester12 transaction_testcase2)

add_executable(transaction_testcase3 transaction_testcase3.c database.c)
add_test(Tester13 transaction_testcase3)

add_executable(check_password_testcase1 check_password_testcase1.c database.c)
add_test(Tester14 check_password_testcase1)

add_executable(check_password_testcase2 check_password_testcase2.c database.c)
add_test(Tester15 check_password_testcase2)

add_executable(check_password_testcase3 check_password_testcase3.c database.c)
add_test(Tester16 check_password_testcase3)

add_executable(check_password_testcase4 check_password_testcase4.c database.c)
add_test(Tester17 check_password_testcase4)

add_executable(check_password_testcase5 check_password_testcase5.c database.c)
add_test(Tester18 check_password_testcase5)

add_executable(delete_user_testcase1 delete_user_testcase1.c database.c)
add_test(Tester19 delete_user_testcase1)

add_executable(delete_user_testcase2 delete_user_testcase2.c database.c)
add_test(Tester20 delete_user_testcase2)

add_executable(delete_user_testcase3 delete_user_testcase3.c database.c)
add_test(Tester21 delete_user_testcase3)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
