#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include<bits/stdc++.h>
using namespace std;


class Department {
protected:
    string departId;
    string departName;

public:
    Department(const string& departId, const string& departName);
    void setDepartId(const string& id);
    void setDepartName(const string& name);
    string getDepartId() const;
    string getDepartName() const;

    virtual void print(ostream& os) const;
    friend ostream& operator<<(ostream& os, const Department& obj) {
        obj.print(os);
        return os;
    }
};

#endif //DEPARTMENT_H
