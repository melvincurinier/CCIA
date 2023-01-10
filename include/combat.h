#include <time.h>

#include "pokedex.h"

/*-------------- Partie initialisation ----------------*/

//initialise une equipe avec les premier pokemon presnt dans la pile
equipe *init_equipe(pile p);
//initialise la meteo a neutre
//dans le futur gerer si des effest son apliqués au terrain
terrain *init_terrain(equipe *J1, equipe *J2);

/*-------------- Partie affichage ----------------*/

void afficher_equipe(equipe *E);
void afficher_terrain(terrain *T);

/*--------------Partie changement de pokemon-------------------*/

//modifie l'equipe pour placer le nouveau pokemon sur le terrain
void switch_pokemon(terrain *T, pokemon *poke, int joueur);  //joueur=1 pour J1, =2 pourJ2


/*-------------- Partie attaque a degats brute ----------------*/

//renvoie le multiplicateur de degats en fonction des affinités de type
double calcul_multiplicateur(Types offensive, Types defensive);
//retourn vrai si le type de l'attaque est le meme que celui du pokemon
int stab(attaques att, pokemon poke);
//calcule les degat infligés par poke1 sur pokeé
//Pour le moment :  prend en compte :
// Puissance de l'attaque, type de pokemon, type de l'attaque(stab + tableau des types), stat du pokemon attaquant, stat du poke defenseur
// a rajouter : boost d'attaque/defense ? meteo ? coup critique ? autre chose ? 
int calcul_pv_perdu(terrain *T,pokemon poke1, pokemon poke2, attaques att);


/*-------------- Partie attaque et gestion de changement de statut ----------------*/

void applique_confusion(terrain *T, pokemon * poke,attaques att);
//diminue de 25% la vitesse du pokemon (les 25% de chance de rater sont aplliquer dans a fonction "toucher")
void applique_paralisie(pokemon * p);
//diminue ls PV du pokemon de 1/8 par tour
void applique_degats_empoisonnement(pokemon * p);
//reduits l'attaque de moitié, diminue les pv de 1/16
void applique_degats_brulure(pokemon * p);
//20% de chance de se degeler a chaque tour
void degele(pokemon * poke);
//se reveil entre 1 et 3 tour
void reveil(pokemon * p, int tour);
//n'est plus confus entre 1 et 4 tour
void enleve_confusion(pokemon * p, int tour);
//applique les degats des statut et enleve les statut selon les proba associé
void gestion_statut(pokemon * poke, int tour);


/*-------------- Partie attaque à changement de stat ----------------*/

//renvoie le multiplicateur pour l'augmentation ou la diminution d'une stat en fonction du niv
double fraction(int f);
//diminue le niveau d'une stat en focntion de l'attaque
void applique_nerf(pokemon * poke, attaques att);
//augmente le niveau d'une stat en fonction de l'attaque
void applique_boost(pokemon *poke, attaques att);

/*-------------- Partie attaque de changement de meteo et gestion du terrain ----------------*/

void gestion_tempete(terrain *T,int tour);
void gestion_grele(terrain *T,int tour);
void gestion_soleil(terrain *T,int tour);
void gestion_pluie(terrain *T,int tour);
void gestion_meteo(terrain *T, int tour);

/*-------------- Partie gestion de l'attaque ----------------*/

// //renvoi vrai(1) si le poke1 doir attaquer en premier 
// //renvoie faux sinon
/* A L AVENIR : si rajout d'attaque prioritaire : le prendre en compte */
int attaque_priorite(pokemon *poke1, pokemon *poke2);
//renvoie 2 si le pokemon se blesse dans sa confusion
//renvoie 1 si l'attaque touche
//renvoie 0 si l'attaque rate
int toucher(pokemon poke,attaques att);
//renvoie le pokemon defenseur avec les degats recu ou le changement d'etat
//si le pokemon meurt, alors le retire de l'equipe
void applique_attaque(terrain *T, pokemon * poke_attaquant, pokemon * poke_defensive ,attaques att, int tour);


/*-------------- Partie gestion des morts ----------------*/

//renvoie si un pokemon est mort ou non
int mort(pokemon *poke);
//retourne une equipe sans le pokemon mort
void enlever_pokemon_equipe(equipe * E, pokemon *poke);






