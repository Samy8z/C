#include<stdio.h>

int DivisionEuclidienne(int dividende,int diviseur, int *quotient,in *reste)
{
    if(diviseur == 0)
        return 0;
    else 
    {
        *quotient = dividende / diviseur; // division entière
        *reste = dividende % diviseur; // % = calcul reste
        return 1;
    }
}

main()
{
    int divid, divis, q, r;
    printf("Saisir le dividende\n");
    scanf("%d", &divid);
    printf("Saisir le diviseur\n");
    scanf("%d", &divis);

    if(DivisionEuclidienne(divid, divis, &q, &r) == 0)
        printf("Division impossible !\n");
    else
        printf("Quotient=%d, reste=%d\n", q, r);


}