#ifndef HRSYSTEM_H
#define HRSYSTEM_H
#include <bits/stdc++.h>
#include "Employee.h"
#include "ManagerEmployee.h"
#include "HourlyEmployee.h"
#include "CommissionEmployee.h"
#include "Department.h"
using namespace std;



class HRSystem {
private:
    vector<Department> departments;
    vector<Employee*> employees;
    set<string> usedDepartIds;
    set<string> usedEmployeeIds;

public:
    HRSystem();
    ~HRSystem();
    void initialDepartments();
    void initialEmployees();
    string generateRandomDepartId();
    bool isUniqueDepartId(const string& id);
    bool isUniqueEmployeeId(const string& id);
    void addDepartment(const string& name);
    void addEmployee(Employee* emp);
    void editDepartment(const string& id, const string& newName);
    void deleteDepartment(const string& id);
    void editEmployee(const string& id, Employee* emp);
    void deleteEmployee(const string& id);
    Department* findDepartment(const string& id);
    Employee* findEmployee(const string& id) const;
    void findEmployeesByName(const string& name, bool detailed) const;
    void findEmployeesByJobTitle(const string& title, bool detailed) const;
    void findEmployeesByDepartment(const string& deptId, bool detailed) const;
    void calculatePayroll() const;
    void calculatePayrollForDepartment(const string& deptId) const;
    void calculatePayrollForEmployee(const string& empId) const;
    void displayAll() const;
};





#endif //HRSYSTEM_H
