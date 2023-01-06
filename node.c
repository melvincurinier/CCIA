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
    printf("----------Equipe Player 1----------\n");
    afficher_equipe(node->T->player1);
    printf("----------Equipe Player 2----------\n");
    afficher_equipe(node->T->player2);
}

// initialise un node avec un terrain donné
void initNode(Item *node, terrain *T)
{
    assert(node);
    node->T=T;
}

//retourne le nombre de pokemon vivant dans l'équipe du player 1
int evaluateNode(Item *node)
{   
  return node->T->player1->nb_vivant;
}

terrain copy_terrain(terrain *T){
    terrain T2;
    T2.meteo=T->meteo;
    T2.player1=T->player1;
    T2.player2=T->player2;
    T2.pokeJ1=T->pokeJ1;
    T2.pokeJ2=T->pokeJ2;
    T->tour_meteo=T->tour_meteo;
    return T2;
}

terrain evalue_attaque(terrain T,pokemon poke_attaquant, pokemon poke_defensive, attaques att, int tour){
        int degats;
        terrain T2;
        int touche = toucher(poke_attaquant,att);
        if(touche == 0){
            return;
        }
        else if(touche == 1){
            /*--------------cas d'une attaque normal----------------*/
            if(att.application == 0){
                degats = calcul_pv_perdu(&T,poke_attaquant,poke_defensive,att);
                poke_defensive.stat.PV = poke_defensive.stat.PV - degats;
            }
            /*--------------cas d'une attaque de changement de statut ----------------*/
            else if(att.application == 1){
                if(poke_defensive.etat == neutre){
                    switch (att.effet) {
                        case paraliser :
                            applique_paralisie(&poke_defensive);
                            break;
                        case empoisoner:
                            poke_defensive.etat=empoisoner;
                            break;
                        case endormie:
                            poke_defensive.etat = endormie;
                            poke_defensive.tour_etat=tour;
                            break;
                        case brulure:
                            poke_defensive.etat = brulure;
                            break;
                        case confusion:
                            poke_defensive.etat = confusion;
                            poke_defensive.tour_etat=tour;
                            break;
                        case geler:
                            poke_defensive.etat = geler;
                            break;
                        default:
                            break;
                    }
                }
                else{
                    return;
                }
            }
            /*--------------cas d'une attaque qui boost une ou plusieurs stats---------*/
            else if(att.application == 2){
                applique_boost(&poke_attaquant,att);
            }
            /*--------------cas d'une attaque qui nerf une ou plusieurs stats---------*/
            else if(att.application == 3){
                applique_nerf(&poke_defensive,att);
            }
            /*--------------cas d'une attaque qui change la meteo---------*/
            else if(att.application == 4){
                switch (att.Meteo) {
                        case pluie :
                            T.meteo=pluie;
                            T.tour_meteo=tour;
                            break;
                        case soleil:
                            T.meteo=soleil;
                            T.tour_meteo=tour;
                            break;
                        case tempete:
                            T.meteo=tempete;
                            T.tour_meteo=tour;
                            break;
                        case grele:
                            T.meteo=grele;
                            T.tour_meteo=tour;
                            break;
                        default:
                            break;
                    }
            }
            
        }
        else if(touche == 2){
            applique_confusion(&T,&poke_attaquant,att);
        }
    return T;
}



void deroulement_tour_att_att(terrain *T, attaques att1, attaques att2, int tour){
  terrain T2 = copy_terrain(T);
    // si le premier pokemon est plus rapide que le deuxieme
    if(attaque_priorite(T->pokeJ1,T->pokeJ2)){
        T2 = evalue_attaque(T2,T2.pokeJ1,T2.pokeJ2,att1,tour);
        if(!mort(T->pokeJ2)){
            applique_attaque(T,T->pokeJ2,T->pokeJ1,att2,tour);
        }
    }
    //si le J2 joue en premier
    else{
        applique_attaque(T,T->pokeJ2,T->pokeJ1,att2,tour);
        if(!mort(T->pokeJ1)){
            applique_attaque(T,T->pokeJ1,T->pokeJ2,att1,tour);
        }
    }
//----------------------- Gestion des statut ---------------------------//
    gestion_statut(T->pokeJ1, tour - T->pokeJ1->tour_etat);
    gestion_statut(T->pokeJ2, tour - T->pokeJ2->tour_etat);
//----------------------- Gestion de la meteo ---------------------------//
    gestion_meteo(T,tour - T->tour_meteo);
    tour++;
}

