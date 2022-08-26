//
// Created by mstojanovic2000 on 26.8.22..
//
#include "predmeti.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* filename = "predmeti.txt";

pred_kol* predmeti_head = NULL;
pred_kol* predmeti_tail = NULL;

void ucitaj() {
    FILE* f = fopen(filename, "r");
    if (f == NULL)
        return;
    for (char linija[50] = {0}; fscanf(f, "%[^\n]\n", linija) == 1;) {
        kreiraj_predmet(linija);
    }
    fclose(f);
}

void ispisi() {
    FILE* f = fopen(filename, "w");
    if (f == NULL)
        return;
    for (pred_kol* e = predmeti_head; e; e = e->next)
        fprintf(f, "%s\n", e->predmet);
    fclose(f);
}

static pred_kol* predmet_create(char* naziv) {
    pred_kol* kol = (pred_kol*) malloc(sizeof(pred_kol));
    strcpy(kol->predmet, naziv);
    kol->next = NULL;
    return kol;
}

void kreiraj_predmet(char* naziv_predmeta) {
    pred_kol* kol = predmet_create(naziv_predmeta);
    if (!predmeti_head) {
        predmeti_head = kol;
        predmeti_tail = kol;
        return;
    }
    predmeti_tail->next = kol;
    predmeti_tail = kol;
}

void ispisi_predmete() {
    for (pred_kol* e = predmeti_head; e; e = e->next)
        fprintf(stdout, "%s\n", e->predmet);
}