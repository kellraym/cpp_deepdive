#ifndef BANK_H
#define BANk_H

#include <iostream>
#include <string>
#include<map>
#include "Account.h"

class Bank
{
    private:
        int account_count = 0;
        std::map<std::string, Account> accounts;
        void list_options();
        void handle_choice(int user_select);
        void add_account();
        void remove_account();
        void add_account_file(Account&);
        void load_accounts();
        void check_account();
        void show_all_accounts();
        void modify_balance(int);
        void update_accounts();
        void close_account();

    public:
        void run_bank();  
};

#endif