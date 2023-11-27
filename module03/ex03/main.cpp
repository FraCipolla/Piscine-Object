#include "EmployeeManagement.hpp"
#include "SalariedEmployee.hpp"
#include "HourlyEmployee.hpp"

int main () {
    EmployeeManager manager;

    SalariedEmployee::ContractEmployee *contractEmployee = new SalariedEmployee::ContractEmployee(1000.0);
    SalariedEmployee::Apprentice *apprentice = new SalariedEmployee::Apprentice(1000.0);
    HourlyEmployee::TempWorker *tempWorker = new HourlyEmployee::TempWorker(1000.0);

    manager.addEmployee(contractEmployee);
    manager.addEmployee(apprentice);
    manager.addEmployee(tempWorker);

    manager.executeWorkday();
    

    return 0;
}