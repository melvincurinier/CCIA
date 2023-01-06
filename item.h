#include "combat.h"

struct Item_s;

typedef struct Item_s {
  terrain *T;
  int choix; //choix que va faire l'ia
  attaques AT;  //attaque si l'ia decide d'attaquer
  pokemon * poke; //nouveau pokemon si elle decide de switch
  float f, g, h; // cost, heuristic, ...
  int depth;
  struct Item_s *parent; // needed for tree structure in game search
  struct Item_s *prev, *next; // needed for chained list 
} Item;