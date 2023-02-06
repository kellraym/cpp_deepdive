#include <iostream>
#include <fstream>
#include <string>
#include<map>
#include <vector>
#include "Bank.h"
#include "Account.h"

#define FILE_NAME "../files/accounts.txt"

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
            return;
        case 2:
            check_account();
            return;
        case 3:
            std::cout << "\nDepositing funds\n";
            modify_balance(1);
            return;
        case 4:
            std::cout << "\nWithdrawing funds\n";
            modify_balance(-1);
            return;
        case 5:
            close_account();
            return;
        case 6:
            show_all_accounts();
            return;
        default:
            std::cout << "Please enter a choice from 1-7";
            return;
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

    while (balance < 0.0)
    {
        std::cout << "Enter starting balance: ";
        std::cin >> balance;

        if (balance < 0.0)
        {
            std::cout << "Balance cannot be negative\n";
        }
    }
    accounts[first_name + last_name] = Account(first_name, last_name, balance);
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
    std::ofstream ostream(FILE_NAME, std::ios::app);
    if (!ostream)
    {
        std::cout << "cannot acquire file";
        throw -1;
    }

    ostream << "Account " << ++account_count << "\n";
    ostream << a;
    ostream << "\n";
    ostream.close();
}

void Bank::load_accounts()
{
    std::ifstream istream;
    std::vector<std::vector<std::string>> account_vals = {
        {}, // first names 
        {}, // last names
        {}  // balances
    };

    istream.open(FILE_NAME);
    if (!istream)
    {
        std::ofstream ostream(FILE_NAME);
        ostream.close();
        return;
    }

    bool next_is_val = false;
    std::string current_val = "";
    unsigned trinary_counter = 0; // so it never counts over to negative numbers
    while (!istream.eof())
    {
        istream >> current_val;
        
        if (next_is_val)
        {
            account_vals[trinary_counter++ % 3].push_back(current_val);
            next_is_val = false;
        }

        if ((int) current_val.find(":") != -1) next_is_val = true;

    }

    for (size_t i = 0; i < account_vals[0].size(); i++)
    {
        std::string first_name = account_vals[0][i];
        std::string last_name = account_vals[1][i];
        float balance = std::stof(account_vals[2][i]);
        accounts[first_name + last_name] = Account(first_name, last_name, balance);
        account_count++;
    }
}

void Bank::check_account()
{
    std::string first_name;
    std::string last_name;
    std::string full_name;
    std::cout << "Enter first name: ";
    std::cin >> first_name;
    std::cout << "Enter last name: ";
    std::cin >> last_name;
    full_name = first_name + last_name;

    if (accounts.find(full_name) == accounts.end())
    {
        std::cout << "\n***ACCOUNT NOT FOUND***\n\n";
        return;
    }

    std::cout << "\nAccount information:\n";
    

    std::cout << accounts.at(full_name);
    std::cout << "\n";
}

void Bank::show_all_accounts()
{
    std::map<std::string, Account>::iterator itr;
    for (itr = accounts.begin(); itr != accounts.end(); itr++) 
    {
        std::cout << "\n";
        std::cout << itr->second;
    }
    std::cout << "\n";
}

void Bank::modify_balance(int amount_sign)
{
    std::string first_name;
    std::string last_name;
    float amount;

    std::cout << "Enter first name: ";
    std::cin >> first_name;
    std::cout << "Enger last name: ";
    std::cin >> last_name;
    std::cout << "Enter amount: ";
    std::cin >> amount;

    if (amount_sign > -1)
    {
        accounts[first_name + last_name].deposit(amount);
    }
    else
    {
        accounts[first_name + last_name].withdraw(amount);
    }

    update_accounts();
}

void Bank::update_accounts()
{
    std::map<std::string, Account>::iterator itr;
    std::ofstream output(FILE_NAME);

    if (!output)
    {
        std::cout << "cannot acquire file";
        throw -1;
    }

    account_count = 0;
    for (itr = accounts.begin(); itr != accounts.end(); itr++)
    {
        output << "Account " << ++account_count << "\n";
        output << itr->second;
        output << "\n";
    }
    output.close();
}

void Bank::close_account()
{
    std::string first_name;
    std::string last_name;
    std::string choice;
    std::cout << "Closing account\n";
    std::cout << "Enter first name: ";
    std::cin >> first_name;
    std::cout << "Enger last name: ";
    std::cin >> last_name;

    std::cout << "Are you sure you would like to close this account? enter y/n: ";
    std::cin >> choice;
    if (choice != "y" && choice != "Y")
    {
        std::cout << "\nCancelling account closure\n";
        return;
    }

    accounts.erase(first_name + last_name);
    update_accounts();
}

void Bank::run_bank()
{
    try
    {
        load_accounts();
    }
    catch(int e)
    {
        std::cout << "Error loading accounts";
    }

    while(true)
    {
        int user_select = -1;
        list_options();
        std::cout << "Enter your choice: ";
        std::cin >> user_select;
        if (user_select == 7) break;
        handle_choice(user_select);
    }
}