#include<stdio.h>
#include<stdlib.h>


int main(){
    int a, n, res = 1;

    printf("Saisir a\n");
    scanf("%d",&a);
    printf("Saisir n\n");
    scanf("%d",&n);

    for(int i = 0; i < n; i++)
        res = res * a;

    printf("La puissance vaut %d\n", res);
    return 0;
}