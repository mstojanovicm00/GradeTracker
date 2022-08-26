//
// Created by mstojanovic2000 on 26.8.22..
//

#ifndef GRADE_TRACKER_PREDMETI_H
#define GRADE_TRACKER_PREDMETI_H

typedef struct PRED {
    char predmet[50];
    struct PRED* next;
} pred_kol;

void ucitaj();
void ispisi();

void kreiraj_predmet(char* naziv_predmeta);

void ispisi_predmete();

#endif //GRADE_TRACKER_PREDMETI_H
