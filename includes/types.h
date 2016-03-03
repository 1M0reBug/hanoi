#ifndef TYPES_H
#define TYPES_H

typedef struct _noeud noeud ;

struct _noeud{
	int valeur;
	noeud* gauche;
	noeud* droit;
};

typedef enum {false, true} bool;

#endif //TYPE_H
