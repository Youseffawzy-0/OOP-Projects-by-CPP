#include "SalaryEmployee.h"



SalaryEmployee::SalaryEmployee(const string& name, const string& employeeId, const string& jobTitle,
                               double salary, const string& email, const string& phone, const string& departId)
    : Employee(name, employeeId, jobTitle, salary, email, phone, departId) {}

void SalaryEmployee::setSalary(double s) {
    Employee::setSalary(s);
}

double SalaryEmployee::getSalary() const {
    return Employee::getSalary();
}

void SalaryEmployee::display() const {
    cout << "Salaried Employee: ";
    Employee::display();
}

void SalaryEmployee::displayDetailed() const {
    cout << "Salaried Employee: ";
    Employee::displayDetailed();
}