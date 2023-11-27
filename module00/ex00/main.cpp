#include "Bank.hpp"

#include <iostream>

int main()
{

	Bank bank = Bank();
	bank.setLiquidity(999); // bank.liquidity = 999;
	bank.addAccount({100});   // bank.clientAccounts.push_back(&accountA);
	bank.addAccount({100});   // bank.clientAccounts.push_back(&accountB);

	bank.withdraw(200);
	bank.addAccValue(400, accountA);

	std::cout << "Account : " << std::endl;
	std::cout << accountA << std::endl;
	std::cout << accountB << std::endl;

	std::cout << " ----- " << std::endl;

	std::cout << "Bank : " << std::endl;
	std::cout << bank;

	return (0);
}
