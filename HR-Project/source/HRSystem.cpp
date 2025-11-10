#include "HRSystem.h"







HRSystem::HRSystem() {
    cout << "Welcome to Company's HR System.\n";
}

HRSystem::~HRSystem() {
    for (Employee* emp : employees) {
        delete emp;
    }
}

string HRSystem::generateRandomDepartId() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1000, 9999);
    string id;
    do {
        id = to_string(dis(gen));
    } while (!isUniqueDepartId(id));
    usedDepartIds.insert(id);
    return id;
}

bool HRSystem::isUniqueDepartId(const string& id) {
    return usedDepartIds.find(id) == usedDepartIds.end();
}

bool HRSystem::isUniqueEmployeeId(const string& id) {
    return usedEmployeeIds.find(id) == usedEmployeeIds.end();
}

void HRSystem::initialDepartments() {
    departments.clear();
    usedDepartIds.clear();
    vector<pair<string, string>> initialDepts = {
        {"00", "Unassigned"},
        {"11", "Web Department"},
        {"22", "Cyber Department"},
        {"33", "Data Department"},
        {"44", "IT Department"},
        {"55", "AI Department"}
    };
    for (const auto& dept : initialDepts) {
        departments.emplace_back(dept.first, dept.second);
        usedDepartIds.insert(dept.first);
    }
}

void HRSystem::initialEmployees() {
    employees.clear();
    usedEmployeeIds.clear();
    vector<Employee*> initialEmps = {
        new SalaryEmployee("Saif", "11550", "Web Developer", 555.2, "hfhhf@f", "010454545", "11"),
        new SalaryEmployee("Ahmed", "22440", "Cyber Engineer", 1000.2, "frfrf@f", "012445454", "22"),
        new SalaryEmployee("Sara", "33120", "Data Analyst", 1200.0, "sara@example.com", "123abc", "33"),
        new ManagerEmployee("Bilal", "44025", "IT Manager", 1900.9, "bilal@example.com", "manage123", "44", 500.0),
        new HourlyEmployee("Rana", "44160", "IT Support", 40.0, 23.75, "rana@example.com", "help321", "44"),
        new CommissionEmployee("Fadi", "55021", "AI Specialist", 100000.0, 0.17, "fadi@example.com", "ai2025", "55")
    };
    for (Employee* emp : initialEmps) {
        usedEmployeeIds.insert(emp->getEmployeeId());
        employees.push_back(emp);
    }
}

void HRSystem::addDepartment(const string& name) {
    string id = generateRandomDepartId();
    departments.emplace_back(id, name);
    cout << "Department added with ID: " << id << endl;
}

void HRSystem::addEmployee(Employee* emp) {
    if (isUniqueEmployeeId(emp->getEmployeeId())) {
        usedEmployeeIds.insert(emp->getEmployeeId());
        employees.push_back(emp);
        cout << "Employee added.\n";
    } else {
        delete emp;
        cout << "Employee ID already exists.\n";
    }
}

void HRSystem::editDepartment(const string& id, const string& newName) {
    Department* dept = findDepartment(id);
    if (dept) {
        dept->setDepartName(newName);
        cout << "Department updated.\n";
    } else {
        cout << "Department not found.\n";
    }
}

void HRSystem::deleteDepartment(const string& id) {
    if (id == "00") {
        cout << "Cannot delete Unassigned department.\n";
        return;
    }
    for (auto it = departments.begin(); it != departments.end(); ++it) {
        if (it->getDepartId() == id) {
            for (Employee* emp : employees) {
                if (emp->getDepartId() == id) {
                    emp->setDepartId("00");
                }
            }
            usedDepartIds.erase(id);
            departments.erase(it);
            cout << "Department deleted. Employees reassigned to Unassigned.\n";
            return;
        }
    }
    cout << "Department not found.\n";
}

