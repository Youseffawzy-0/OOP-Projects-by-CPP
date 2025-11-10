#ifndef HOURLYEMPLOYEE_H
#define HOURLYEMPLOYEE_H
#include "Employee.h"




class HourlyEmployee : public Employee {
protected:
    double hoursWorked;
    double rate;

public:
    HourlyEmployee(const string& name, const string& employeeId, const string& jobTitle,
                   double hoursWorked, double rate, const string& email, const string& phone, const string& departId);
    void setHoursWorked(double hours);
    void setRate(double r);
    double getHoursWorked() const;
    double getRate() const;
    void addHours(double hours);
    double getSalary() const override;
    void display() const override;
    void displayDetailed() const override;
};



#endif //HOURLYEMPLOYEE_H
