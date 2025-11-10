#ifndef COMMISSIONEMPLOYEE_H
#define COMMISSIONEMPLOYEE_H
#include "Employee.h"






class CommissionEmployee : public Employee {
protected:
    double target;
    double rate;

public:
    CommissionEmployee(const string& name, const string& employeeId, const string& jobTitle,
                       double target, double rate, const string& email, const string& phone, const string& departId);
    double getTarget() const;
    double getRate() const;
    void setTarget(double t);
    void setRate(double r);
    double getSalary() const override;
    void display() const override;
    void displayDetailed() const override;
};






#endif //COMMISSIONEMPLOYEE_H
