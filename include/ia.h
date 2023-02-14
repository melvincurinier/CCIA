#include "node.h"

list_t openlist;
list_t closedlist;

Item * astar(int tour);

Item *back_track(Item *node);

Item *solution_secours(Item *node,int tour);

Item *bfs( int tour);