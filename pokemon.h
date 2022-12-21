#include <stdio.h>
#include <stdlib.h>

typedef enum { feu, eau, plante, electrique, psy, poison, vol, spectre, tenebre, sol, dragon, fee, insecte, combat, normal, roche, acier, glace } Types ;

typedef enum {neutre, paraliser, empoisoner, endormie, brulure, confusion, geler } statut;

typedef enum {rien, pluie, tempete, grele, soleil} statut2;

typedef enum {flammeche, pistolet_a_eau, tranche_herbe, cage_eclair, berceuse, feu_follet, onde_folie, gele, toxic} capacites;


typedef struct{
    int PV_max;
    int PV;
    int attaque;
    int attaque_spe;
    int defense;
    int defense_spe;
    int vitesse;
}  stats; 

typedef struct{
    capacites nom;
    Types type;
    int application; //0 attaque normal, 1 changement de statut, 2 boost, 3 nerf
    int precision;
    int puissance;
    /*------quand application == 0 (attaque normal )*/
    int phy_or_spe; //0 si attaque sur le physique, 1 si tape sur le speciale
    
    /*--------quand application == 1 (changement de statut) --------*/
    statut effet;  //quel statut sera appliqué au pokemon adverse
    /*--------quand application == 2 (boost) --------*/
    double boost;   //multiplicateur (augmentation ou diminution) de la stat choisi
    int s; //0=PV, 1=attaque, 2=attaque_spe, 3=defense, 4=defense_spe, 5=vitesse
} attaques;

typedef struct{
    char *nom;
    Types type;
    int nb_attaque;
    attaques attaque[4];
    stats stat;
    statut etat;
    int tour_etat;
}  pokemon;


typedef struct{
    int nb_vivant;
    // le pokemon à l'indice 0 sera celui sur le terrain
    pokemon liste_pokemon[6];
}  equipe ;

typedef struct{
    statut2 meteo;
}  terrain ;



