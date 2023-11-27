#pragma once

#include <iostream>

class Employee
{
private:
    int _id;
    static int id_counter;
    int _hourly_value;
public:
    Employee() : _hourly_value(0), _id(id_counter++) {};
    Employee(int hourly_value) : _hourly_value(hourly_value), _id(id_counter++) {};
    ~Employee() {
        std::cout << "Employee destructor called" << std::endl;
    };

    int executeWorkday() {
        return _hourly_value * 7;
    }

    // Getters
    int getHourlyValue() const { return _hourly_value; };
    int getId() const { return _id; };
};

int Employee::id_counter = 0;