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

    public:
        void run_bank();  
};

#endif