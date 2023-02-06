#include <iostream>
#include <string>
#include "Account.h"

Account::Account() : Account("", "", 0) {}

Account::Account(std::string first_name, std::string last_name, float balance)
{
    this->first_name = first_name;
    this->last_name = last_name;
    set_balance(balance);
}

void Account::deposit(int bal_change)
{
    set_balance(bal_change);
}

void Account::set_balance(float x)
{
    if (balance + x >= 0)
    {
        balance += x;
    }
    else
    {
        std::cout << "Insufficient funds!\n";
    }
}

void Account::withdraw(int bal_change)
{
    set_balance(-bal_change);
}

float Account::get_balance()
{
    return balance;
}

std::ofstream &operator<<(std::ofstream &ofs, Account &a)
{
    std::string balance_string = std::to_string(a.balance);
    size_t dec_idx = balance_string.find(".");
    balance_string.erase(balance_string.begin() + dec_idx + 3, balance_string.end());
    
    ofs << "First Name: " + a.first_name + "\n";
    ofs << "Last Name: " + a.last_name + "\n";
    ofs << "Balance: " + balance_string + "\n";
    return ofs;
}

std::ostream &operator<<(std::ostream &os, Account &a)
{
    std::string balance_string = std::to_string(a.balance);
    size_t dec_idx = balance_string.find(".");
    balance_string.erase(balance_string.begin() + dec_idx + 3, balance_string.end());

    os << "First Name: " + a.first_name + "\n";
    os << "Last Name: " + a.last_name + "\n";
    os << "Balance: " + balance_string + "\n";
    return os;
}