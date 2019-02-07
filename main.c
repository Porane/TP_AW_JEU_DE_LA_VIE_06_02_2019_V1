#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fonctions.h"

int main()
//BUT : faire un jeu de la vie 
//ENTREE : le nombre de cycles entre par l'utilisateur
//SORTIES : chaque generation du jeu de la vie
{
    int nCpt;
    int nCycles;
    int nTab[TAILLE][TAILLE];
    FILE *log = NULL;

    log = fopen("log.txt", "a");

    printf("Bienvenue dans le jeu de la vie, veuillez rentrer le nombre de cycles : ");
    scanf("%d", &nCycles);
    initTab(nTab);

    printf("Voici la generation mere : \n");
    affichage(nTab);

    printf("Appuyez sur entree pour passer a la generation suivante...\n");
    getchar();

    srand(time(NULL));
    for(nCpt = 0; nCpt < nCycles; nCpt++){
        fprintf(log, "Generation %d : \n", nCpt);
        changEtat(nTab, log);

        printf("Voici la generation %d ! \n", nCpt+1);
        affichage(nTab);

        printf("Appuyez sur entree pour passer a la generation suivante...\n");
        getchar();
    }

    fclose(log);

    return 0;
}
