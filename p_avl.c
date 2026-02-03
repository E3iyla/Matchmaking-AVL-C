#include <stdlib.h>
#include <stdio.h>
#include "p_conteneur.h"
#include "p_joueur.h" 

// struture d'un noeud AVL
typedef struct s_noeud_avl{
    t_element l_etiquette;
    struct s_noeud_avl* la_gauche ;
    struct s_noeud_avl* la_droite;
    int la_hauteur;
}t_noeud_avl;

typedef t_noeud_avl* t_avl;

// creation d une nouvelle feuille
t_avl nouvelle_feuille_avl(t_element etiquette){
    t_avl res= (t_avl)malloc(sizeof(t_noeud_avl));
    if(res== NULL){
        exit(EXIT_FAILURE);
    }
    res-> l_etiquette= etiquette;
    res->la_gauche= NULL;
    res-> la_droite= NULL;
    res-> la_hauteur =0;
    return res;
}

// on recupere la hauteur d un noeud
int hauteur_avl(t_avl ceci){
    if(ceci == NULL){
        return -1;
    }
    return ceci->la_hauteur;
}

// pour trouver qui est le plus grand 
int max_2(int x, int y){
    if(x > y){
        return x;
    }else{
        return y;
    }
}

// recalculer la hauteur en fonction de ses fils 
void mettre_a_jour_hauteur_avl(t_avl ceci){
    if(ceci != NULL){
        ceci-> la_hauteur= max_2(hauteur_avl(ceci->la_gauche), hauteur_avl(ceci->la_droite)) + 1;
    }
}

// calculer le deséquilibre
int deseq(t_avl ceci){
    if(ceci == NULL){ 
        return 0;
    }
    return hauteur_avl(ceci->la_gauche) - hauteur_avl(ceci->la_droite);
}

// rotations droite
void rotation_droite_avl(t_avl* ceci){
    t_avl x = (*ceci)->la_gauche;
    (*ceci)->la_gauche = x->la_droite;
    x->la_droite = (*ceci);
    mettre_a_jour_hauteur_avl(*ceci);
    mettre_a_jour_hauteur_avl(x);
    *ceci = x;
}

// rotation gauche
void rotation_gauche_avl(t_avl* ceci){
    t_avl x = (*ceci)->la_droite;
    (*ceci)->la_droite = x->la_gauche;
    x->la_gauche = (*ceci);
    mettre_a_jour_hauteur_avl(*ceci);
    mettre_a_jour_hauteur_avl(x);
    *ceci = x;
}

// de gauche a droite
void rotation_gauche_droite_avl(t_avl* ceci){
    rotation_droite_avl(& ((*ceci)->la_droite));
    rotation_gauche_avl(ceci);
}

// de droite a gauche 
void rotation_droite_gauche_avl(t_avl* ceci){
    rotation_gauche_avl(&((*ceci)->la_gauche));
    rotation_droite_avl(ceci);
}

// choisis la bonne rotation si ça choisis a gauche 
void ramener_a_gauche(t_avl* ceci){
    if(deseq((*ceci)->la_droite) == -1){
        rotation_gauche_avl(ceci);
    }else{
        rotation_gauche_droite_avl(ceci);
    }
}

// choisis la bonne rotation si ça penche a droite 
void ramener_a_droite(t_avl* ceci){
    if(deseq((*ceci)->la_gauche) == 1){
        rotation_droite_avl(ceci);
    }else{
        rotation_droite_gauche_avl(ceci);
    }
}

// initialiser un arbre vide 
t_conteneur nouveau_conteneur(){
    return NULL;
}

void detruire_avl(t_avl ceci){
    if(ceci != NULL){
        detruire_avl(ceci-> la_gauche);
        detruire_avl(ceci-> la_droite);
        free(ceci);
    }
}

// Pour tout supprimer 
void finaliser_conteneur(t_conteneur* ceci){
    detruire_avl((t_avl)*ceci);
    *ceci = NULL;
}

void afficher_avl_infixe(t_avl ceci, int decalage){
    if(ceci != NULL){
        afficher_avl_infixe(ceci->la_gauche, decalage + 1); // Ordre croissant
        for(int i = 0; i < decalage; i++) printf("    ");
        afficher_joueur((t_joueur*)ceci->l_etiquette); 
        printf ("\n");
        afficher_avl_infixe( ceci-> la_droite, decalage+1);
    }
}

// fonction d'affichage
void afficher_conteneur(t_conteneur ceci){
    if(ceci == NULL){
        printf("Arbre vide\n");
    }else{
        afficher_avl_infixe((t_avl)ceci, 0);
    }
}

// inserer ceci et cela au bon endroit
void inserer_avl(t_avl* ceci, t_element cela){
    if(*ceci == NULL){
        *ceci= nouvelle_feuille_avl(cela);
    }else{
        if(est_inferieur_ou_egal_a(cela, (*ceci)->l_etiquette)){
            inserer_avl(&((*ceci) -> la_gauche), cela);
        }else{
            inserer_avl(&((*ceci)-> la_droite), cela);
        }
        mettre_a_jour_hauteur_avl(*ceci); 
        int d = deseq(*ceci);
        if(d > 1){
            ramener_a_droite(ceci);
        }
        if(d < -1){
            ramener_a_gauche(ceci);
        }
    }
}

// pour ajouter un joueur 
int ajouter_conteneur(t_conteneur* ceci, t_element cela){
    inserer_avl((t_avl*)ceci, cela);
    return 1;
}

// trouver et retirer le plus petit
void extraire_plus_petit_avl(t_avl* ceci, t_element* cela){
    if((*ceci)->la_gauche == NULL){
        t_avl tmp = *ceci;
        *cela= tmp->l_etiquette;
        *ceci= (*ceci)->la_droite;
        free(tmp);
    }else{
        extraire_plus_petit_avl(&((*ceci)->la_gauche), cela);
        mettre_a_jour_hauteur_avl(*ceci);
        if(deseq(*ceci) < -1){
            ramener_a_gauche(ceci);
        }
    }
}

// retirer un joueur
int retirer_conteneur(t_conteneur* ceci, t_element* cela){
    if(*ceci == NULL){
        return 0;
    }
    extraire_plus_petit_avl((t_avl*)ceci, cela);
    return 1;
}