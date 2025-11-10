#include "HourlyEmployee.h"



HourlyEmployee::HourlyEmployee(const string& name, const string& employeeId, const string& jobTitle,
                               double hoursWorked, double rate, const string& email, const string& phone, const string& departId)
    : Employee(name, employeeId, jobTitle, 0.0, email, phone, departId), hoursWorked(hoursWorked), rate(rate) {}

void HourlyEmployee::setHoursWorked(double hours) {
    hoursWorked = hours;
}

double HourlyEmployee::getHoursWorked() const {
    return hoursWorked;
}

void HourlyEmployee::setRate(double r) {
    rate = r;
}

double HourlyEmployee::getRate() const {
    return rate;
}

void HourlyEmployee::addHours(double hours) {
    hoursWorked += hours;
}

double HourlyEmployee::getSalary() const {
    return hoursWorked * rate;
}

void HourlyEmployee::display() const {
    cout << "Hourly Employee: ";
    Employee::display();
}

void HourlyEmployee::displayDetailed() const {
    cout << "Hourly Employee: ";
    Employee::displayDetailed();
    cout << "Hours Worked: " << hoursWorked << ", Rate: $" << rate << endl;
}