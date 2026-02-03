#ifndef P_CONTENEUR_H
#define P_CONTENEUR_H

#include "p_joueur.h" 

// On définit le Conteneur (l'arbre) comme une boite générique
typedef void* t_conteneur;

//Les fonctions du conteneur
t_conteneur nouveau_conteneur();
void finaliser_conteneur(t_conteneur* ceci);
void afficher_conteneur(t_conteneur ceci);
int ajouter_conteneur(t_conteneur* ceci, t_element cela);
int retirer_conteneur(t_conteneur* ceci, t_element* cela);

#endif