#include "types.h"
#include "functions.h"
#include <stdio.h>
#include <stdlib.h>


/**
  * @author Jordan QUAGLIATINI, Rayan ROGAÏ
  * @date 03/003/2016
  * Ce fichier regroupe l'ensemble des fonctions de manipulation
  * d'arbre binaire
  */


void insertion_recursive(noeud **racine, int valeur){
	if(*racine){
		if(valeur > (*racine)->valeur){
			insertion_recursive(& ((*racine)->droit),valeur);
		}	else{
		  insertion_recursive(& ((*racine)->gauche),valeur);
		}
	} else {
			(*racine) = malloc(sizeof(noeud));
			(*racine)->valeur = valeur;
			(*racine)->gauche = NULL;
			(*racine)->droit = NULL;
		}
}

void grd(noeud *racine){

  if(racine->gauche){
    grd(racine->gauche);
  }

  printf("%d ", racine->valeur);

  if(racine->droit){
    grd(racine->droit);
  }
}

void rgd(noeud *racine){

  printf("%d ", racine->valeur);

  if(racine->gauche)
    rgd(racine->gauche);

  if(racine->droit)
    rgd(racine->droit);
}

void suppression(noeud **racine, int valeur){
  noeud *courant = *racine;

  if(courant) {
    if(valeur < courant->valeur){
      suppression(&(courant->gauche), valeur);
    }else {
      if(valeur > courant->valeur) {
        suppression(&(courant->droit), valeur);
      } else {
        if(!courant->gauche) {
          courant = courant->droit;
        } else {
          if(!courant->droit) {
            courant = courant->gauche;
          } else {
            courant->valeur = supmax(&(courant->gauche));
          }
        }
      }
    }
  }
}

int supmax(noeud **racine){
  if((*racine)->droit)
    return supmax(&((*racine)->droit));

  int max = (*racine)->valeur;
  noeud** oldRacine = racine;
  (*racine) = (*racine)->gauche;
  free(*oldRacine);
  return max;

}

void insertion_iterative(noeud** racine, int valeur) {
  while(*racine) {
    if(valeur > (*racine)->valeur) {
      *racine = (*racine)->gauche;
    } else if(valeur < (*racine)->valeur) {
      *racine = (*racine)->droit;
    }
  }

  (*racine) = malloc(sizeof(noeud));
  (*racine)->valeur = valeur;
  (*racine)->gauche = NULL;
  (*racine)->droit = NULL;
}

void remplissage(noeud **racine, const char *nom){

    FILE* file = fopen(nom, "r");
    int line = 0;
    while(!feof(file)) {
        fscanf(nom, "%d", &line);
        insertion_recursive(racine, line);
    }
    fclose(file);
}
