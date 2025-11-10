#include "CommissionEmployee.h"




CommissionEmployee::CommissionEmployee(const string& name, const string& employeeId, const string& jobTitle,
                                       double target, double rate, const string& email, const string& phone, const string& departId)
    : Employee(name, employeeId, jobTitle, 0.0, email, phone, departId), target(target), rate(rate) {}

double CommissionEmployee::getTarget() const {
    return target;
}

void CommissionEmployee::setTarget(double t) {
    target = t;
}

double CommissionEmployee::getRate() const {
    return rate;
}

void CommissionEmployee::setRate(double r) {
    rate = r;
}

double CommissionEmployee::getSalary() const {
    return rate * target;
}

void CommissionEmployee::display() const {
    cout << "Commission Employee: ";
    Employee::display();
}

void CommissionEmployee::displayDetailed() const {
    cout << "Commission Employee: ";
    Employee::displayDetailed();
    cout << "Target: $" << target << ", Commission Rate: " << rate << endl;
}