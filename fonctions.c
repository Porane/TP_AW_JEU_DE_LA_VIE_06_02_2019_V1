#include "fonctions.h"

void initTab(int nTab [][TAILLE])
{
    int nX;
    int nY;

    for(nX = 0; nX < TAILLE; nX++){
        for(nY = 0; nY < TAILLE; nY++){
            nTab[nX][nY] = (rand() % 3) < 1;
        }
    }
}

int detectCases(int nTab[][TAILLE], int nPX, int nPY)
{
    int nbCases = 0;
    int nX;
    int nY;

    for(nX = nPX-1; nX <= nPX+1; nX++){
        for(nY = nPY-1; nY <= nPY+1; nY++){
            if (nX >= 0 && nY >= 0 && nX < TAILLE && nY < TAILLE) {
                nbCases = nbCases + nTab[nX][nY];
            }
        }
    }
    nbCases -= nTab[nPX][nPY];
    return nbCases;
}

void changEtat(int nTab[][TAILLE], FILE *log)
{
    int nbVoisins;
    int nX;
    int nY;
    int nTabVoisins[TAILLE][TAILLE];

    for(nX = 0; nX < TAILLE; nX++){
        for(nY = 0; nY < TAILLE; nY++){
            nTabVoisins[nX][nY] = detectCases(nTab, nX, nY);
        }
    }
    for(nX = 0; nX < TAILLE; nX++){
        for(nY = 0; nY < TAILLE; nY++){
            nbVoisins = nTabVoisins[nX][nY];
            if (nTab[nX][nY] == 1) {
                if(nbVoisins < 2 || nbVoisins > 3){
                    nTab[nX][nY] = 0;
                    fprintf(log, "Une cellule meurt en %d, %d...\n", nX, nY);
                }
            } else {
                if(nbVoisins == 3){
                    nTab[nX][nY] = 1;
                    fprintf(log, "Une cellule nait en %d, %d !\n", nX, nY);
                }
            }
        }
    }
}

void affichage(int nTab[][TAILLE])
{
    int nX;
    int nY;

    for(nX = 0; nX < TAILLE; nX++){
        for(nY = 0; nY < TAILLE; nY++)
            printf("%c", nTab[nX][nY] ? 'X' : '_');
        printf("\n");
    }
}
