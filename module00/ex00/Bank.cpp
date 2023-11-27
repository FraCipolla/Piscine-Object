#include "Bank.hpp"
#include <iostream>

Bank::Bank() : _liquidity(0) {}
Bank::Bank(double amount) : _liquidity(amount) {}
Bank::~Bank() {
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
void Bank::setClientAccounts(std::vector<Account *> cliAcc) { this->_clientAccounts = cliAcc; }

// Methods
void Bank::addAccount(Bank::Account &acc) {
    this->_clientAccounts.push_back(&acc);
}
void Bank::delAccount(Bank::Account &acc) {
    std::vector<Bank::Account *>::iterator it = this->_clientAccounts.begin();
    for (; it != this->_clientAccounts.end(); it++) {
        if ((*it) == &acc) {
            this->_clientAccounts.erase(it);
            return ;
        }
    }
}
void Bank::addAccValue(double amount, Bank::Account &acc) {
    double inflow = (amount / 100) * 5;
    amount -= inflow;
    acc.addLiquidity(amount);
    this->_liquidity += inflow;
}
void Bank::withdraw(double amount) {
    this->_liquidity -= amount;
}

void Bank::deposit(double amount) {
    this->_liquidity += amount;
}

void Bank::giveLoan(double amount, Bank::Account &acc) {
    if (this->_liquidity >= amount) {
        this->_liquidity -= amount;
        acc.getLoan(amount); // REDO
    }
}

Bank::Account *Bank::createAccount(double amount) {
    Bank::Account *acc = new Bank::Account(amount);
    this->_clientAccounts.push_back(acc);
    return acc;
}

std::ostream& operator << (std::ostream& p_os, const Bank& p_bank)
{
	p_os << "Bank informations : " << std::endl;
	p_os << "Liquidity : " << p_bank.getLiquidity() << std::endl;
    std::vector<Bank::Account *> acc = p_bank.getClientAccounts();
    std::vector<Bank::Account *>::iterator it = acc.begin();
    for (; it != acc.end(); it++)
        p_os << "id: " << (*it)->getId() << " value: " << (*it)->getValue() << std::endl;
	return (p_os);
}