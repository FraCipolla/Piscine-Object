#pragma once

#include <iostream>
#include "Employee.hpp"

class HourlyEmployee : public Employee {
    public:
        class TempWorker : public Employee {
            private:
                double _workedHours;
            public:
                TempWorker(double salary) : Employee(salary), _workedHours(0) {
                    std::cout << "TempWorker constructor called" << std::endl;
                };
                ~TempWorker() { std::cout << "TempWorker destructor called" << std::endl; };
                
                void work(double hours) {
                    _workedHours += hours;
                };
                void work(double hours, int days) {
                    _workedHours += hours * days;
                };

                int executeWorkday() {
                    return _workedHours * this->getHourlyValue();
                };
        };
};