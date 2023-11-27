#pragma once

#include <iostream>

class Gears {
    private:
        int _curr_gear;
    public:
        Gears() : _curr_gear(0) { std::cout << "Gears default constructor" << std::endl; }
        Gears(int gear) : _curr_gear(gear) { std::cout << "Gears(int gear)" << std::endl; }
        Gears(const Gears &other) : _curr_gear(other._curr_gear) { std::cout << "Gears(const Gears &other)" << std::endl; }
        virtual ~Gears() { std::cout << "Gears destructor" << std::endl; }

        int getGear() const { return this->_curr_gear; }

        void shift_up() {
            if (this->_curr_gear == 5) {
                std::cout << "Already in top gear" << std::endl;
                return;
            }
            std::cout << "shift_up: current gear " << this->_curr_gear <<  std::endl;
            this->_curr_gear++;
            
        };
        void shift_down() {
            if (this->_curr_gear == 0) {
                std::cout << "Already in first gear" << std::endl;
                return;
            }
            std::cout << "shift_down: current gear " << this->_curr_gear <<  std::endl;
            this->_curr_gear--;
        };
        void reverse() {
            if (this->_curr_gear == -1) {
                std::cout << "Already in reverse gear" << std::endl;
                return;
            }
            this->_curr_gear = -1;
            std::cout << "reverse: current gear " << this->_curr_gear <<  std::endl;
        };
};