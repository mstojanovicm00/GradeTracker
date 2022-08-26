//
// Created by mstojanovic2000 on 26.8.22..
//

#ifndef GRADE_TRACKER_PREDMETI_STUDENTI_H
#define GRADE_TRACKER_PREDMETI_STUDENTI_H

#include "predmeti.h"
#include "studenti.h"

typedef struct {
    char predmet[100];
    student* student;
} predmet_student;

void ucitaj_predmet(char predmet[]);

#endif //GRADE_TRACKER_PREDMETI_STUDENTI_H
