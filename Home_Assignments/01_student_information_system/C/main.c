#include <stdio.h>
#include <stdlib.h>
#include "sis.h"

student_t student[MAXSTUDENTS];
int nStudents = 0;
int i = 0;

void addStudents() {
    int op;

    while(1) {
        printf("Please enter student details:\n");

        printf("Name      : ");
        scanf("%s", student[i].name);
        printf("Department: ");
        scanf("%s", student[i].dept);
        printf("Year      : ");
        scanf("%d", &student[i].year);
        printf("Class roll: ");
        scanf("%d", &student[i].classRoll);
        printf("Marks for Sub1: ");
        scanf("%d", &student[i].marks.sub1);
        printf("Marks for Sub2: ");
        scanf("%d", &student[i].marks.sub2);
        printf("Marks for Sub3: ");
        scanf("%d", &student[i].marks.sub3);
        printf("Marks for Sub4: ");
        scanf("%d", &student[i].marks.sub4);

        nStudents++;
        i++;

        printf("Add another student? (1 for YES / 0 for NO): ");
        scanf("%d", &op);

        if(op != 1)
            return;
    }
}

void displayDetails() {
    int i;

    printf("Displaying student details:\n");
    printf("           Personal Details             |        Marks         \n");
    printf("--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---\n");
    printf("            Name      Dept.  Year  Roll | Sub1 Sub2 Sub3 Sub4  \n");
    printf("--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---\n");

    for(i = 0 ; i < nStudents ; i++) {
        printf("%16s %10s %5d %5d | %4d %4d %4d %4d\n",
               student[i].name, student[i].dept,
               student[i].year, student[i].classRoll,
               student[i].marks.sub1, student[i].marks.sub2,
               student[i].marks.sub3, student[i].marks.sub4);
    }

    printf("--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---\n");
}

int main() {
    int op;

    while(1) {
        printf("Operation:\n");
        printf("--- --- --- --- --- --- --- ---\n");
        printf("\t1. Add students\n");
        printf("\t2. Display details\n");
        printf("\t3. Exit\n");
        printf("\tEnter choice > ");

        scanf("%d", &op);

        switch(op) {
            case 1:
                addStudents();
                break;
            case 2:
                displayDetails();
                break;
            case 3:
                exit(EXIT_SUCCESS);
            default:
                break;
        }
    }
}