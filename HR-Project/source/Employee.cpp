#include "Employee.h"




Employee::Employee(const string& name, const string& employeeId, const string& jobTitle,
                   double salary, const string& email, const string& phone, const string& departId) {
    setName(name);
    setEmployeeId(employeeId);
    setJobTitle(jobTitle);
    setSalary(salary);
    setEmail(email);
    setPhone(phone);
    setDepartId(departId);
}

void Employee::setEmployeeId(const string& id) {
    employeeId = id;
}

void Employee::setName(const string& name) {
    this->name = name;
}

void Employee::setJobTitle(const string& title) {
    jobTitle = title;
}

void Employee::setEmail(const string& email) {
    this->email = email;
}

void Employee::setPhone(const string& phone) {
    this->phone = phone;
}

void Employee::setSalary(double s) {
    salary = s;
}

void Employee::setDepartId(const string& id) {
    departId = id;
}

string Employee::getEmployeeId() const {
    return employeeId;
}

string Employee::getName() const {
    return name;
}

string Employee::getJobTitle() const {
    return jobTitle;
}

string Employee::getEmail() const {
    return email;
}

string Employee::getPhone() const {
    return phone;
}

double Employee::getSalary() const {
    return salary;
}

string Employee::getDepartId() const {
    return departId;
}

void Employee::print(ostream& os) const {
    os << "ID: " << employeeId << ", Name: " << name << ", Job Title: " << jobTitle << ", Department ID: " << departId;
}

void Employee::display() const {
    cout << *this << endl;
}

void Employee::displayDetailed() const {
    cout << *this << ", Email: " << email << ", Phone: " << phone << ", Salary: $" << getSalary() << endl;
}

ostream& operator<<(ostream& os, const Employee& emp) {
    emp.print(os);
    return os;
}


