#include "node.h"

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>


// print a board
void printItem(Item *node)
{
    assert(node);
    afficher_terrain(node->T);
    printf("le choix : %d\n", node->choix);
    if( node->choix == 0 ){
        printf("l'attaque choisie: ");
        afficher_attaque(node->AT);
    }
    else if( node->choix == 1 ){
        printf("le pokemon choisie : %s ", node->poke.nom);
    }
        
}

// initialise un node avec un terrain donné
void initNode(Item *node, terrain T)
{
    assert(node);
    node->T=T;
}

/* -------------PARTIE CALCUL DE L'HEURISTIC -------------------*/

//f sera egal au nombre de pv de la team adverse -> plus f est petit mieux est le coup
double get_heuristic(Item *node){
    double f=0;
    int i,j;
        for(i=0;i<node->T.J1.nb_vivant;i++){
                f = f + (node->T.J1.liste_pokemon[i].stat.PV);
        }
        for(j=0;j<node->T.J2.nb_vivant;j++){
                f = f - (node->T.J2.liste_pokemon[j].stat.PV);
        }
    return f;
}
 
pokemon best_switch_ia(terrain T){
    int i;
    for(i=1; i<T.J2.nb_vivant;i++){
        if(calcul_multiplicateur(T.J2.liste_pokemon[i].type,T.J1.liste_pokemon[0].type) >1){
            return T.J2.liste_pokemon[i];
        }
    }
    for(i=0; i<T.J2.nb_vivant;i++){
        for(int j=0;j <T.J2.liste_pokemon[i].nb_attaque;j++){
            if(calcul_multiplicateur(T.J2.liste_pokemon[i].attaque[j].type,T.J1.liste_pokemon[0].type) >1){
                return T.J2.liste_pokemon[i];
            }
        }
    }
}

/* -------------PARTIE  -------------------*/

terrain deroulement_tour_att(terrain T,int joueur, attaques att, int tour){
    // pokemon poke1, poke2;
    //si tour de J1
    if(joueur==1){
        int touch = toucher(T.J1.liste_pokemon[0], att);
        if(touch==0){
            T.toucher=0;
        }
        //l'attaque a reussi
        else if(touch==1){
            T.toucher=1;
            T = applique_attaque(T,1,att,tour);
        }
        //le pokemon se blesse dans sa confusion
        else if(touch==2){
            T.toucher=2;
            T.J1.liste_pokemon[0] = applique_confusion(T,T.J1.liste_pokemon[0],att);
        }
        T.J1.liste_pokemon[0]=gestion_statut(T.J1.liste_pokemon[0], tour - T.J1.liste_pokemon[0].tour_etat);
        T = gestion_meteo(T,1, tour - T.tour_meteo);
    }
    //si tour de J2
    else if(joueur ==2){
        int touch = toucher(T.J2.liste_pokemon[0], att);
        if(touch==0){
            T.toucher=0;
        }
        //l'attaque a reussi
        else if(touch==1){
            T.toucher=1;
            T = applique_attaque(T,2,att,tour);
        }
        //le pokemon se blesse dans sa confusion
        else if(touch==2){
            T.toucher=2;
            T.J2.liste_pokemon[0] = applique_confusion(T,T.J2.liste_pokemon[0],att);
        }
        T.J2.liste_pokemon[0]=gestion_statut(T.J2.liste_pokemon[0], tour - T.J2.liste_pokemon[0].tour_etat);
        T = gestion_meteo(T,2, tour - T.tour_meteo);
    }
    // //-----------gestion des morts--------------//
    // if(mort(T.J1.liste_pokemon[0]) && T.J1.nb_vivant>1){
    //             //on retire le pokemon mort de l'equipe
    //             T = enlever_pokemon_equipe(T, 1,T.J1.liste_pokemon[0]);
    //             //on en choisie un nouveau
    //             poke1 = choix_switch_ia_random(T,1);
    //             T = switch_pokemon(T, 1, poke1);
    //         }
    // //dans ce cas c'est le dernier pokemon qui viens de mourir
    // else if (mort(T.J1.liste_pokemon[0]) && T.J1.nb_vivant <=1 ){
    //     //on met le nb de vivant a 0 pour que la partie se termine
    //     T.J1.nb_vivant=0;
    // }
    // if(mort(T.J2.liste_pokemon[0]) && T.J2.nb_vivant>1){
    //     T=enlever_pokemon_equipe(T,2,T.J2.liste_pokemon[0]);
    //     poke2 = choix_switch_ia_random(T,2);
    //     T = switch_pokemon(T, 2, poke2);
    // }
    // else if (mort(T.J2.liste_pokemon[0]) && T.J2.nb_vivant <=1 ){
    //     T.J2.nb_vivant=0;
    // }
    return T;
}

terrain deroulement_tour_swt(terrain T,int joueur, pokemon poke){
    if(joueur == 1){
        T = switch_pokemon(T,1,poke);
    }
    else{
        T = switch_pokemon(T,2,poke);
    }
    return T;
}


Item *get_child_att(Item *node, attaques att,int joueur, int tour){
    Item *new_node = nodeAlloc();
    initNode(new_node, node->T);

    new_node->choix= 0;
    new_node->AT=att;

    new_node->T = deroulement_tour_att(new_node->T,joueur, att, tour);
    new_node->toucher= new_node->T.toucher;

    new_node->parent = node;
    new_node->depth = node->depth + 1;

    new_node->f=get_heuristic(new_node);

    return new_node;
}

Item *get_child_swt(Item *node, pokemon poke,int joueur){
    Item *new_node = nodeAlloc();
    initNode(new_node, node->T);

    new_node->choix= 1;
    new_node->poke = poke;

    new_node->T = deroulement_tour_swt(new_node->T, joueur,poke);

    new_node->parent = node;
    new_node->depth = node->depth + 1;

    new_node->f=get_heuristic(new_node);

    return new_node;
}

