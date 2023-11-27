#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Employee.hpp"

class EmployeeManager
{
private:
    std::vector<Employee> _employees;
public:
    EmployeeManager() {
        std::cout << "EmployeeManager constructor called" << std::endl;
    };
    ~EmployeeManager() {
        std::cout << "EmployeeManager destructor called" << std::endl;
    };

    void addEmployee(Employee *employee) {
        _employees.push_back(*employee);
    }

    void executeWorkday() {
        for (size_t i = 0; i < _employees.size(); i++) {
            std::cout << "Employee " << _employees[i].getId() << " worked " << _employees[i].executeWorkday() << " hours" << std::endl;
        }
    }
    void removeEmployee(Employee employee) {
        for (size_t i = 0; i < _employees.size(); i++) {
            if (_employees[i].getId() == employee.getId()) {
                _employees.erase(_employees.begin() + i);
            }
        }
    }

    void calculatePayroll() {
    }

};

