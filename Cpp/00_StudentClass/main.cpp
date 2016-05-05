/* ==================================================================
 * A program to implement the class student with name,  marks,  init-
 * function,  function to compute average and function to display the
 * data.
 * ==================================================================
 */

#include <iostream>
#include <stdlib.h>
#include <string.h>
#define MAXSUB 4
#define MAXLEN 32

using namespace std;

class Student {
    char * name;         //-- Should be re-written using String class
    float marks[MAXSUB];
public:
    void init();                      //-- Initialize student objects
    void getDetails();                //-- Input  all student details
    float average(float marks[]);     //-- Calculate   average  marks
    void display();
};

void Student::init() {
    name = (char *)malloc(sizeof(char) * MAXLEN);
    strcpy(name, " ");

    for(int i = 0 ; i < MAXSUB ; i++) {
        marks[i] = 0;
    }
}

void Student::getDetails() {
    cout << "Name: ";
    cin >> name;

    cout << "Enter marks of " << name << "..\n";
    for(int i = 0 ; i < MAXSUB ; i++) {
        cin >> marks[i];
    }
}

float Student::average(float marks[]) {
    float avg, sumOfAll;

    for(int i = 0 ; i < MAXSUB ; i++) {
        sumOfAll += marks[i];
    }

    avg = sumOfAll / MAXSUB;

    return avg;
}

void Student::display() {
    cout << "Name of student: " << name << "\n";

    cout << "Marks obtained..\n";
    for(int i = 0 ; i < MAXSUB ; i++) {
        cout << "Sub [" << i << "]: " << marks[i] << "\n";
    }

    cout << "Average: " << average(marks) << "\n";
}

int main() {
    int nStudents;

    cout << "How many students are in the class: ";
    cin >> nStudents;

    Student st[nStudents];

    cout << "Enter details for " << nStudents << " students..\n";
    for(int i = 0 ; i < nStudents ; i++) {
        st[i].init();
        st[i].getDetails();
    }

    cout << "Displaying details of students..\n";
    for(int i = 0 ; i < nStudents ; i++) {
        st[i].display();
    }

    return 0;
}
