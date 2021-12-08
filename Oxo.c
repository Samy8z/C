#include<stdio.h> 
#include<stdlib.h>

int impotOxo(int age, char sexe)
{
    int imposable;
    if(sexe == 'M' && age >= 20 || sexe == 'F' && 18 < age && age < 35)
        imposable = 1;
    else
        imposable = 0;

        return imposable;
}

int main()
{
    int age;
    char sexe;
    printf("Saisir un age\n");
    scanf("%d",&age);
    printf("Saisir un sexe (M,F,...)\n");
    scanf("%c",&sexe);

    if(sexe == 'M' && age >= 20 || sexe == 'F' && 18 < age && age < 35)
        printf("Imposable\n");
    else
        printf("non imposable\n");
}