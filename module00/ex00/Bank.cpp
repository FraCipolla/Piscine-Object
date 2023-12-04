#include "Bank.hpp"
#include <iostream>
#include <string>

int Bank::_counter = 0;

Bank::Bank() : _liquidity(0) {}
Bank::Bank(double amount) : _liquidity(amount) {}
Bank::Bank(const Bank::Account &acc) {
    this->_clientAccounts.push_back(new Bank::Account(this->_counter++, acc));  
}
Bank::~Bank() {
    for (size_t i = 0; i < this->_clientAccounts.size(); i++) {
        delete this->_clientAccounts[i];
    }
    this->_clientAccounts.clear();
}

// Getters
double Bank::getLiquidity() const { return this->_liquidity; }
double Bank::getLiquidity() { return this->_liquidity; }
std::vector<Bank::Account *> Bank::getClientAccounts() const {
    return this->_clientAccounts;
}
std::vector<Bank::Account *> Bank::getClientAccounts() {
    return this->_clientAccounts;
}

// Setters
void Bank::setLiquidity(double amount) { this->_liquidity = amount; }

// Methods
void Bank::addMoney(double amount, Bank::Account &acc) {
    try {
        this->_clientAccounts[acc.getId()]->_value += amount;
        double inflow = (amount / 100) * 5;
        amount -= inflow;
        this->_liquidity += inflow;
    } catch (std::string e) {
        std::cout << e << std::endl;
    }
}

void Bank::addMoney(double amount, int id) {
    try {
        this->_clientAccounts[id]->_value += amount;
        double inflow = (amount / 100) * 5;
        amount -= inflow;
        this->_liquidity += inflow;
    } catch (std::string e) {
        std::cout << e << std::endl;
    }
}

void Bank::withdraw(double amount) {
    try {
        if (this->_liquidity < amount)
            throw std::string("Not enough liquidity");
        this->_liquidity -= amount;
    } catch (std::string e) {
        std::cout << e << std::endl;
    }
}

void Bank::deposit(double amount) {
    this->_liquidity += amount;
}

void Bank::giveLoan(double amount, Bank::Account &acc) {
    try {
        if (this->_liquidity >= amount) {
            this->_liquidity -= amount;
            this->_clientAccounts[acc.getId()]->_loan += amount;
        } else {
            throw std::string("Not enough liquidity");
        }
    } catch (std::string e) {
        std::cout << e << std::endl;
    }
}

void Bank::giveLoan(double amount, int id) {
    try {
        if (this->_liquidity >= amount) {
            this->_liquidity -= amount;
            this->_clientAccounts[id]->_loan += amount;
        } else {
            throw std::string("Not enough liquidity");
        }
    } catch (std::string e) {
        std::cout << e << std::endl;
    }
}

void Bank::createAccount() {
    Bank::Account *acc = new Bank::Account(this->_counter++);
    this->_clientAccounts.push_back(acc);
}

void Bank::delAccount(Bank::Account &acc) {
    Bank::Account *account = Bank::operator[](acc.getId());
    if (account == NULL) {
        return ;
    }
    this->_clientAccounts.erase(this->_clientAccounts.begin() + acc.getId());
    for (size_t i = acc.getId(); i < this->_clientAccounts.size(); i++) {
        this->_clientAccounts[i]->_id--;
    }
    Bank::_counter--;
}

void Bank::delAccount(int id) {
    Bank::Account *acc = Bank::operator[](id);
    if (acc == NULL) {
        return ;
    }
    delete acc;
    this->_clientAccounts.erase(this->_clientAccounts.begin() + id);
    for (size_t i = id; i < this->_clientAccounts.size(); i++) {
        this->_clientAccounts[i]->_id--;
    }
    Bank::_counter--;
}

void Bank::takeMoney(double amount, Bank::Account &acc) {
    try {
        Bank::Account *account = this->_clientAccounts[acc.getId()];
        if (account->_value >= amount) {
            account->_value -= amount;
            this->_liquidity += amount;
        } else {
            throw std::string("Not enough money");
        }
    } catch (std::string e) {
        std::cout << e << std::endl;
    }
}

void Bank::takeMoney(double amount, int id) {
    try {
        Bank::Account *account = this->_clientAccounts[id];
        if (account->_value >= amount) {
            account->_value -= amount;
            this->_liquidity += amount;
        } else {
            throw std::string("Not enough money");
        }
    } catch (std::string e) {
        std::cout << e << std::endl;
    }
}

Bank::Account* Bank::operator[](int id) {
    try {
        if ((size_t)id >= this->_clientAccounts.size())
            throw std::string("Account not found");
        return this->_clientAccounts[id];
    } catch (std::string e) {
        std::cout << e << std::endl;
    }
    return NULL;
}

Bank::Account* Bank::operator[](int id) const {
    try {
        if ((size_t)id > this->_clientAccounts.size())
            throw std::string("Account not found");
        return this->_clientAccounts[id];
    } catch (std::string e) {
        std::cout << e << std::endl;
    }
    return NULL;
}

std::ostream& operator << (std::ostream& p_os, const Bank& p_bank)
{
	p_os << "Bank informations : " << std::endl;
	p_os << "Liquidity : " << p_bank.getLiquidity() << std::endl;
    std::vector<Bank::Account *> acc = p_bank.getClientAccounts();
    std::vector<Bank::Account *>::iterator it = acc.begin();
    for (; it != acc.end(); it++) {
        p_os << *it << std::endl;
    }
	return (p_os);
}

std::ostream& operator << (std::ostream& p_os, const Bank::Account* p_account)
{
    p_os << "Account Id : " << p_account->getId() << std::endl;
    p_os << "Value : " << p_account->getValue() << std::endl;
    p_os << "Loan : " << p_account->getLoan() << std::endl;
    return (p_os);
}