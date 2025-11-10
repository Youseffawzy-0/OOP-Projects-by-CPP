#include "System.h"
#include <bits/stdc++.h>
using namespace std;



void message() {
    cout<<"\n...................................\n";
    cout<< "\nStudent Management System\n";
    cout<< "1. Add a Student\n";
    cout<< "2. Compare Students\n";
    cout<< "3. Display All Students\n";
    cout<< "4. Find Student by ID\n";
    cout<< "5. Add more GPA to a Student\n";
    cout<< "6. Sort Students by GPA\n";
    cout<< "0. Exit\n";
    cout<<"..................................\n";
    cout<< "Enter choice: ";
}
int main() {
    System system;
    int choice;
    message();
    cin>>choice;
    while(choice!=0) {
        if(choice==1) {
            int age,id;
            string name,email,phone;
            float gpa;
            cout<<"Enter Student Name: ";cin>>name;
            cout<<"Enter Student Age: ";cin>>age;
            cout<<"Enter Student ID: ";cin>>id;
            cout<<"Enter Student GPA: ";cin>>gpa;if(gpa>4.0)gpa=4.0;
            cout<<"Enter Student Email: ";cin>>email;
            cout<<"Enter Student Phone: ";cin>>phone;
            Student student(name,age,id,gpa,email,phone);
            system.addStudent(student);
            cout<<"Student has been added successfully! Details: "<<student<<endl;
            message();cin>>choice;
        }
        else if(choice==2) {
            int id1,id2;
            cout<<"Enter Student 1 ID: ";cin>>id1;
            cout<<"Enter Student 2 ID: ";cin>>id2;
            int x=system.compareStudents(id1,id2);
            if(x==1) {cout<<"Student 1 has more gpa.\n";}
            else if (x==-1)(cout<<"Student 2 has more gpa.\n");
            else(cout<<"Student 1 has the same gpa as Student 2.\n");
            message();cin>>choice;
        }
        else if(choice==3) {
            system.display();
            message();cin>>choice;
        }
        else if(choice==4) {
            int id;
            cout<<"Enter Student ID: ";cin>>id;
            system.findById(id);
            message();cin>>choice;
        }
        else if(choice==5) {
            cout<<"Enter Student ID: ";int id;cin>>id;
            cout<<"Enter extra GPA: ";float extraGpa;cin>>extraGpa;
            system.addExtraGpa(id,extraGpa);
            message();cin>>choice;
        }
        else if(choice==6) {
            system.sortByGpa();
            cout<<"Students sorted by GPA\n";
            message();cin>>choice;
        }
        else cout<<"invaild choice.";
    }
}