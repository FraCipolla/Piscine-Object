#pragma once

#include <iostream>

class Wheel {
    private:
        int _angle;
    public:
        Wheel() { std::cout << "Wheel default constructor" << std::endl; }
        Wheel(int angle) : _angle(angle) { std::cout << "Wheel(int angle)" << std::endl; }
        Wheel(const Wheel &other) : _angle(other._angle) { std::cout << "Wheel(const Wheel &other)" << std::endl; }
        virtual ~Wheel() { std::cout << "Wheel destructor" << std::endl; };

        int getAngle() const { return this->_angle; }
        
        void turn_wheel(int angle) {
            std::cout << "turn_wheel(int angle)" << std::endl;
            if (this->_angle + angle > 360)
                this->_angle = (this->_angle + angle) % 360;
            else if (this->_angle + angle < 0)
                this->_angle = 360 + (this->_angle + angle);
            else
                this->_angle += angle;
        }

        void straighten_wheel() {
            std::cout << "straighten_wheel()" << std::endl;
            this->_angle = 0;
        }
};