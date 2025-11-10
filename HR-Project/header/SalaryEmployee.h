#ifndef SALARYEMPLOYEE_H
#define SALARYEMPLOYEE_H
#include "Employee.h"




class SalaryEmployee : public Employee {
public:
    SalaryEmployee(const string& name, const string& employeeId, const string& jobTitle,
                   double salary, const string& email, const string& phone, const string& departId);
    void setSalary(double s) override;
    double getSalary() const override;
    void display() const override;
    void displayDetailed() const override;
};


#endif //SALARYEMPLOYEE_H
