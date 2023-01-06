#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "arbre.h"

/* Item Functions */

Item *nodeAlloc()
{
  Item *node;

  node = (Item *) malloc( sizeof(Item) );
  assert(node);

  node->T=NULL;
  node->parent = NULL;
  node->prev = NULL;
  node->next = NULL;
  node->poke = NULL;
  node->f = node->g = node->h = (double)0.0;

  return node;
}

void freeItem( Item *node )
{
  if (node && node->T) free(node->T);
  if (node) free(node);
}


void initList( list_t *list_p )
{
  //if (list_p == NULL) list_p = malloc(sizeof(list_t));
	assert(list_p);
  list_p->numElements = 0;
  list_p->first = NULL;
  list_p->last = NULL;
}

int listCount( list_t *list )
{
	return list->numElements;
}

// return an item with corresponding board , or null
// Item* onList( list_t *list, char *board)
// {
//   Item *item=list->first;
//   while(item!=NULL){
//     if(strcmp(board,item->board) == 0){
//       return item;
//     }
//     item=item->next;
//   }
//   return NULL;
// }

Item* onList( list_t *list,terrain *T )
{
    assert(list);  assert(T);
	Item *cur = list->first;
	while (cur) {
     	if (cur->T->meteo == T->meteo && cur->T->pokeJ1 == T->pokeJ1 && cur->T->pokeJ2==T->pokeJ2 && cur->T->tour_meteo){
            return cur;
        }
        cur = cur->next;
    }
    return NULL;
}

// return and remove first item
Item *popFirst( list_t *list ) //
{
	Item *item = list->first;
  delList(list,list->first);
	return item;
}

// return and remove last item
Item *popLast( list_t *list ) //
{
	Item *item = list->last;
  delList(list,list->last);
  return item;
}

// remove a node from list
void delList( list_t *list, Item *node) {
  if(list->numElements==0){
    return;
  }
  else{
    if(list->numElements==1){
      list->first=list->last=NULL;
    }
    else if(list->first==node){
      node->next->prev=NULL;
      list->first=node->next;
      node->next=NULL;

    }
    else if(list->last==node){
      node->prev->next=NULL;
      list->last=node->prev;
      node->prev=NULL;
    }
    else{
      node->prev->next=node->next;
      node->next->prev=node->prev;
      node->next=NULL;
      node->prev=NULL;
    }
    list->numElements--;
  }
}

// return and remove best item with minimal f value
Item *popBest( list_t *list ) // and remove the best board from the list.
{
  Item *item = list->first;
  Item *best= list->first;
  while(item!=NULL ){
    if(item->f < best->f){
      best=item;
    }
    item=item->next;
  }
  delList(list,best);
  return best;
}

 // add item in top
void addFirst( list_t *list, Item *node ) // add in head
{
  if(list->numElements==0){
    list->first=node;
    list->last=node;
  }
  else{
    node->next=list->first;
    list->first->prev=node;
    list->first=node;
  }
  list->numElements++;
}

 // add item in queue
void addLast( list_t *list, Item *node ) // add in tail
{
  
  if(list->numElements==0){
    list->first=node;
    list->last=node;
  }
  else{
    list->last->next=node;
    node->prev=list->last;
    list->last=node;
  }
  list->numElements++;
}

void cleanupList( list_t *list )
{
  int i;
  Item *tmp=list->first;
  for(i=0;i<list->numElements - 1 ;i++){
    list->first=list->first->next;
    list->first->prev=NULL;
    freeItem(tmp);
    tmp=list->first;
  }
  list->first=NULL;
  freeItem(tmp);
  list->numElements=0;
}

void printList( list_t list ) {
	Item *item = list.first;
  while (item) {
    afficher_terrain(item->T);
    item = item->next;
  }
  printf(" (nb_items: %d)\n", list.numElements);
}