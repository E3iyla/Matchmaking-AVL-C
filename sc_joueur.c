#include <stdio.h>
#include <stdlib.h> 
#include "p_joueur.h"
#include "p_conteneur.h"

int main(){
    printf("-------------------------------------------------\n");
    printf("       MATCHMAKING PAR ARBRE AVL\n");
    printf("-------------------------------------------------\n\n");

    // On crée l'arbre 
    t_conteneur mon_arbre = nouveau_conteneur();

    // Création des joueurs
    t_joueur* j1 = nouveau_joueur("Leia Organa", 1200, 1);
    t_joueur* j2 = nouveau_joueur("Obi-Wan Kenobi", 2000, 1);
    t_joueur* j3 = nouveau_joueur("C-3PO", 500, 1);
    t_joueur* j4 = nouveau_joueur("Yoda", 2500, 1);
    t_joueur* j5 = nouveau_joueur("Luke Skywalker", 800, 1); 

    // On les met dans l'arbre 
    ajouter_conteneur(&mon_arbre, j1);
    ajouter_conteneur(&mon_arbre, j2);
    ajouter_conteneur(&mon_arbre, j3);
    ajouter_conteneur(&mon_arbre, j4);
    ajouter_conteneur(&mon_arbre, j5);

    // Affichage de la file
    printf("--- File d'attente (triee par ELO) ---\n");
    afficher_conteneur(mon_arbre);
    printf("--------------------------------------\n");

    // Retrait des deux joueurs avec l'ELO le plus faible
    t_element joueur_A_element = NULL;
    t_element joueur_B_element = NULL;

    printf("\n>>> Resultat du Matchmaking <<<\n");
    
    // Retrait du premier joueur (le plus faible ELO)
    if (retirer_conteneur(&mon_arbre, &joueur_A_element)) {
        t_joueur* jA = (t_joueur*)joueur_A_element;
        
        // Retrait du deuxième joueur
        if(retirer_conteneur(&mon_arbre, &joueur_B_element)) {
            t_joueur* jB = (t_joueur*)joueur_B_element;
            
            // Affichage des résultats du match
            printf("Match trouve entre :\n");
            printf("  Joueur A : "); afficher_joueur(jA); printf(" | Attente: %.0f sec\n", temps_ecoule_sec(jA));
            printf("  Joueur B : "); afficher_joueur(jB); printf(" | Attente: %.0f sec\n", temps_ecoule_sec(jB));
            
            // Nettoyage des joueurs retirés
            finaliser_joueur(jA);
            finaliser_joueur(jB);

        }else{
            printf("-> Pas assez de joueurs pour faire un match.\n");
            finaliser_joueur(jA);
        }
    }else{
        printf("-> Arbre vide, pas de match possible.\n");
    }

    printf("\nJoueurs restant en file\n");
    afficher_conteneur(mon_arbre);
    printf("--------------------------------------\n");
    
    // Free la mémoire
    finaliser_conteneur(&mon_arbre);
    
    printf("\nProgramme termine.\n");
    return 0;
}




