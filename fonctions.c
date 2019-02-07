#include "fonctions.h"

void initTab(int nTab [][TAILLE])
//BUT : initialisation du tableau
//ENTREES : le tableau
//SORTIES : le tableau initialise
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
//BUT : detecter l'etat d'une case
//ENTREES : le tableau et 2 entiers
//SORTIES : la detection de l'etat de cette case
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
//BUT : changer l'etat d'une case et le notifier dans un fichier txt
//ENTREES : le tableau et un fichier txt
//SORTIES : l'etat de la case changee et sa notification dans le fichier txt
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
//BUT : afficher le tableau
//ENTREES : le tableau
//SORTIES : l'affichage du tableau
{
    int nX;
    int nY;

    for(nX = 0; nX < TAILLE; nX++){
        for(nY = 0; nY < TAILLE; nY++)
            printf("%c", nTab[nX][nY] ? 'X' : '_');
        printf("\n");
    }
}
