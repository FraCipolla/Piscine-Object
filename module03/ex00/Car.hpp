#pragma once

#include <iostream>
#include "Gears.hpp"
#include "Wheel.hpp"
#include "Engine.hpp"
#include "Break.hpp"

class Car : public Gears, public Wheel, public Engine, public Break {
	public:
		Car() : Gears(), Wheel(), Engine(), Break() {
			std::cout << "Car default constructor" << std::endl;
		}
		Car(int gear, int angle, int speed, int force) : Gears(gear), Wheel(angle), Engine(speed), Break(force) {
			std::cout << "Car(int gear, int angle, int speed, int force)" << std::endl;
		}
		Car(const Car &other) : Gears(other), Wheel(other), Engine(other), Break(other) {
			std::cout << "Car(const Car &other)" << std::endl;
		}
		~Car() {
			std::cout << "Car destructor" << std::endl;
		}

		void print() {
			std::cout << "Gear: " << this->getGear() << std::endl;
			std::cout << "Angle: " << this->getAngle() << std::endl;
			std::cout << "Speed: " << this->getSpeed() << std::endl;
			std::cout << "Force: " << this->getForce() << std::endl;
		}
};
