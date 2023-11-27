#pragma once

#include <iostream>
#include "Tool.hpp"

class Shovel : public Tool{
	int numberOfUses;

	public:
	Shovel() : numberOfUses(0) {};
	Shovel(int n) : numberOfUses(n) {};	
	~Shovel() { std::cout << "Shovel destructor" << std::endl; }

	void use() {
		if (numberOfUses <= 0)
			std::cout << "Shovel is broken" << std::endl;
		else if (numberOfUses > 0) {
			std::cout << "Shovel used" << std::endl;
			numberOfUses--;
		}
	}

};
