#include <iostream>
#include <fstream>
#include <string>
#include<map>
#include "Bank.h"
#include "Account.h"

// Bank::Bank() : Bank(1) {}

// Bank::Bank(int account_count)
// {
//     account_count = 0;
// }

void Bank::list_options()
{
    std::cout << "Select one option below:\n";
    std::cout << "\t1. Open an account\n";
    std::cout << "\t2. Balance Enquiry\n";
    std::cout << "\t3. Deposit\n";
    std::cout << "\t4. Withdrawal\n";
    std::cout << "\t5. Close an account\n";
    std::cout << "\t6. Show all accounts\n";
    std::cout << "\t7. Quit\n";
}

void Bank::handle_choice(int user_select)
{
    switch(user_select)
    {
        case 1:
            add_account();
            break;
        default:
            break;
    }
}

void Bank::add_account()
{
    std::string first_name;
    std::string last_name;
    float balance = -1.0f;
    std::cout << "First name: ";
    std::cin >> first_name;
    std::cout << "Last name: ";
    std::cin >> last_name;

    while(balance < 0.0)
    {
        std::cout << "Enter starting balance: ";
        std::cin >> balance;

        if (balance < 0.0)
        {
            std::cout << "Balance cannot be negative\n";
        }
    }

    accounts[first_name + last_name] = Account(first_name, last_name, balance);
    // TODO: write account to file
    try
    {
        add_account_file(accounts[first_name + last_name]);
    }
    catch(int e)
    {
        std::cout << "\nFailed to add account :(\n";
        return;
    }
    
    std::cout << "Congratulations! account has been created!\n\n";
}

void Bank::add_account_file(Account &a)
{
    std::ofstream ostream("../files/accounts.txt", std::ios::app);
    if (!ostream)
    {
        std::cout << "not acquired";
        throw -1;
    }
    ostream << "\n";
    ostream << "Account " << ++account_count << "\n";
    ostream << a;
    ostream.close();
}

void Bank::run_bank()
{
    // TODO: load in accounts from file, track account count
    int user_select = -1;
    while(user_select != 7)
    {
        list_options();
        std::cout << "Enter your choice: ";
        std::cin >> user_select;
        handle_choice(user_select);
    }
}