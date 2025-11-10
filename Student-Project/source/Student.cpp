#include "Student.h"



Student::Student():Person()
{
    id =55;
    gpa=3.8;
    email="Yousefmohamed2654@gmail.com";
    phone="01018400191";
}

Student::Student(string name, int age, int id, float gpa, string email, string phone)
    :Person(name,age),id(id),gpa(gpa),email(email),phone(phone){}
void Student::display(ostream& os) const  {
    Person::display(os);
    os<<" id: "<<id<<" gpa: "<<gpa<<" email: "<<email<<" phone: "<<phone<<endl;
}
bool Student::operator==(Student student2) {
    return gpa == student2.gpa;
}
bool Student::operator>=(Student student2) {
    return gpa>=student2.gpa;
}
void Student::operator+(int extraGpa) {
    gpa+=extraGpa;
    if (gpa>4.0) gpa=4.0;
}
    void Student::setId(int i) { id = i; }
    void Student::setGpa(float g) { gpa = g; }
    void Student::setPhone( string p) { phone = p; }
    void Student::setEmail( string e) { email = e; }

    int Student::getId() { return id; }
    float Student::getGpa() { return gpa; }
    string Student::getPhone() { return phone; }
    string Student::getEmail() { return email; }







