#include "ia.h"
#include <time.h>


// //demande au joueur si il veux attaquer ou switcher
// //renvoie 0 pour attaquer
// //1 pour switcher
int choix_action_ia(){
    srand(time(NULL));
    return rand()%2;
}

//affiche les attaque du pokemon sur le terrain
//puis renvoie l'attaque choisie par le joueur
attaques choix_att_ia(pokemon *poke){
    srand(time(NULL));
    int x = rand()% poke->nb_attaque;
    return poke->attaque[x];
}

// //renvoie le pokemon choisie poar le joueur
pokemon *choix_switch_ia(equipe *J1){
    srand(time(NULL));
    int x = rand() % J1->nb_vivant;
    return J1->liste_pokemon[x];
}