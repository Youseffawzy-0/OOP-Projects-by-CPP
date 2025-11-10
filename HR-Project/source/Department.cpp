#include "Department.h"




Department::Department(const string& departId, const string& departName) {
    this->departId = departId;
    this->departName = departName;
}

void Department::setDepartId(const string& id) {
    departId = id;
}

void Department::setDepartName(const string& name) {
    departName = name;
}

string Department::getDepartId() const {
    return departId;
}

string Department::getDepartName() const {
    return departName;
}

void Department::print(ostream& os) const {
    os << "Department ID: " << departId << " Department Name: " << departName;
}
