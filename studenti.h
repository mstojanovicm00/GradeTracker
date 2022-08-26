//
// Created by mstojanovic2000 on 26.8.22..
//

#ifndef GRADE_TRACKER_STUDENTI_H
#define GRADE_TRACKER_STUDENTI_H

#include "smerovi.h"

typedef struct {
    char ime[20];
    char prezime[20];
    smer smer;
    int broj;
    int godina;
    char mejl[50];
} student;

student student_create(char ime[], char prezime[], smer smer, int broj, int godina);
void student_print(student student);
student* student_mejl(student* student);
int student_compare(student s1, student s2);

void student_debug(student student);

typedef struct STUD {
    student student;
    struct STUD* left;
    struct STUD* right;
} stud_kol;

int student_exists(stud_kol* kol, student student);
stud_kol* stud_kol_add(stud_kol* kol, char ime[], char prezime[], smer smer, int broj, int godina);

#endif //GRADE_TRACKER_STUDENTI_H
