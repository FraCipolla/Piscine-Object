#pragma once

#include "Shape.hpp"
#include <iostream>

class Circle : public Shape {
    private:
        double _radius;
    
    public:
        Circle() : _radius(0) { std::cout << "Circle default constructor" << std::endl; }
        Circle(double radius) : _radius(radius) { std::cout << "Circle(double radius)" << std::endl; }
        Circle(const Circle &other) : _radius(other._radius) { std::cout << "Circle(const Circle &other)" << std::endl; }
        Circle(Circle &&other) : _radius(std::move(other._radius)) { std::cout << "Circle(const Circle &&other)" << std::endl; }

        ~Circle() { std::cout << "Circle destructor" << std::endl; };

        Circle &operator =(Circle &&other) {
            std::cout << "Circle operator=" << std::endl;
            this->_radius = std::move(other._radius);
            return *this;
        }
        Circle &operator =(const Circle &other) {
            std::cout << "Circle operator=" << std::endl;
            this->_radius = other._radius;
            return *this;
        }

        double get_area() const {
            return this->_radius * this->_radius * 3.14;
        }

        double get_perimeter() const {
            return 2 * this->_radius * 3.14;
        }

        friend std::ostream& operator<<(std::ostream &os, const Circle &circle) {
            os << "Circle radius: " << circle._radius << std::endl;
            return os;
        }
};