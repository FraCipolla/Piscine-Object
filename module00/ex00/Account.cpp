#include "Account.hpp"
#include "Bank.hpp"

int Account::_counter = 0;

Account::Account() : _id(_counter++), _value(0), _loan(0) {}
Account::Account(double amount) : _id(_counter++), _value(amount), _loan(0) {}
Account::Account(const Account &acc): _id(_counter++) {
    this->_value = acc.getValue();
    this->_loan = acc.getLoan();
    }
Account::~Account() {}

Account * Account::operator=(Account &acc) {
    delete(this);
    *this = acc;
    return this;
}

Account * Account::operator ->() { return this; }

bool Account::operator==(Account &lhs) {
    return (this->_id == lhs._id && this->_value == lhs._value);
    }
bool Account::operator==(Account *lhs) {
    return (this->_id == lhs->_id && this->_value == lhs->_value);
    }
int Account::getId() const { return this->_id; }
double Account::getValue() const { return this->_value; }
double Account::getLoan() const { return this->_loan; }
double Account::getValue() { return this->_value; }
double Account::getLoan() { return this->_loan; }

std::ostream& operator << (std::ostream& p_os, const Account& p_account)
{
    p_os << "[" << p_account.getId() << "] - [" << p_account.getValue() << "]";
    return (p_os);
}