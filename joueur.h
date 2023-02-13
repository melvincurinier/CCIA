#include "arbre.h"

// //renvoie true(1) si une equipe n'a plus de pokemon
int partie_fini (terrain T);

// //demande au joueur si il veux attaquer ou switcher
// //renvoie 0 pour attaquer
// //1 pour switcher
int choix_action_joueur();

//affiche les attaque du pokemon sur le terrain
//puis renvoie l'attaque choisie par le joueur
attaques choix_att_joueur(pokemon poke);

// //renvoie le pokemon choisie poar le joueur
pokemon choix_switch_joueur(equipe J1);