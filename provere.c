//
// Created by mstojanovic2000 on 26.8.22..
//

#include "provere.h"

#include <string.h>

provera_znanja kreiraj_proveru_znanja(char predmet[], char naziv_provere[], int maksimalan_broj_poena) {
    provera_znanja provera;
    strcpy(provera.predmet, predmet);
    strcpy(provera.naziv_provere, naziv_provere);
    provera.maksimalan_broj_poena = maksimalan_broj_poena;
    return provera;
}
