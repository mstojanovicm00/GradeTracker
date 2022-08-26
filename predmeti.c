//
// Created by mstojanovic2000 on 26.8.22..
//
#include "predmeti.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char filename[] = "predmeti.txt";

pred_kol* predmeti_head = NULL;
pred_kol* predmeti_tail = NULL;

void ucitaj() {
    FILE* f = fopen(filename, "r");
    if (f == NULL) {
        return;
    }
    for (char linija[100] = {0}; fscanf(f, "%[^\n]\n", linija) == 1;) {
        kreiraj_predmet(linija);
    }
    fclose(f);
}

static void obrisi_listu(pred_kol* e) {
    if (e == NULL)
        return;
    obrisi_listu(e->next);
    free(e);
}

void ispisi() {
    FILE* f = fopen(filename, "w");
    if (f == NULL) {
        obrisi_listu(predmeti_head);
        return;
    }
    for (pred_kol* e = predmeti_head; e; e = e->next)
        fprintf(f, "%s\n", e->predmet);
    obrisi_listu(predmeti_head);
    fclose(f);
}

static pred_kol* predmet_create(char* naziv) {
    pred_kol* kol = (pred_kol*) malloc(sizeof(pred_kol));
    strcpy(kol->predmet, naziv);
    kol->next = NULL;
    return kol;
}

static void napravi_fajl(char* filename, char* ekstenzija) {
    char fajl[105] = {0};
    strcat(fajl, filename);
    strcat(fajl, ".");
    strcat(fajl, ekstenzija);
    FILE* temp = fopen(fajl, "r");
    if (temp == NULL) {
        FILE *f = fopen(fajl, "w");
        if (f == NULL)
            return;
        fclose(f);
    }
    fclose(temp);
}

void kreiraj_predmet(char* naziv_predmeta) {
    pred_kol* kol = predmet_create(naziv_predmeta);
    if (!predmeti_head) {
        predmeti_head = kol;
        predmeti_tail = kol;
        napravi_fajl(naziv_predmeta, "subj");
        return;
    }
    predmeti_tail->next = kol;
    predmeti_tail = kol;
    napravi_fajl(naziv_predmeta, "subj");
}

void ispisi_predmete() {
    for (pred_kol* e = predmeti_head; e; e = e->next)
        fprintf(stdout, "%s\n", e->predmet);
}