#include <iostream>
#include <iomanip>
#include "sis.hpp"

using namespace std;

Student student[MAXSTUDENTS];
int nStudents = 0;
int i = 0;

void addStudents() {
    int op;

    while(1) {
        cout << "Please enter student details:\n";

        cout << "Name      : ";
        cin >> student[i].name;
        cout << "Department: ";
        cin >> student[i].dept;
        cout << "Year      : ";
        cin >> student[i].year;
        cout << "Class roll: ";
        cin >> student[i].classRoll;
        cout << "Marks for Sub1: ";
        cin >> student[i].sub1;
        cout << "Marks for Sub2: ";
        cin >> student[i].sub2;
        cout << "Marks for Sub3: ";
        cin >> student[i].sub3;
        cout << "Marks for Sub4: ";
        cin >> student[i].sub4;

        nStudents++;
        i++;

        cout << "Add another student? (1 for YES / 0 for NO): ";
        cin >> op;

        if(op != 1)
            return;
    }
}

void displayDetails() {
    int i;

    cout << "Displaying student details:\n"
         << "           Personal Details             |        Marks         \n"
         << "--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---\n"
         << "            Name      Dept.  Year  Roll | Sub1 Sub2 Sub3 Sub4  \n"
         << "--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---\n";

    for(i = 0 ; i < nStudents ; i++) {
        cout << setw(16) << student[i].name << " "
             << setw(10) << student[i].dept << " "
             << setw(5) << student[i].year << " "
             << setw(5) << student[i].classRoll << " "
             << setw(4) << student[i].sub1 << " "
             << setw(4) << student[i].sub2 << " "
             << setw(4) << student[i].sub3 << " "
             << setw(4) << student[i].sub4 << endl;
    }

    cout << "--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---\n";
}

int main() {
    int op;

    while(1) {
        cout << "Operation:\n"
             << "--- --- --- --- --- --- --- ---\n"
             << "\t1. Add students\n"
             << "\t2. Display details\n"
             << "\t3. Exit\n"
             << "\tEnter choice > ";

        cin >> op;

        switch(op) {
            case 1:
                addStudents();
                break;
            case 2:
                displayDetails();
                break;
            case 3:
                return 0;
            default:
                break;
        }
    }

    return 0;
}