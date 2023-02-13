#include "node.h"

list_t openlist;
list_t closedlist;

pokemon choix_switch_ia_random(terrain T, int joueur);

void generate_bot_moves(Item *node,list_t *openlist, int tour);

void generate_j_moves(Item *node, list_t *openlist, int tour);

Item * minimax(Item *node, int depth, int player, int tour, Item *bestMove);

Item * astar(int tour);

Item *back_track(Item *node);

Item *solution_secours(Item *node,int tour);

Item *bfs( int tour);