#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#define N 1000000 // Nombre de tirages
// Fils écrivain : place des couples de nombres aléatoires dans le tube
// Paramètre d’entrée. d : le tableau des descripteurs du tube
void fils_ecr(int *d)
{
int i;
float x, y;
// Fermeture de l'extremite du tube dont ce fils ne se sert pas
close(d[0]);
for (i = 0; i < N; i++)
{
x = (float) random() / RAND_MAX;
write(d[1], &x, sizeof(float));
y = (float) random() / RAND_MAX;
write(d[1], &y, sizeof(float));
}
// Fermeture de l'extremite du tube dont ce fils ne se sert plus
close(d[1]);
// Le fils a fini son travail : il s'auto-détruit
exit(0);
}
// Fils lecteur : lit les couples déposés par le 1er fils et calcule pi
// Paramètre d’entrée. d : le tableau des descripteurs du tube
void fils_lect(int *d)
{
int i, M = 0;
float x, y, pi;
close(d[1]);
for (i = 0; i < N; i++)
{
read(d[0], &x, sizeof(float));
read(d[0], &y, sizeof(float));
if (x * x + y * y <= 1)
M++;
}
pi = 4.0 * M / N;
printf("Estimation de pi : %f\n", pi);
close(d[0]);
exit(0);
}

// Fonction principale
int main()
{
int d[2];
pid_t p;
// Creation du tube
if (pipe(d) == -1)
{
perror("TD8:pipe");
exit(1);
}
// Creation des deux fils
if ((p = fork()) == -1) // Test de la réussite de la primitive fork
{
perror("TD8:fork");
exit(2);
}
if (p == 0) fils_ecr(d); // Exécuté par le 1er fils ; les descripteurs du tube sont
// passés en paramètre(via le tableau d)
if ((p = fork()) == -1)
{
perror("TD8:fork");
exit(2);
}
if (p == 0) fils_lect(d); // Exécuté par le deuxième fils
// Attente par le père des deux fils pour éviter les zombies
wait(NULL); wait(NULL);
// Fermeture des extremites du tubes non utilisees par le pere
close(d[0]);
close(d[1]);
printf("Fin normale du programme\n");
// Renvoi d'un code de retour conforme à l'esprit... devinez !
exit(0);
}