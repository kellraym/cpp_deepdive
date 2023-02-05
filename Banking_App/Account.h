#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <fstream>

class Account
{
    private:
        std::string first_name;
        std::string last_name;
        float balance;

        void set_balance(float);

    public:
        Account();
        Account(std::string, std::string, int);
        void deposit(int);
        void withdraw(int);
        float get_balance();
        friend std::ofstream &operator<<(std::ofstream &ofs, Account &a);
};

#endif