#ifndef P_JOUEUR_H
#define P_JOUEUR_H

#include <time.h> // Pour gerer l'heure
typedef void* t_element;

// Structure d'un joueur
typedef struct{
    char* pseudo;    
    int elo;// Le niveau 
    int canal;       
    time_t arrivee;  // L'heure d'arrivée
}t_joueur ;

// Pour créer un joueur
t_joueur* nouveau_joueur(char* pseudo, int elo, int canal);

// Pour supprimer un joueur + nettoyer la mémoire
void finaliser_joueur(t_joueur* joueur);

// Pour afficher un joueur
void afficher_joueur(t_joueur* joueur);

// Pour comparer deux joueurs (par rapport au ELO)
int est_inferieur_ou_egal_a(t_element j1, t_element j2);

// Calcule le temps d'attente en secondes
double temps_ecoule_sec(t_joueur* joueur);
#endif