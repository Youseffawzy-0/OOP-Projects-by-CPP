#ifndef MANAGEREMPLOYEE_H
#define MANAGEREMPLOYEE_H
#include "SalaryEmployee.h"




class ManagerEmployee : public SalaryEmployee {
protected:
    double bonus;

public:
    ManagerEmployee(const string& name, const string& employeeId, const string& jobTitle,
                    double salary, const string& email, const string& phone, const string& departId, double bonus = 0.0);
    void addBonus(double moreBonus);
    double getSalary() const override;
    void display() const override;
    void displayDetailed() const override;
};

#endif //MANAGEREMPLOYEE_H
