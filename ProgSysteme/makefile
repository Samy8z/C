moyenne: principal.o entree.o affichage.o calcul.o
	gcc -o moyenne principal.o entree.o affichage.o calcul.o
principal.o: principal.c moyenne.h
	gcc -c principal.c
entree.o: entree.c
	gcc -c entree.c
affichage.o: affichage.c
	gcc -c affichage.c
calcul.o: calcul.c moyenne.h
	gcc -c calcul.c