#include "ManagerEmployee.h"





ManagerEmployee::ManagerEmployee(const string& name, const string& employeeId, const string& jobTitle,
                                 double salary, const string& email, const string& phone, const string& departId, double bonus)
    : SalaryEmployee(name, employeeId, jobTitle, salary, email, phone, departId), bonus(bonus) {}

void ManagerEmployee::addBonus(double moreBonus) {
    bonus += moreBonus;
}

double ManagerEmployee::getSalary() const {
    return Employee::getSalary() + bonus;
}

void ManagerEmployee::display() const {
    cout << "Manager Employee: ";
    Employee::display();
}

void ManagerEmployee::displayDetailed() const {
    cout << "Manager Employee: ";
    Employee::displayDetailed();
    cout << "Bonus: $" << bonus << endl;
}