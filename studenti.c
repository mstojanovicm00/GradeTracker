//
// Created by mstojanovic2000 on 26.8.22..
//

#include "studenti.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

student student_create(char ime[], char prezime[], smer smer, int broj, int godina) {
    student s;
    strcpy(s.ime, ime);
    strcpy(s.prezime, prezime);
    s.smer = smer;
    s.broj = broj;
    s.godina = godina;
    strcpy(s.mejl, "");
    return s;
}

void student_print(student student) {
    printf("\t         Ime: %s\n", student.ime);
    printf("\t     Prezime: %s\n", student.prezime);
    printf("\t        Smer: %s\n", smer_to_string(student.smer));
    printf("\t  Broj upisa: %d\n", student.broj);
    printf("\tGodina upisa: %d\n", student.godina);

}

student* student_mejl(student* student) {
    if (student->mejl[0])
        return student;
    if (student->godina <= 2017) {
        char mejl[50] = {0};
        sprintf(mejl, "%c%s%d@raf.rs", student->ime[0], student->prezime, student->godina % 100);
        for (char* s = mejl; *s != '@'; ++s) {
            if (*s >= 'A' && *s <= 'Z')
                *s += 'a' - 'A';
        }
        strcpy(student->mejl, mejl);
        return student;
    }
    char mejl[50] = {0};
    sprintf(mejl, "%c%s%d%d%s@raf.rs",
            student->ime[0], student->prezime, student->broj, student->godina % 100, smer_to_string(student->smer));
    for (char* s = mejl; *s != '@'; ++s) {
        if (*s >= 'A' && *s <= 'Z')
            *s += 'a' - 'A';
    }
    strcpy(student->mejl, mejl);
    return student;
}

int student_compare(student s1, student s2) {
    if (s1.godina < s2.godina)
        return -1;
    if (s1.godina > s2.godina)
        return 1;
    if (s1.smer < s2.smer)
        return -1;
    if (s1.smer > s2.smer)
        return 1;
    if (s1.broj < s2.broj)
        return -1;
    if (s1.broj > s2.broj)
        return 1;
    return 0;
}

void student_debug(student student) {
    fprintf(stderr, "%s", student_mejl(&student)->mejl);
}

int student_exists(stud_kol* kol, student student) {
    if (kol == NULL)
        return 0;
    if (student_compare(kol->student, student) == 0)
        return 1;
    if (student_exists(kol->left, student))
        return 1;
    if (student_exists(kol->right, student))
        return 1;
    return 0;
}

static stud_kol* stud_kol_create(student student) {
    stud_kol* kol = (stud_kol*) malloc(sizeof(stud_kol));
    kol->student = student;
    kol->left = NULL;
    kol->right = NULL;
    return kol;
}

static stud_kol* stud_kol_add_rec(stud_kol* koren, stud_kol* element) {
    if (koren == NULL)
        return element;
    if (student_compare(koren->student, element->student) < 0)
        koren->right = stud_kol_add_rec(koren->right, element);
    else if (student_compare(koren->student, element->student) < 0)
        koren->left = stud_kol_add_rec(koren->left, element);
    return koren;
}

stud_kol* stud_kol_add(stud_kol* kol, char ime[], char prezime[], smer smer, int broj, int godina) {
    student student = student_create(ime, prezime, smer, broj, godina);
    if (student_exists(kol, student))
        return kol;
    stud_kol* nova = stud_kol_create(student);
    return stud_kol_add_rec(kol, nova);
}