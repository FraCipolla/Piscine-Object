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
    EmployeeManager(/* args */);
    ~EmployeeManager();

    void addEmployee(Employee *employee) {
    }

    void removeEmployee(Employee employee) {
    }

    void calculatePayroll() {
        
    }
};

