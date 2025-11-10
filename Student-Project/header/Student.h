#ifndef STUDENT_H
#define STUDENT_H
#include "Person.h"


class Student : public Person
{
protected:
int id;float gpa;string email,phone;
public:
    Student();
    Student(string name ,int age,int id,float gpa ,string email,string phone);
    void display(ostream& os) const override;
    friend ostream& operator<<(ostream& os, const Student& student) {
        student.display(os);
        return os;
    }
    bool operator ==(Student student2);
    bool operator >=(Student student2);
    void operator +(int extraGpa);
    void setId(int i);
    void setGpa(float g) ;
    void setPhone( string p);
    void setEmail( string e);
    int getId() ;
    float getGpa();
    string getPhone() ;
    string getEmail() ;
};


















#endif
