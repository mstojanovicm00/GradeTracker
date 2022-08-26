//
// Created by mstojanovic2000 on 26.8.22..
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "predmeti_studenti.h"

stud_kol *kolekcija_studenata = NULL;

static predmet_student *kreiraj_entry(char *predmet, student student) {
    predmet_student *e = (predmet_student*) malloc(sizeof(predmet_student));
    strcpy(e->predmet, predmet);
    e->student = &student;
    return e;
}

void ucitaj_predmet(char predmet[]) {
    char filename[105] = {0};
    strcat(filename, predmet);
    strcat(filename, ".subj");
    FILE* f = fopen(filename, "r");
    if (!f) {
        return;
    }
    char ime[20];
    char prezime[20];
    char smer[5];
    int broj;
    int godina;
    while (fscanf(f, "%s %s %s %d %d", ime, prezime, smer, &broj, &godina) == 5) {
        student student = student_create(ime, prezime, string_to_smer(smer), broj, godina);
        kolekcija_studenata = stud_kol_add(kolekcija_studenata, student);

    }

}