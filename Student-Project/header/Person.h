#ifndef PERSON_H
#define PERSON_H
#include <bits/stdc++.h>
using namespace std;


class Person
{
protected:
    int age;string name;
public:
    Person();
    Person(string name, int age);
    virtual void display(ostream& os) const;
    friend ostream& operator<<(ostream& os, const Person& person) {
        person.display(os);
        return os;
    }


};















#endif