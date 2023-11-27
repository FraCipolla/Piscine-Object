#pragma once

#include <iostream>
#include "Employee.hpp"

class SalariedEmployee : public Employee {
    public:
        class ContractEmployee : public Employee {
            private:
                double _unworkedHours;
            public:
                ContractEmployee(double salary) : Employee(salary), _unworkedHours(0) {
                    std::cout << "ContractEmployee constructor called" << std::endl;
                };
                ~ContractEmployee() {
                    std::cout << "ContractEmployee destructor called" << std::endl;
                };

            void vacation(double hours) {
                _unworkedHours += hours;
            };
            void sickness(double hours) {
                _unworkedHours += hours;
            };
            void anyReason(double hours) {
                _unworkedHours += hours;
            };
        };
        
        class Apprentice : public ContractEmployee {
            private:
                double _schoolHours;
            public:
                Apprentice(double salary) : ContractEmployee(salary), _schoolHours(0) {
                    std::cout << "Apprentice constructor called" << std::endl;
                };
                ~Apprentice() { std::cout << "Apprentice destructor called" << std::endl; };
            void school(double hours) {
                _schoolHours += hours;
            };
        };
};