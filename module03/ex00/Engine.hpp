#pragma once

#include <iostream>

class Engine {
    private:
        int _speed;

    public:
        Engine() { std::cout << "Engine default constructor" << std::endl; }
        Engine(int speed) : _speed(speed) { std::cout << "Engine(int speed)" << std::endl; }
        Engine(const Engine &other) : _speed(other._speed) { std::cout << "Engine(const Engine &other)" << std::endl; }
        virtual ~Engine() { std::cout << "Engine destructor" << std::endl; };

        int getSpeed() const { return this->_speed; }
        
        void start() { std::cout << "start()" << std::endl; }
        void stop() { std::cout << "stop()" << std::endl; }
        void accelerate(int speed) {
            std::cout << "accelerate(int speed)" << std::endl;
            this->_speed += speed;
        }
};