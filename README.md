#Système de matchmaking ELO-Temps 

##1. Objectif du Projet
Ce projet implémente une librairie en C pour gérer des participants dans une structure d'arbre qui s'équilibre automatiquement. 
Elle permet d'organiser les joueurs par niveau ELO et à prendre en compte le temps d'attente pour la formation des matchs.

## Caractéristiques Techniques
* Algorithmique : Utilisation d'un arbre AVL pour un tri automatique par ELO croissant et une recherche rapide.
* Architecture Modulaire: Séparation du code en 3 modules pour respecter le principe d'encapsulation (Joueur, Conteneur AVL, et Scénario de test).
* Gestion Mémoire : Utilisation rigoureuse de l'allocation dynamique (`malloc` et `free`) pour éviter toute fuite de mémoire.

##Structure du Projet
Pour utiliser ce code, veuillez en premier lieu vérifier les fichiers sources.
Le projet est composé de 6 fichiers principaux :
	- p_joueur.h
	- p_joueur.c
	- p_conteneur.h
	- p_avl.c
 	- sc_joueur.c
	- makefile

2. Compilation et construction de l'exécutable
	- Pour compiler le projet et le créer, utilisez la commande make. 
	- Puis utiliser ./matchmaking_avl.exe pour executer.
	- Une fois compilé vous aurez l'affichage des résultats! 
    - Vous pouvez modifier ou ajouter des joueurs si vous le souhaitez dans  sc_joueur.c .
 
