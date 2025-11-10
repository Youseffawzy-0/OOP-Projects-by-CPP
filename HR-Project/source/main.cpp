#include <bits/stdc++.h>
#include "HRSystem.h"
using namespace std;

int message1(HRSystem& sys);
int message2(HRSystem& sys);

int message(HRSystem& sys) {
    int choice;
    cout << ".................................\n"
         << "1. Departments Hub.\n"
         << "2. Employees Hub.\n"
         << "3. Display All.\n"
         << "0. Exit.\n"
         << "Enter your choice: ";
    cin >> choice;
    while (cin.fail() || choice < 0 || choice > 3) {
        cout << "Invalid choice: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> choice;
    }
    cin.ignore();
    if (choice == 1) {
        while (message1(sys) != 0);
    } else if (choice == 2) {
        while (message2(sys) != 0);
    } else if (choice == 3) {
        sys.displayAll();
    }
    return choice;
}

int message1(HRSystem& sys) {
    int choice;
    cout << "...............................\n"
         << "Welcome to Departments Hub\n"
         << "1. Add department\n"
         << "2. Edit department\n"
         << "3. Delete department\n"
         << "4. Find department\n"
         << "0. Return to main menu.\n"
         << "Enter your choice: ";
    cin >> choice;
    while (cin.fail() || choice < 0 || choice > 4) {
        cout << "Invalid choice: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> choice;
    }
    cin.ignore();
    if (choice == 1) {
        string name;
        cout << "Enter Department Name: ";
        getline(cin, name);
        sys.addDepartment(name);
    } else if (choice == 2) {
        string id, name;
        cout << "Enter Department ID to edit: ";
        getline(cin, id);
        cout << "Enter new Department Name: ";
        getline(cin, name);
        sys.editDepartment(id, name);
    } else if (choice == 3) {
        string id;
        cout << "Enter Department ID to delete: ";
        getline(cin, id);
        sys.deleteDepartment(id);
    } else if (choice == 4) {
        string id;
        cout << "Enter Department ID to find: ";
        getline(cin, id);
        Department* dept = sys.findDepartment(id);
        if (dept) {
            cout << *dept << endl;
            sys.findEmployeesByDepartment(id, true);
        } else {
            cout << "Department not found.\n";
        }
    }
    return choice;
}

