#include<stdio.h>
#include<stdlib.h>

int puissance(int nb, int puiss)
{
    int resultat = 1;

    for(int i = 0; i < puiss; i++)
        resultat = resultat * nb;

    return resultat;
}

int main(){
    int a, n;

    printf("Saisir a\n");
    scanf("%d",&a);
    printf("Saisir n\n");
    scanf("%d",&n);
    printf("La puissance vaut %d\n", puissance(a,n));
    return 0;
}

// Ctrl + Shift + B to compile with GNU