#pragma once

#include <iostream>
#include <vector>
#include "Tool.hpp"

typedef struct Position {
	int x;
	int y;
	int z;
	
	Position() : x(0), y(0), z(0) {};
	Position(int x, int y, int z) : x(x), y(y), z(z) {};
};

typedef struct Statistic {
	int level;
	int exp;

	Statistic() : level(0), exp(0) {};
	Statistic(int lv, int ex) : level(lv), exp(ex) {};
};

class Worker {
	private:
		Position coordonnee;
		Statistic stat;
		std::vector<Tool *> tools;

	public:
		Worker() {};
		Worker(Position pos, Statistic stat) : coordonnee(pos), stat(stat) {};
		~Worker() { std::cout << "Worker destructor" << std::endl; }
	
		// void addShovel(Shovel &shovel) { this->shovel = shovel; }
		void addTool(Tool &tool) { this->tools.push_back(&tool); }
		void work() {
			std::cout << "It's time to work !" << std::endl;
		}
};