int message2(HRSystem& sys) {
    int choice;
    cout << "........................\n"
         << "Welcome to Employees Hub.\n"
         << "1. Add Employee\n"
         << "2. Edit Employee\n"
         << "3. Delete Employee\n"
         << "4. Find Employee\n"
         << "5. Calculate Payroll\n"
         << "0. Return to main menu\n"
         << "Enter your choice: ";
    cin >> choice;
    while (cin.fail() || choice < 0 || choice > 5) {
        cout << "Invalid choice: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> choice;
    }
    cin.ignore();
    if (choice == 1) {
        string name, id, title, email, phone, deptId;
        int empType;
        cout << "Enter Employee Type (1: Salary, 2: Manager, 3: Hourly, 4: Commission): ";
        cin >> empType;
        while (cin.fail() || empType < 1 || empType > 4) {
            cout << "Invalid type: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> empType;
        }
        cin.ignore();
        cout << "Enter Employee Name: ";
        getline(cin, name);
        cout << "Enter Employee ID: ";
        getline(cin, id);
        if (!sys.isUniqueEmployeeId(id)) {
            cout << "Employee ID already exists.\n";
            return choice;
        }
        cout << "Enter Job Title: ";
        getline(cin, title);
        cout << "Enter Email: ";
        getline(cin, email);
        cout << "Enter Phone: ";
        getline(cin, phone);
        cout << "Enter Department ID: ";
        getline(cin, deptId);
        Employee* emp = nullptr;
        if (empType == 1) {
            double salary;
            cout << "Enter Salary: ";
            cin >> salary;
            while (cin.fail() || salary < 0) {
                cout << "Invalid salary: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> salary;
            }
            cin.ignore();
            emp = new SalaryEmployee(name, id, title, salary, email, phone, deptId);
        } else if (empType == 2) {
            double salary, bonus;
            cout << "Enter Salary: ";
            cin >> salary;
            while (cin.fail() || salary < 0) {
                cout << "Invalid salary: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> salary;
            }
            cout << "Enter Bonus: ";
            cin >> bonus;
            while (cin.fail() || bonus < 0) {
                cout << "Invalid bonus: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> bonus;
            }
            cin.ignore();
            emp = new ManagerEmployee(name, id, title, salary, email, phone, deptId, bonus);
        } else if (empType == 3) {
            double hours, rate;
            cout << "Enter Hours Worked: ";
            cin >> hours;
            while (cin.fail() || hours < 0) {
                cout << "Invalid hours: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> hours;
            }
            cout << "Enter Hourly Rate: ";
            cin >> rate;
            while (cin.fail() || rate < 0) {
                cout << "Invalid rate: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> rate;
            }
            cin.ignore();
            emp = new HourlyEmployee(name, id, title, hours, rate, email, phone, deptId);
        } else if (empType == 4) {
            double target, rate;
            cout << "Enter Sales Target: ";
            cin >> target;
            while (cin.fail() || target < 0) {
                cout << "Invalid target: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> target;
            }
            cout << "Enter Commission Rate: ";
            cin >> rate;
            while (cin.fail() || rate < 0) {
                cout << "Invalid rate: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> rate;
            }
            cin.ignore();
            emp = new CommissionEmployee(name, id, title, target, rate, email, phone, deptId);
        }
        sys.addEmployee(emp);
    } else if (choice == 2) {
        string id;
        cout << "Enter Employee ID to edit: ";
        getline(cin, id);
        Employee* existing = sys.findEmployee(id);
        if (existing) {
            string name, title, email, phone, deptId;
            int empType;
            cout << "Enter Employee Type (1: Salary, 2: Manager, 3: Hourly, 4: Commission): ";
            cin >> empType;
            while (cin.fail() || empType < 1 || empType > 4) {
                cout << "Invalid type: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> empType;
            }
            cin.ignore();
            cout << "Enter new Employee Name: ";
            getline(cin, name);
            cout << "Enter new Job Title: ";
            getline(cin, title);
            cout << "Enter new Email: ";
            getline(cin, email);
            cout << "Enter new Phone: ";
            getline(cin, phone);
            cout << "Enter new Department ID: ";
            getline(cin, deptId);
            Employee* emp = nullptr;
            if (empType == 1) {
                double salary;
                cout << "Enter new Salary: ";
                cin >> salary;
                while (cin.fail() || salary < 0) {
                    cout << "Invalid salary: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin >> salary;
                }
                cin.ignore();
                emp = new SalaryEmployee(name, id, title, salary, email, phone, deptId);
            } else if (empType == 2) {
                double salary, bonus;
                cout << "Enter new Salary: ";
                cin >> salary;
                while (cin.fail() || salary < 0) {
                    cout << "Invalid salary: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin >> salary;
                }
                cout << "Enter new Bonus: ";
                cin >> bonus;
                while (cin.fail() || bonus < 0) {
                    cout << "Invalid bonus: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin >> bonus;
                }
                cin.ignore();
                emp = new ManagerEmployee(name, id, title, salary, email, phone, deptId, bonus);
            } else if (empType == 3) {
                double hours, rate;
                cout << "Enter new Hours Worked: ";
                cin >> hours;
                while (cin.fail() || hours < 0) {
                    cout << "Invalid hours: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin >> hours;
                }
                cout << "Enter new Hourly Rate: ";
                cin >> rate;
                while (cin.fail() || rate < 0) {
                    cout << "Invalid rate: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin >> rate;
                }
                cin.ignore();
                emp = new HourlyEmployee(name, id, title, hours, rate, email, phone, deptId);
            } else if (empType == 4) {
                double target, rate;
                cout << "Enter new Sales Target: ";
                cin >> target;
                while (cin.fail() || target < 0) {
                    cout << "Invalid target: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin >> target;
                }
                cout << "Enter new Commission Rate: ";
                cin >> rate;
                while (cin.fail() || rate < 0) {
                    cout << "Invalid rate: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin >> rate;
                }
                cin.ignore();
                emp = new CommissionEmployee(name, id, title, target, rate, email, phone, deptId);
            }
            sys.editEmployee(id, emp);
        } else {
            cout << "Employee not found.\n";
        }
    } else if (choice == 3) {
        string id;
        cout << "Enter Employee ID to delete: ";
        getline(cin, id);
        sys.deleteEmployee(id);
    } else if (choice == 4) {
        int searchType;
        cout << "Search by:\n1. ID\n2. Name\n3. Job Title\n4. Department ID\nEnter choice: ";
        cin >> searchType;
        while (cin.fail() || searchType < 1 || searchType > 4) {
            cout << "Invalid choice: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> searchType;
        }
        cin.ignore();
        if (searchType == 1) {
            string id;
            cout << "Enter Employee ID: ";
            getline(cin, id);
            Employee* emp = sys.findEmployee(id);
            if (emp) {
                char view;
                cout << "Detailed view? (y/n): ";
                cin >> view;
                cin.ignore();
                if (view == 'y' || view == 'Y') {
                    emp->displayDetailed();
                } else {
                    emp->display();
                }
            } else {
                cout << "Employee not found.\n";
            }
        } else if (searchType == 2) {
            string name;
            cout << "Enter Name (partial match): ";
            getline(cin, name);
            char view;
            cout << "Detailed view? (y/n): ";
            cin >> view;
            cin.ignore();
            sys.findEmployeesByName(name, view == 'y' || view == 'Y');
        } else if (searchType == 3) {
            string title;
            cout << "Enter Job Title (partial match): ";
            getline(cin, title);
            char view;
            cout << "Detailed view? (y/n): ";
            cin >> view;
            cin.ignore();
            sys.findEmployeesByJobTitle(title, view == 'y' || view == 'Y');
        } else if (searchType == 4) {
            string deptId;
            cout << "Enter Department ID: ";
            getline(cin, deptId);
            char view;
            cout << "Detailed view? (y/n): ";
            cin >> view;
            cin.ignore();
            sys.findEmployeesByDepartment(deptId, view == 'y' || view == 'Y');
        }
    } else if (choice == 5) {
        int payrollType;
        cout << "Calculate payroll for:\n1. All Employees\n2. Department\n3. Individual Employee\nEnter choice: ";
        cin >> payrollType;
        while (cin.fail() || payrollType < 1 || payrollType > 3) {
            cout << "Invalid choice: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> payrollType;
        }
        cin.ignore();
        if (payrollType == 1) {
            sys.calculatePayroll();
        } else if (payrollType == 2) {
            string deptId;
            cout << "Enter Department ID: ";
            getline(cin, deptId);
            sys.calculatePayrollForDepartment(deptId);
        } else if (payrollType == 3) {
            string empId;
            cout << "Enter Employee ID: ";
            getline(cin, empId);
            sys.calculatePayrollForEmployee(empId);
        }
    }
    return choice;
}

int main() {
    HRSystem sys;
    sys.initialDepartments();
    sys.initialEmployees();
    int choice;
    do {
        choice = message(sys);
    } while (choice != 0);
    return 0;
}


