#pragma once

#include <ostream>
#include <iostream>

class Account
{
    private:
        const int _id;
        static int _counter;
        double _value;
        double _loan;
        friend class Bank;

        void addLiquidity(double amount) {
            this->_value += amount;
        }

        void getLoan(double amount) {
            this->_loan += amount;
        }

    public:
        Account();
        Account(double amount);
        Account(const Account &acc);
        ~Account();

        Account * operator=(Account &acc);
        Account * operator ->();

        bool operator==(Account &lhs);
        bool operator==(Account *lhs);

        // Getters
        int getId() const;
        double getValue() const;
        double getLoan() const;
        double getValue();
        double getLoan();

        friend std::ostream& operator << (std::ostream& p_os, const Account& p_account);
};