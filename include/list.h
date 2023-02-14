#include <assert.h>
#include "pokemon.h"

struct cel{
    pokemon poke;
    struct cel *suiv;
};
typedef struct cel cellule;

typedef cellule * List;

struct zpile {
int size ;
List top ;
};
typedef struct zpile * pile ;

/*----------------fonction sur les liste ----------------------*/

//verifie si la liste est vide
int is_empty_list(List l) ;
//crée une lune liste vide
List create_empty_list();
//ajoute un élément a la liste
List add (pokemon e, List l);
//renvoie le premier élément de la liste
pokemon head(List l) ;
//renvoie la liste sans le premier élément
List tail(List l) ;

/*--------------------fonction sur la pile -------------------------*/

pile create_empty_stack();
int is_empty_stack();
//ajoute en tete un élément
void push(pokemon e, pile Pile);
//enleve le premier élément de la pile et renvoie sa valeur
pokemon pop(pile Pile);
//renvoie juste le premier élément
pokemon top(pile Pile);

pokemon pop_selection(pile Pile,int num);

void print_stack(pile Pile);
