#include "types.h"

void insertion_recursive(noeud **racine, int valeur);   //Création de l'arbre de maniere recursive
void grd(noeud *racine);    //Affiche tous les éléments de l'arbre selon un parcours Gauche Racine Droite
void rgd(noeud *racine);    //Affiche tous les éléments de l'arbre selon un parcours Racine Gauche Droite
void suppression(noeud **racine, int valeur);   //Supprime la valeur de l'arbre
void remplissage(noeud **racine, const char *nom);  //Remplit un arbre à l'aide des valeurs trouvées dans le fichier dont le nom est passé en paramètre
int supmax(noeud **racine);   //Fonction obscure
