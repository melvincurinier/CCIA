
#include "list.h"

/*--------------------fonction sur la liste --------------------------*/
//verifie si la liste est vide
int is_empty_list(List l){
    if(l == NULL){
        return 1;
    }
    else {
        return 0;
    }
}
//crée une lune liste vide
List create_empty_list(){
    return NULL;
}
//ajoute un élément au debut de la liste
List add(pokemon e, List l){
    cellule *cel = malloc(sizeof(cellule));
    cel->poke = e;
    (*cel).suiv = l;
    return cel;
}
pokemon head(List l){
    assert(!is_empty_list(l));
    return l->poke;
}
List tail(List l){
    assert(!is_empty_list(l));
    return l->suiv;
}

/*--------------------fonction sur la pile --------------------------*/

pile create_empty_stack(){
    pile Pile=malloc(sizeof(pile));
    Pile->size=0;
    Pile->top=create_empty_list();
    return Pile;
}

//retourn 1(vrai) si la pile est vide et 0(faux) si la liste n'est pas vide
int is_empty_stack(pile Pile){
    if (Pile->size==0){
        return 1;
    }
    else{
        return 0;
    }
}

void push(pokemon e,pile Pile){
    Pile->size++;
    Pile->top = add(e,Pile->top);
}

pokemon pop(pile Pile){
    pokemon e = head(Pile->top);
    cellule *tmp=Pile->top;
    Pile->size=Pile->size -1;
    Pile->top=tail(Pile->top);
    free(tmp);
    return e;
}

pokemon top(pile Pile){
    return head(Pile->top);
}

// pokemon pop_selection(pile Pile,int num){
//     if(num==0){
//         return pop(Pile);
//     }
//     else{
//         cellule *tmp = Pile->top;
//         cellule *tmp2;
//         for (int i=0;i<num;i++){
//             tmp2=tmp;
//             tmp=tail(tmp);
//         }
        
//         tmp2->suiv = tmp->suiv;
//         pokemon poke = tmp->poke;
//         free(tmp);
//         Pile->size=Pile->size -1;
//         return poke;
//     }
// }

pokemon pop_selection(pile Pile, int num){
    cellule *tmp = Pile->top;
    for(int i=0;i<num;i++){
        tmp=tmp->suiv;
    }
    return tmp->poke;
}