void HRSystem::editEmployee(const string& id, Employee* emp) {
    for (auto it = employees.begin(); it != employees.end(); ++it) {
        if ((*it)->getEmployeeId() == id) {
            delete *it;
            *it = emp;
            cout << "Employee updated.\n";
            return;
        }
    }
    delete emp;
    cout << "Employee not found.\n";
}

void HRSystem::deleteEmployee(const string& id) {
    for (auto it = employees.begin(); it != employees.end(); ++it) {
        if ((*it)->getEmployeeId() == id) {
            delete *it;
            usedEmployeeIds.erase(id);
            employees.erase(it);
            cout << "Employee deleted.\n";
            return;
        }
    }
    cout << "Employee not found.\n";
}

Department* HRSystem::findDepartment(const string& id) {
    for (Department& dept : departments) {
        if (dept.getDepartId() == id) {
            return &dept;
        }
    }
    return nullptr;
}

Employee* HRSystem::findEmployee(const string& id)const {
    for (Employee* emp : employees) {
        if (emp->getEmployeeId() == id) {
            return emp;
        }
    }
    return nullptr;
}

void HRSystem::findEmployeesByName(const string& name, bool detailed) const {
    string lowerName = name;
    transform(lowerName.begin(), lowerName.end(), lowerName.begin(), ::tolower);
    bool found = false;
    for (const Employee* emp : employees) {
        string empName = emp->getName();
        transform(empName.begin(), empName.end(), empName.begin(), ::tolower);
        if (empName.find(lowerName) != string::npos) {
            found = true;
            if (detailed) {
                emp->displayDetailed();
            } else {
                emp->display();
            }
        }
    }
    if (!found) {
        cout << "No employees found with name containing: " << name << endl;
    }
}

void HRSystem::findEmployeesByJobTitle(const string& title, bool detailed) const {
    string lowerTitle = title;
    transform(lowerTitle.begin(), lowerTitle.end(), lowerTitle.begin(), ::tolower);
    bool found = false;
    for (const Employee* emp : employees) {
        string empTitle = emp->getJobTitle();
        transform(empTitle.begin(), empTitle.end(), empTitle.begin(), ::tolower);
        if (empTitle.find(lowerTitle) != string::npos) {
            found = true;
            if (detailed) {
                emp->displayDetailed();
            } else {
                emp->display();
            }
        }
    }
    if (!found) {
        cout << "No employees found with job title containing: " << title << endl;
    }
}

void HRSystem::findEmployeesByDepartment(const string& deptId, bool detailed) const {
    bool found = false;
    for (const Employee* emp : employees) {
        if (emp->getDepartId() == deptId) {
            found = true;
            if (detailed) {
                emp->displayDetailed();
            } else {
                emp->display();
            }
        }
    }
    if (!found) {
        cout << "No employees found in department ID: " << deptId << endl;
    }
}

void HRSystem::calculatePayroll() const {
    double total = 0.0;
    for (const Employee* emp : employees) {
        total += emp->getSalary();
    }
    cout << "Total payroll for all employees: $" << total << endl;
}

void HRSystem::calculatePayrollForDepartment(const string& deptId) const {
    double total = 0.0;
    bool found = false;
    for (const Employee* emp : employees) {
        if (emp->getDepartId() == deptId) {
            total += emp->getSalary();
            found = true;
        }
    }
    if (found) {
        cout << "Total payroll for department ID " << deptId << ": $" << total << endl;
    } else {
        cout << "No employees found in department ID: " << deptId << endl;
    }
}

void HRSystem::calculatePayrollForEmployee(const string& empId) const {
    Employee* emp = findEmployee(empId);
    if (emp) {
        cout << "Payroll for employee ID " << empId << ": $" << emp->getSalary() << endl;
    } else {
        cout << "Employee not found.\n";
    }
}

void HRSystem::displayAll() const {
    cout << "\nDepartments:\n";
    for (const Department& dept : departments) {
        cout << dept << endl;
        findEmployeesByDepartment(dept.getDepartId(), false);
    }
    cout << "\nAll Employees:\n";
    for (const Employee* emp : employees) {
        emp->display();
    }
}