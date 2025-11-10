#include "System.h"



System::System() :capacity(5){
    st=new Student[capacity];
    st[0]=Student();
    st[1]=Student("khaled",15,45,2.4,"hhjh@add.com","0101564");
    st[2]=Student("jo",20,888,1.6,"jgggg@add.com","0101564555455");
    st[3] = Student("khaled", 21, 789, 1.6, "01018550191", "yousefmohamed2655@gmail.com");
    st[4] = Student("ali", 22, 1011, 4.0, "010541125", "haah@yahoo.com");
    size =5;
}
void System::findById(int id) {
    bool found = false;
    for(int i=0;i<capacity;i++) {
        if (st[i].getId() == id) {
            found = true;
            cout<<st[i];
            break;
        }
    }
    if (!found) cout<<"not found.";

}
int System::compareStudents(int id1,int id2) {
    int x=0,y=0;
    for (int i=0;i<capacity;i++) {
        if (st[i].getId() == id1) {x=st[i].getGpa();}
        if (st[i].getId() == id2) {y=st[i].getGpa();}
    }
    if (x==y) {return 0;}
    else if (x>y) {return 1;}
    else {return -1;}
}
void System::resize() {
    capacity *= 2;
    Student* temp=new Student[capacity];
    copy(st,st+size,temp);
    delete[] st;
    st=temp;
}

void System::addStudent(Student& student) {
    if (size==capacity) resize();
    st[size++]=student;
}
void System::display() const {
    for(int i=0;i<size;++i) {cout<<"Student no. "<<i+1<<": "<<st[i]<<endl;}
}
void System::addExtraGpa(int id ,float extraGpa)const {
    for (int i=0;i<capacity;i++) {
        if (st[i].getId() == id) {st[i]+extraGpa;}
    }

}
void System::sortByGpa() {
    sort(st,st+size,[](Student& a,Student& b) {return a.getGpa()>=b.getGpa();});
}
