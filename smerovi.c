//
// Created by mstojanovic2000 on 26.8.22..
//

#include "smerovi.h"

#include <string.h>

#define BROJ_SMEROVA 2
char* smerovi[] = {
        "RN", "RI"
};

char* smer_to_string(smer smer) {
    return smerovi[smer];
}

smer string_to_smer(char *naziv) {
    for (int i = 0; i < BROJ_SMEROVA; ++i) {
        if (!strcmp(naziv, smerovi[i]))
            return i;
    }
    return -1;
}