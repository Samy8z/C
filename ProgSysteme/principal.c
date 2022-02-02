#include <stdio.h>
#include <stdlib.h>
#include "moyenne.h"

/* prototype des fonctions externes */
float saisie(void);
float total(float,float);
void affiche(float);

int main(void) 
{ 
 float valeur=0,chiffre;
 int i;  

 printf("Nombre de valeurs : %d\n", NBREVALEUR);

 for(i=0;i<NBREVALEUR;i++) 
 { 
     /* saisie() a définir dans entree.c */ 
     chiffre=saisie();  

     /* total()  a définir dans calcul.c */
     valeur=total(valeur,chiffre);
 }

 /* affiche() a définir dans affichage.c */
 affiche(valeur);
 exit(0);
}