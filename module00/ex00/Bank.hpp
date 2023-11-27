#pragma once

// #include "Account.hpp"
#include <vector>

class Bank
{
    private:
        double _liquidity;
        static int _ids;
        struct Account
        {
            const int _id;
            static int _counter;
            double _value;
            double _loan;

            Account();
            Account(double amount);
            Account(const Account &acc);
            ~Account();

            // Getters
            int getId() const;
            double getValue() const;
            double getLoan() const;
        };
        std::vector<Account *> _clientAccounts;
        

    public:
        Bank();
        Bank(double amount);

        ~Bank();
        Account * operator[](int id) {
            return this->_clientAccounts[id];
        }
        // getters
        double getLiquidity() const;
        double getLiquidity();
        std::vector<Account *> getClientAccounts() const;
        std::vector<Account *> getClientAccounts();

        // setters
        void setLiquidity(double amount);
        void setClientAccounts(std::vector<Account *> cliAcc);

        // methods
        Account *createAccount(double amount);
        void addAccount(Account &acc);
        void delAccount(Account &acc);
        void addAccValue(double amount, Account &acc);

        void withdraw(double amount);

        void deposit(double amount);

        void giveLoan(double amount, Account &acc);
        
        friend std::ostream& operator << (std::ostream& p_os, const Bank& p_bank);
};