#include "Person.h"


Person::Person() {
    name = "yousef";
    age = 19;
}
Person::Person(string name, int age) {
    this->name = name;
    this->age = age;
}

void Person::display(ostream& os) const {
    os << "Name: " << name << ", Age: " << age;
}














