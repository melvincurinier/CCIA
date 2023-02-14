#include "node.h"

pokemon choix_switch_ia_random(terrain T, int joueur);

Item * minimax(Item *node, int depth, int player, int tour);

Item * astar(list_t *openlist,int tour);

Item *back_track(Item *node);

Item *solution_secours(Item *node,int tour);

Item * bfs(list_t *openlist,int tour);

attaques best_attaque(Item *node);