void deroulement_tour_att_swt(terrain *T,attaques att, pokemon *poke, int tour){
  // si le J1 attaque et le J2 switch
  switch_pokemon(T,poke,2);
  applique_attaque(T,T->pokeJ1,T->pokeJ2,att, tour);
  gestion_statut(T->pokeJ1, tour - T->pokeJ1->tour_etat);
  gestion_statut(T->pokeJ2, tour - T->pokeJ2->tour_etat);
  gestion_meteo(T,tour - T->tour_meteo);
  tour++;
}

void deroulement_tour_swt_att(terrain *T, attaques att, pokemon *poke, int tour){
  switch_pokemon(T,poke,1);
  applique_attaque(T,T->pokeJ2,T->pokeJ1,att, tour);
  gestion_statut(T->pokeJ1, tour - T->pokeJ1->tour_etat);
  gestion_statut(T->pokeJ2, tour - T->pokeJ2->tour_etat);
  gestion_meteo(T,tour - T->tour_meteo);
  tour++;
}

void deroulement_tour_swt_swt(terrain *T, pokemon *poke1, pokemon *poke2, int tour){
  switch_pokemon(T,poke1,1);
  switch_pokemon(T,poke2,2);
  gestion_statut(T->pokeJ1, tour - T->pokeJ1->tour_etat);
  gestion_statut(T->pokeJ2, tour - T->pokeJ2->tour_etat);
  gestion_meteo(T,tour - T->tour_meteo);
  tour++;
}

// retourn un nouvelle item avec attaque du J2 et du J1
Item *getChildNode_att_att(Item *node, attaques att1, attaques att2,int tour)
{
  Item *child_p = NULL;
  /* allocate and init child node */
  child_p = nodeAlloc();
  initNode(child_p, node->T);

  child_p->AT = att2;
  child_p->choix=0;

  /* Make move (attaque) */
  deroulement_tour_att_att(child_p->T,att1,att2,tour);
  /* link child to parent for backtrack */
  child_p->parent = node;
  child_p->depth = node->depth + 1;

  return child_p;
}

// retourne un nouvelle item avec attaque du J1 et switch du J2
Item *getChildNode_att_swt(Item *node, attaques att, pokemon *poke,int tour){
  Item *child_p = NULL;
  /* allocate and init child node */
  child_p = nodeAlloc();
  initNode(child_p, node->T);

  child_p->choix =1;
  child_p->poke=poke;

  /* Make move (attaque) */
  deroulement_tour_att_swt(child_p->T,att,poke,tour);
  /* link child to parent for backtrack */
  child_p->parent = node;
  child_p->depth = node->depth + 1;

  return child_p;
}

// retourne un nouvelle item avec attaque du J2 et switch du J1
Item *getChildNode_swt_att(Item *node, attaques att, pokemon *poke,int tour){
  Item *child_p = NULL;
  /* allocate and init child node */
  child_p = nodeAlloc();
  initNode(child_p, node->T);

  child_p->choix=0;
  child_p->AT=att;

  /* Make move (attaque) */
  deroulement_tour_swt_att(child_p->T,att,poke,tour);
  /* link child to parent for backtrack */
  child_p->parent = node;
  child_p->depth = node->depth + 1;
  return child_p;
}

// retourne un nouvelle item avec switch di J1 et J2
Item *getChildNode_swt_swt(Item *node, pokemon *poke1, pokemon *poke2,int tour){
  Item *child_p = NULL;
  /* allocate and init child node */
  child_p = nodeAlloc();
  initNode(child_p, node->T);

  child_p->choix=1;
  child_p->poke=poke2;

  /* Make move (attaque) */
  deroulement_tour_swt_swt(child_p->T,poke1,poke2,tour);
  /* link child to parent for backtrack */
  child_p->parent = node;
  child_p->depth = node->depth + 1;
  return child_p;
}