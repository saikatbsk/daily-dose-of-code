#ifndef _SIS_H_
#define _SIS_H_

#define MAXSTUDENTS 128
#define MAXSIZE     128

typedef struct marks {
    int sub1;
    int sub2;
    int sub3;
    int sub4;
} marks_t;

typedef struct student {
    char name[MAXSIZE];
    char dept[MAXSIZE];
    int year;
    int classRoll;
    marks_t marks;
} student_t;

#endif