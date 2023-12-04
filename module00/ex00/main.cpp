#include "Bank.hpp"

#include <iostream>

int main()
{
	Bank bank(1000);

	bank.setLiquidity(1000);
	std::cout << "Liquidity: " << bank.getLiquidity() << std::endl;

	bank.createAccount();
	bank.createAccount();
	bank.createAccount();
	bank.createAccount();

	std::cout << bank << std::endl;

	bank.addMoney(100, 0);
	bank.addMoney(200, 1);
	bank.addMoney(300, 2);
	bank.addMoney(400, 3);

	std::cout << bank << std::endl;

	bank.takeMoney(10, 0);
	bank.takeMoney(20, 1);
	bank.takeMoney(30, 2);
	bank.takeMoney(40, 3);

	std::cout << bank << std::endl;

	bank.giveLoan(100, 0);
	bank.giveLoan(200, 1);
	bank.giveLoan(300, 2);
	bank.giveLoan(400, 3);

	std::cout << bank << std::endl;

	std::cout << "Testing exceptions:" << std::endl;

	bank.takeMoney(100000, 0);
	
	bank.delAccount(100);

	bank.giveLoan(100000, 0);

	bank.withdraw(100000);

	std::cout << "deleting accounts:" << std::endl;
	bank.delAccount(0);
	bank.delAccount(1);
	bank.delAccount(2);
	bank.delAccount(3);

	std::cout << bank << std::endl;

	return (0);
}
