#pragma once

// #include "Account.hpp"
#include <vector>
#include <ostream>

class Bank
{
    private:
        double _liquidity;
        static int _counter;
        struct Account
        {
            int _id;
            double _value;
            double _loan;

            Account(int id) : _id(id), _value(0), _loan(0) {};
            Account &operator=(const Account &acc);
            Account(int id, const Account &acc) : _id(id), _value(acc._value), _loan(acc._loan) {};
            ~Account() {};

            // Getters
            int getId() const { return this->_id; }
            double getValue() const { return this->_value; }
            double getLoan() const { return this->_loan; }
        };
        std::vector<Account *> _clientAccounts;
        

    public:
        Bank();
        Bank(double amount);
        Bank(const Account &acc);
        
        ~Bank();

        // operators
        Account* operator[](int id);
        Account* operator[](int id) const;
        Bank& operator=(const Bank &bank);

        // getters
        double getLiquidity() const;
        double getLiquidity();
        std::vector<Account *> getClientAccounts() const;
        std::vector<Account *> getClientAccounts();

        // setters
        void setLiquidity(double amount);

        // methods
        void createAccount();
        void delAccount(Account &acc);
        void delAccount(int id);
        void addMoney(double amount, Account &acc);
        void addMoney(double amount, int id);
        void takeMoney(double amount, Account &acc);
        void takeMoney(double amount, int id);

        void withdraw(double amount);
        void deposit(double amount);
        void giveLoan(double amount, Account &acc);
        void giveLoan(double amount, int id);
        
        friend std::ostream& operator << (std::ostream& p_os, const Bank& p_bank);
        friend std::ostream& operator << (std::ostream& p_os, const Account* p_account);
};