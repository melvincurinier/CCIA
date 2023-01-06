#include "joueur.h"



void printItem(Item *node);

void initNode(Item *node, terrain *T);

int evaluateNode( Item *node );

terrain copy_terrain(terrain *T);

terrain evalue_attaque(terrain T,pokemon poke_attaquant, pokemon poke_defensive, attaques att, int tour);

void deroulement_tour_att_att(terrain *T, attaques att1, attaques att2, int tour);
void deroulement_tour_att_swt(terrain *T,attaques att, pokemon *poke, int tour);
void deroulement_tour_swt_att(terrain *T,attaques att, pokemon *poke, int tour);
void deroulement_tour_swt_swt(terrain *T, pokemon *poke1, pokemon *poke2, int tour);

Item *getChildNode_att_att(Item *node, attaques att1, attaques att2,int tour);
Item *getChildNode_att_swt(Item *node, attaques att, pokemon *poke,int tour);
Item *getChildNode_swt_att(Item *node, attaques att, pokemon *poke,int tour);
Item *getChildNode_swt_swt(Item *node, pokemon *poke1, pokemon *poke2,int tour);

