#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 120

typedef struct subject {
    char name[MAXSIZE];
    int marks;
} subject_t;

typedef struct student {
    char name[MAXSIZE];
    int classRoll;
    subject_t subjects[MAXSIZE];
} student_t;

void collectStudentDetails(student_t student[], int numStudents, char subjects[][MAXSIZE], int numSub) {
    int i, j;

    for(i = 0 ; i < numStudents ; i++) {
        printf("Name: ");
        scanf("%s", student[i].name);

        printf("Class Roll: ");
        scanf("%d", &student[i].classRoll);

        for(j = 0 ; j < numSub ; j++) {
            strcpy(student[i].subjects[j].name, subjects[j]);

            printf("Enter marks for %s: ", student[i].subjects[j].name);
            scanf("%d", &student[i].subjects[j].marks);
        }

        printf("\n");
    }
}

void displayStudentDetails(student_t student[], int numStudents, int numSub) {
    int i, j;
    char header[10][10] = {"Name", "Roll"};

    printf("%16s %4s ", header[0], header[1]);

    for(i = 0 ; i < numSub ; i++) {
        printf("%16s ", student[0].subjects[i].name);
    }

    printf("\n");

    for(i = 0 ; i < numStudents ; i++) {
        printf("%16s %4d ", student[i].name, student[i].classRoll);

        for(j = 0 ; j < numSub ; j++) {
            printf("%16d ", student[i].subjects[j].marks);
        }

        printf("\n");
    }
}

int main() {
    int numStudents, numSub, i;
    char subjects[MAXSIZE][MAXSIZE];
    student_t student[100];

    printf("How many students do you want to add? ");
    scanf("%d", &numStudents);

    printf("How many subjects were in the exam? ");
    scanf("%d", &numSub);

    printf("Enter subject names: ");
    for(i = 0 ; i < numSub ; i++) {
        fscanf(stdin, "%s", subjects[i]);
    }

    printf("\n");
    printf("Enter student details:\n");
    collectStudentDetails(student, numStudents, subjects, numSub);

    printf("\n");
    printf("Student details you have entered are:\n");
    displayStudentDetails(student, numStudents, numSub);

    return 0;
}
