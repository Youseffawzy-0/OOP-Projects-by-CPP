#ifndef SYSTEM_H
#define SYSTEM_H
#include "Student.h"

class System : public Student {
private:
    int capacity,size;
    Student* st;
public:
    System();
    void findById(int id);
    int compareStudents(int id1,int id2);
    void addStudent(Student& student);
    void display()const;
    void resize();
    void addExtraGpa(int id,float extraGpa)const;
    void sortByGpa();

};













#endif