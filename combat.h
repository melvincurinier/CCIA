#include <time.h>

#include "pokedex.h"

//initialise une equipe avec les premier pokemon presnt dans la pile
equipe init_equipe(pile p);

void afficher_equipe(equipe E);

//initialise la meteo a neutre
// dans le futur gerer si des effest son apliqués au terrain
terrain init_terrain();

void afficher_terrain(terrain T,equipe J1, equipe J2);

//renvoie le multiplicateur de degats en fonction des affinités de type
double calcul_multiplicateur(Types offensive, Types defensive);

//retourn vrai si le type de l'attaque est le meme que celui du pokemon
int stab(attaques att, pokemon poke);

//calcule les degat infligés par poke1 sur pokeé
//Pour le moment :  prend en compte :
// Puissance de l'attaque, type de pokemon, type de l'attaque(stab + tableau des types), stat du pokemon attaquant, stat du poke defenseur
// a rajouter : boost d'attaque/defense ? meteo ? coup critique ? autre chose ? 
int calcul_pv_perdu(pokemon poke1, pokemon poke2, attaques att);

//retourne une equipe sans le pokemon mort
equipe enlever_pokemon_equipe(equipe E, pokemon poke);

//renvoie 2 si le pokemon se blesse dans sa confusion
//renvoie 1 si l'attaque touche
//renvoie 0 si l'attaque rate
int toucher(pokemon poke,attaques att);

//renvoie le pokemon defenseur avec les degats recu ou le changement d'etat
//si le pokemon meurt, alors le retire de l'equipe
pokemon applique_attaque(pokemon poke_attaquant, pokemon poke_defensive ,attaques att, int tour);

pokemon applique_confusion(pokemon poke,attaques att);

//renvoie si un pokemon est mort ou non
int mort(pokemon poke);

// //renvoi vrai(1) si le poke1 doir attaquer en premier 
// //renvoie faux sinon
/* A L AVENIR : si rajout d'attaque prioritaire : le prendre en compte */
int attaque_priorite(pokemon poke1, pokemon poke2);

//modifie l'equipe pour placer le nouveau pokemon à l'indice 0 et renvoie l'equipe modifié
equipe switch_pokemon(equipe E, pokemon poke);

//diminue de 25% la vitesse du pokemon (les 25% de chance de rater sont aplliquer dans a fonction "toucher")
pokemon applique_paralisie(pokemon p);

//diminue ls PV du pokemon de 1/8 par tour
pokemon applique_degats_empoisonnement(pokemon p);

//reduits l'attaque de moitié, diminue les pv de 1/16
pokemon applique_degats_brulure(pokemon p);

pokemon degele(pokemon poke);

pokemon reveil(pokemon p, int tour);

pokemon enleve_confusion(pokemon p, int tour);

pokemon gestion_statut(pokemon poke, int tour);