cmake_minimum_required(VERSION 3.23)
project(Grade_Tracker C)

set(CMAKE_C_STANDARD 99)

add_executable(Grade_Tracker main.c predmeti.h predmeti.c boje.h smerovi.c smerovi.h studenti.c studenti.h predmeti_studenti.c predmeti_studenti.h provere.c provere.h)
