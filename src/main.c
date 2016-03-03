#include <stdlib.h>
#include <stdio.h>

#define NBDISQUES 4
void hanoi(int nbPalets, int depart, int inter, int arrivee);

int main() {
    printf("Nombre de disques: %d\n", NBDISQUES);
    hanoi(NBDISQUES, 1, 2, 3);
	return 0;
}

void hanoi(int nbPalets, int depart, int inter, int arrivee) {
    if(nbPalets > 0) {
        hanoi(nbPalets - 1, depart, arrivee, inter);
        printf ("Deplacer le disque du plot %d vers le plot %d\n", depart, arrivee);
        hanoi(nbPalets - 1, inter, depart, arrivee);
    }
}
