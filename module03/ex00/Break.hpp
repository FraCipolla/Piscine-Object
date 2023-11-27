#pragma once

#include <iostream>

class Break {
    private:
        int _force;
    public:
        Break(): _force(0) { std::cout << "Break default constructor" << std::endl; }
        Break(int force) : _force(force) { std::cout << "Break(int force)" << std::endl; }
        Break(const Break &other) : _force(other._force) { std::cout << "Break(const Break &other)" << std::endl; }

        virtual ~Break() { std::cout << "Break destructor" << std::endl; }

        int getForce() const { return this->_force; }
        
        void apply_force_on_brakes(int force) {
            std::cout << "apply_force_on_brakes(int force)" << std::endl;
            if (force > 100)
                force = 100;
            else if (force < 0)
                force = 0;
            if (this->_force + force > 100)
                this->_force = 100;
            else if (this->_force + force < 0)
                this->_force = 0;
            else
                this->_force += force;
            std::cout << "Current force: " << this->_force << std::endl;
        }
        void apply_emergency_brakes() {
            std::cout << "apply_emergency_brakes()" << std::endl;
            this->_force = 100;
        }
};