#include <stdio.h>
#include <stdlib.h>

typedef enum { feu, eau, plante, electrique, psy, poison, vol, spectre, tenebre, sol, dragon, fee, insecte, combat, normal, roche, acier, glace } Types ;

typedef enum {neutre, paraliser, empoisoner, endormie, brulure, confusion, geler } statut;

typedef enum {rien, pluie, tempete, grele, soleil} statut2;

typedef enum { surf, exuviation, aurasphere, laser_glace, exploforce, lance_flamme, vent_violent, toxic,croissance, giga_sangsue, puissance_cachee, 
bomb_beurk, direct_toxic, psyko, vampirisme, ombre_portee, danse_draco, seisme, draco_griffe, poing_feu,
cavalerie_lourde, queue_fer, lame_de_roc, machination, ball_ombre, tonnerre, Lame_dair, aile_acier, plaquage, sabotage, pisto_poing, croc_feu, eruction,
close_combat, ultralaser, machouille} capacites;

//typedef enum {flammeche, pistolet_a_eau, tranche_herbe, cage_eclair, berceuse, feu_follet, onde_folie, gele, toxic, danse_lames, repli, mimi_queue, rugissement, danse_pluie, zenith, tempeteneige, tempete_de_sable } capacites;



typedef struct{
    int PV_max;
    int PV;
    int attaque_initial;
    int attaque;
    int niv_att;
    int attaque_spe_initial;
    int attaque_spe;
    int niv_att_spe;
    int defense_initial;
    int defense;
    int niv_def;
    int defense_spe_initial;
    int defense_spe;
    int niv_def_spe;
    int vitesse_initial;
    int vitesse;
    int niv_vit;
}  stats; 

typedef struct{
    capacites nom;
    Types type;
    int application; //0 attaque normal, 1 changement de statut, 2 boost, 3 nerf, 4 meteo
    int precision;
    int puissance;
    /*------quand application == 0 (attaque normal )*/
    int phy_or_spe; //0 si attaque sur le physique, 1 si tape sur le speciale
    
    /*--------quand application == 1 (changement de statut) --------*/
    statut effet;  //quel statut sera appliqué au pokemon adverse
    /*--------quand application == 2 (boost) --------*/
    int boost;   //niveau de boost ou de diminution de la stat choisi
    int nb_s;  //nb de stat affecté par le changement
    int s[6]; // 1=attaque, 2=attaque_spe, 3=defense, 4=defense_spe, 5=vitesse
    /*--------------qaund application == 4*/
    statut2 Meteo;
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
    equipe J1;
    equipe J2;
    int tour_meteo;
    int toucher; //seulement pour l'ia
}  terrain ;



