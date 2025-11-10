#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "Department.h"
#include<bits/stdc++.h>
using namespace std;


class Employee {
protected:
    string employeeId;
    string name;
    string jobTitle;
    string email;
    string phone;
    double salary;
    string departId;

public:
    Employee(const string& name, const string& employeeId, const string& jobTitle,
            double salary, const string& email, const string& phone, const string& departId);
    virtual ~Employee() = default;
    void setEmployeeId(const string& id);
    void setName(const string& name);
    void setJobTitle(const string& title);
    void setEmail(const string& email);
    void setPhone(const string& phone);
    virtual void setSalary(double s);
    void setDepartId(const string& id);
    string getEmployeeId() const;
    string getName() const;
    string getJobTitle() const;
    string getEmail() const;
    string getPhone() const;
    virtual double getSalary() const;
    string getDepartId() const;
    virtual void print(ostream& os) const;
    virtual void display() const;
    virtual void displayDetailed() const;
};

ostream& operator<<(ostream& os, const Employee& emp);






#endif //EMPLOYEE_H
