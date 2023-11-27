#pragma once

#include <iostream>

class Employee
{
private:
    int _hourly_value;
public:
    Employee() : _hourly_value(0) {};
    Employee(int hourly_value) : _hourly_value(hourly_value) {};
    ~Employee();

    int executeWorkday() {
        return _hourly_value * 7;
    }
};

