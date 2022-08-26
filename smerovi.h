//
// Created by mstojanovic2000 on 26.8.22..
//

#ifndef GRADE_TRACKER_SMEROVI_H
#define GRADE_TRACKER_SMEROVI_H

typedef enum {
    RN, RI
} smer;

char* smer_to_string(smer smer);
smer string_to_smer(char *naziv);

#endif //GRADE_TRACKER_SMEROVI_H
