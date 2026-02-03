#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "p_joueur.h"

//On va creer le nouveau joueur
t_joueur* nouveau_joueur(char* pseudo, int elo,int canal){
    t_joueur* player= (t_joueur*)malloc(sizeof(t_joueur));
    if(player == NULL) exit(EXIT_FAILURE);
    
    // Reservation de memoire pour stocker le pseudo
    player-> pseudo= (char*)malloc(sizeof(char)* (strlen(pseudo) + 1));
    if(player->pseudo == NULL) exit(EXIT_FAILURE);

    strcpy(player-> pseudo, pseudo); // copie du pseudo
    player-> elo= elo;
    player->canal= canal;
    // On ajoute l'heure actuelle
    player->arrivee = time(NULL);
    return player;
}

// afficher un joueur
void afficher_joueur(t_joueur* joueur){
    if(joueur != NULL){
        printf("Nom: %s Niveau: %d", joueur->pseudo, joueur->elo);
    }
}

// on va detruire (finaliser_element)
void finaliser_joueur(t_joueur* joueur){
    if(joueur != NULL){
        // Détruire d'abord le pseudo puis la structure
        free(joueur->pseudo);
        free(joueur);
    }
}

// comparrer deux joueurs (pour l'arbre AVL)
int est_inferieur_ou_egal_a(t_element player1, t_element player2){
    t_joueur* joueur_1= (t_joueur*) player1;
    t_joueur* joueur_2= (t_joueur*)player2;
    // Retourne VRAI si le joueur 1 est moins fort ou égal
    if(joueur_1-> elo <= joueur_2->elo) {
        return 1; 
    }else{
        return 0; 
    }
}

// Calcule le temps écoulé depuis l'enregistrement
double temps_ecoule_sec(t_joueur* joueur) {
    if (joueur == NULL) return 0.0;
    return difftime(time(NULL), joueur->arrivee);
}