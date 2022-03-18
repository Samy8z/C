#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <grp.h>
#include <pwd.h>
#include <time.h>
#include <unistd.h>
int main(int argn, char *argv[])
{
struct stat buf;
struct passwd *usrbuf;
struct group *grbuf;
DIR *cata;
struct dirent *couple;

if (argn != 2)
{
fprintf(stderr, "my_ls: argument requis\n");
exit(1);
}

if ((cata = opendir(argv[1])) == NULL)
{
perror("my_ls:opendir");
exit(2);
}

chdir(argv[1]);

while ((couple = readdir(cata)) != NULL)
{

stat(couple->d_name, &buf);
printf("Fichier etudie: %s\n", couple->d_name);
printf("Numero de i-noeud: %d\n", (int)buf.st_ino);
printf("Nombre de liens : %ld\n", buf.st_nlink);

if ((usrbuf = getpwuid(buf.st_uid)) == NULL)
{
perror("my_ls: getpwuid");
exit(4);
}
printf("Proprietaire : %d (%s)\n", buf.st_uid,
usrbuf->pw_name);

if ((grbuf = getgrgid(buf.st_gid)) == NULL)
{
perror("my_ls: getgrgid");
exit(5);
}
printf("Groupe : %d (%s)\n", buf.st_gid,
grbuf->gr_name);
printf("Taille : %d\n", (int)buf.st_size);
printf("Derniere modif du i-noeud: %s", ctime(&buf.st_ctime));
printf("Derniere modif du fichier: %s", ctime(&buf.st_mtime));
printf("Dernier acces : %s\n", ctime(&buf.st_atime));
}
closedir(cata);
exit(0);
}