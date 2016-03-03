/**
  * Quagliatini Jordan + ROGAI Rayan
  * Description: Parcours d'arbre binaire (GRD et RGD)
  *
*/
#include <stdlib.h>
#include <stdio.h>
#include "types.h"
#include "functions.h"

int main(){
	noeud *racine = NULL;

	/* remplissage de l'arbre*/
	insertion_recursive(&racine, 15);
	insertion_recursive(&racine, 25);
	insertion_recursive(&racine, 10);
	insertion_recursive(&racine, 5);
	insertion_recursive(&racine, 1);
	insertion_recursive(&racine, 6);
	insertion_recursive(&racine, 12);
	insertion_recursive(&racine, 11);
	insertion_recursive(&racine, 13);
	insertion_recursive(&racine, 20);
	insertion_recursive(&racine, 33);
	insertion_recursive(&racine, 17);
	insertion_recursive(&racine, 22);
	insertion_recursive(&racine, 27);
	insertion_recursive(&racine, 34);

	printf("Racine : %d, gauche : %d, gauche-gauche : %d, droit : %d \n", racine->valeur, racine->gauche->valeur, racine->gauche->gauche->valeur, racine->droit->valeur );

	printf("\n------------ GRD -------------- \n");
	grd(racine);
	printf("\n------------------------------- \n");

	printf("\n------------ RGD -------------- \n");
	rgd(racine);
	printf("\n------------------------------- \n");

	printf("\n----- Supression(15) RGD ------ \n");
	suppression(&racine, 15);
	rgd(racine);
	printf("\n------------------------------- \n\n");

	printf("Racine : %d, gauche : %d, gauche-gauche : %d, droit : %d \n", racine->valeur, racine->gauche->valeur, racine->gauche->gauche->valeur, racine->droit->valeur );

	printf("\n\nlecture de file.txt\n");

    noeud* fromFile = NULL;
    remplissage(&fromFile, "file.txt");
    rgd(fromFile);

    printf("\n");

    supprime_arbre(&fromFile);
    supprime_arbre(&racine);

    printf("fromFile : %d\n", fromFile);
    printf("racine : %d\n", racine);


	return 0;
}
