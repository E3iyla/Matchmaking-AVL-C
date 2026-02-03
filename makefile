opt= -c -Wall -Wextra -std=gnu11

matchmaking_avl.exe : sc_joueur.o p_joueur.o p_avl.o
	gcc -o matchmaking_avl.exe sc_joueur.o p_joueur.o p_avl.o

sc_joueur.o: sc_joueur.c p_joueur.h p_conteneur.h
	gcc ${opt} sc_joueur.c

p_joueur.o : p_joueur.c p_joueur.h
	gcc ${opt} p_joueur.c

p_avl.o: p_avl.c p_conteneur.h p_joueur.h
	gcc ${opt} p_avl.c

all : matchmaking_avl.exe

clean :
	rm *.o
	rm *.exe