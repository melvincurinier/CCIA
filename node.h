#include "joueur.h"

void printItem(Item *node);

void initNode(Item *node, terrain T);

double get_heuristic(Item *node);

pokemon best_switch_ia(terrain T);

terrain deroulement_tour_att(terrain T,int joueur, attaques att, int tour);

terrain deroulement_tour_swt(terrain T,int joueur, pokemon poke);

Item *get_child_att(Item *node, attaques att,int joueur, int tour);

Item *get_child_swt(Item *node, pokemon poke,int joueur);
