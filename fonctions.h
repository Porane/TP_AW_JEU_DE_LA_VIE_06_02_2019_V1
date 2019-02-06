#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAILLE 15

/* PROTOTYPES */

extern void initTab(int nTab[][TAILLE]);
extern int detectCases(int nTab[][TAILLE], int nX, int nY);
extern void changEtat(int nTab[][TAILLE], FILE *log);
extern void affichage(int nTab[][TAILLE]);

#endif // FONCTIONS_H_INCLUDED
