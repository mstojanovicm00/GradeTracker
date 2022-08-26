//
// Created by mstojanovic2000 on 26.8.22..
//

#ifndef GRADE_TRACKER_PROVERE_H
#define GRADE_TRACKER_PROVERE_H

typedef struct {
    char predmet[100];
    char naziv_provere[30];
    int maksimalan_broj_poena;
} provera_znanja;

provera_znanja kreiraj_proveru_znanja(char predmet[], char naziv_provere[], int maksimalan_broj_poena);

#endif //GRADE_TRACKER_PROVERE_H
