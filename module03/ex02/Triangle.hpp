#pragma once

#include "Shape.hpp"
#include <iostream>
#include <cmath>

class Triangle : public Shape {
    private:
        double _base;
        double _height;
    
    public:
        Triangle() : _base(0), _height(0) { std::cout << "Triangle default constructor" << std::endl; }
        Triangle(double base, double height) : _base(base), _height(height) { std::cout << "Triangle(double base, double height)" << std::endl; }
        Triangle(const Triangle &other) : _base(other._base), _height(other._height) { std::cout << "Triangle(const Triangle &other)" << std::endl; }
        Triangle(const Triangle &&other) : _base(other._base), _height(other._height) { std::cout << "Triangle(const Triangle &&other)" << std::endl; }

        ~Triangle() { std::cout << "Triangle destructor" << std::endl; };

        Triangle &operator =(Triangle &&other) {
            std::cout << "Triangle operator=" << std::endl;
            this->_base = std::move(other._base);
            this->_height = std::move(other._height);
            return *this;
        }
        Triangle &operator =(const Triangle &other) {
            std::cout << "Triangle operator=" << std::endl;
            this->_base = other._base;
            this->_height = other._height;
            return *this;
        }

        double get_area() const {
            return this->_base * this->_height / 2;
        }

        double get_perimeter() const {
            return this->_base + this->_height + std::sqrt(this->_base * this->_base + this->_height * this->_height);
        }

        friend std::ostream& operator<<(std::ostream &os, const Triangle &triangle) {
            os << "Triangle base: " << triangle._base << std::endl;
            os << "Triangle height: " << triangle._height << std::endl;
            return os;
        }
};