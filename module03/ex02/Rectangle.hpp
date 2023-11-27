#pragma once

#include <iostream>
#include "Shape.hpp"

class Rectangle : public Shape {
    private:
        double _width;
        double _height;
    
    public:
        Rectangle() : _width(0), _height(0) { std::cout << "Rectangle default constructor" << std::endl; }
        Rectangle(double width, double height) : _width(width), _height(height) { std::cout << "Rectangle(double width, double height)" << std::endl; }
        Rectangle(const Rectangle &other) : _width(other._width), _height(other._height) { std::cout << "Rectangle(const Rectangle &other)" << std::endl; }
        Rectangle(const Rectangle &&other) : _width(other._width), _height(other._height) { std::cout << "Rectangle(const Rectangle &&other)" << std::endl; }

        ~Rectangle() { std::cout << "Rectangle destructor" << std::endl; };

        Rectangle &operator =(Rectangle &&other) {
            std::cout << "Rectangle operator=" << std::endl;
            this->_width = std::move(other._width);
            this->_height = std::move(other._height);
            return *this;
        }
        Rectangle &operator =(const Rectangle &other) {
            std::cout << "Rectangle operator=" << std::endl;
            this->_width = other._width;
            this->_height = other._height;
            return *this;
        }

        double get_area() const {
            return this->_width * this->_height;
        }

        double get_perimeter() const {
            return 2 * (this->_width + this->_height);
        }

        friend std::ostream& operator<<(std::ostream &os, const Rectangle &rectangle) {
            os << "Rectangle width: " << rectangle._width << std::endl;
            os << "Rectangle height: " << rectangle._height << std::endl;
            return os;
        }
};