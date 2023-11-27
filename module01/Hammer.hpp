#pragma once

#include <iostream>
#include "Tool.hpp"

class Hammer : public Tool{
	int numberOfUses;

	public:
	Hammer() : numberOfUses(0) {};
	Hammer(int n) : numberOfUses(n) {};	
	~Hammer() { std::cout << "Hammer destructor" << std::endl; }

	void use() {
		if (numberOfUses <= 0)
			std::cout << "Hammer is broken" << std::endl;
		else if (numberOfUses > 0) {
			std::cout << "Hammer used" << std::endl;
			numberOfUses--;
		}
	}

};
