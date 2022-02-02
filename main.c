#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

void viderBuffer(void)
{
  int c;
  while((c=getchar()) != EOF && c != '\n');

}

//Exercice 1.A (Renvoie 1 si nombre est premier, 0 sinon)
int premier(int nombre)
{
    int i ;
    if (nombre % 2 == 0 || nombre == 1)
        return 0 ;
    for (i=3 ; i<(nombre/2) ; i+=2)
    {
        if (nombre % i == 0)
            return 0 ;
    }
    return 1 ;
}
/*
//Exercie 1.B (Nombres premiers jusqu'à n)
void premier_inf_n(int n)
{
    int i, l = 0 ;
    char c ;
    for (i=2 ; i<n ; i++)
    {
        if (premier(i))
        {
            printf("%i, ",i) ;
            l++ ;
            if (l % 25 == 0)
            {
                printf("\n Appuyez sur entrée pour afficher la page suivante \n");
                viderBuffer() ;
                scanf("%c",&c) ;
            }
        }
    }
}

//Exercice 1.C (n premiers nombres premiers)
void premier_n(int n)
{
    int i = 2, k = 0 ;
    char c ;
    while (k < n)
    {
        if (premier(i))
        {
            printf("%i, ",i) ;
            k+=1 ;
            if (k % 25 == 0)
            {
                printf("\n Appuyez sur entr�e pour afficher la page suivante \n");
                viderBuffer() ;
                scanf("%c",&c) ;
            }
        }
        i+=1 ;
    }
}

//Exercice 2.A (Fonction nombres parfait)
int parfait(int nombre){
        int i = 2 , k = 1 ;
    while (i <= sqrt(nombre)) {
        if (nombre % i == 0){
        if (i==nombre/i)
            k+=i;
        else
            k+=i+nombre/i ;

        }
        i++ ;
    }
    //printf("%d\n",k);//
    if (nombre == k) return 1 ;
    else return 0 ;
}

//Exercice 2.D

int parfait2(int nombre,int *retour){
        int i = 2 , k = 1 ;
    while (i <= sqrt(nombre)) {
        if (nombre % i == 0){
        if (i==nombre/i)
            k+=i;
        else
            k+=i+nombre/i ;

        }
    i++ ;
}
    printf("k=%d %d\n",k,nombre);

    if (nombre == k)
        *retour = 1 ;
    else
    *retour = 0 ;
}

//Exercice 2.B
void parfait_inf_n(int n)
{
    int i, l = 0 ;
    char c ;
    for (i=2 ; i<n ; i++)
    {
        if (parfait(i))
        {
            printf("%i, ",i) ;
            l++ ;
            if (l % 25 == 0)
            {
                printf("\n Appuyez sur entr�e pour afficher la page suivante \n");
                viderBuffer() ;
                scanf("%c",&c) ;
            }
        }
    }
}

//Exercice 2.c
void parfait_n(int n)
{
    int i = 2, k = 0 ;
    char c ;
    while (k < n)
    {
        if (parfait(i))
        {
            printf("%i, ",i) ;
            k+=1 ;
            if (k % 25 == 0)
            {
                printf("\n Appuyez sur entr�e pour afficher la page suivante \n");
                viderBuffer() ;
                scanf("%c",&c) ;
            }
        }




        i+=1 ;
    }
}

/*
void main()
{
    int x, retour ;
    printf("Entrez un nombre : ") ;
    scanf("%d",&x) ;
    retour=parfait(x);
    printf("%d",retour);
}

void main()
{
    int x, retour;
    printf("Entrez un nombre : ") ;
    scanf("%d",&x) ;
    parfait2(x,&retour);
    printf("%d",retour);
}
*/