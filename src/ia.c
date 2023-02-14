#include "ia.h"

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>


/*
// player : 1 = MAX(bot) / 2 = MIN(joueur)
// retourne l'item avec le meilleur terrain a la fin de l'execution
void minimax(Item *node, int depth, int player, int tour, Item *bestMove){
    Item *child ;
    Item *mouv;
    if(partie_fini(node->T) || depth == 10){
        return;
    }
        //tour de MAX
    else if(player == 1){
            bestMove->f=INT_MIN;
            //créer toutes les possibilités d'attaque possible
            for(int i=0;i<node->T.J1.liste_pokemon[0].nb_attaque;i++){
                child = get_child_att(node,node->T.J1.liste_pokemon[0].attaque[i],1,tour);
                // printf("////////////////////////////////////////////////////          LE TERRAIN D UN CHILD POUR MAX      \n");
                // afficher_terrain(child->T);
                // printf("l'attaque correspndante : ");
                // afficher_attaque(child->AT);
                // printf("\n");
                minimax(child,depth+1,2,tour+1,bestMove);
                if(mouv->f > bestMove->f){
                    bestMove = mouv;
                }
            }
            // bestMove->parent->f=bestMove->f;
            // printf("le f du parent : %f\n", bestMove->f);
        }
        //tour de MIN
    else{
           // printf("rentrer dans 2\n");
            bestMove->f=INT_MAX;
            //créer toutes les possibilités d'attaque possible
            for(int j=0;j<node->T.J2.liste_pokemon[0].nb_attaque;j++){
                child = get_child_att(node,node->T.J2.liste_pokemon[0].attaque[j],2,tour);
                // printf("////////////////////////////////////////////////////           LE TERRAIN D UN CHILD POUR MIN      \n");
                // afficher_terrain(child->T);
                // printf("l'attaque correspndante : ");
                // afficher_attaque(child->AT);
                // printf("\n");
                minimax(child,depth+1,1,tour+1,bestMove);
                
                if(mouv->f < bestMove->f){
                    bestMove = mouv;
                }
            }
            // bestMove->parent->f=bestMove->f;
        }
}
*/


Item * astar(list_t *openlist,int tour){
    Item *node, *child;
    int i,j;
    while (listCount(openlist) != 0){
        node = popBest(openlist);
        //arret de la recherche si on a réussi a finir la partie 
        //ou si la pofondeur dépasse la profondeur max
        if (partie_fini(node->T) || node->depth >= 10 ) {
            return back_track(node);
        }
        else{
            //création de toutes les possibilités d'attaque de l'ia
            for( i=0; i < node->T.J2.liste_pokemon[0].nb_attaque; i++){
                child = get_child_att(node, node->T.J2.liste_pokemon[0].attaque[i],2, tour);
                    addFirst(openlist,child);
                }
            //création de toutes les possibilités de switch de l'ia
            for( j=1; j < node->T.J2.nb_vivant; j++ ){
                child = get_child_swt(node,node->T.J2.liste_pokemon[j],2);
                    addFirst(openlist,child);
                }
        }
    }  

}


Item *solution_secours(Item *node,int tour){
    Item *best_node=nodeAlloc();
    Item *child;
    for(int i=0; i <= node->T.J2.liste_pokemon[0].nb_attaque; i++){
        child = get_child_att(node, node->T.J2.liste_pokemon[0].attaque[i],2, tour);
        printf("dans les attaque f = %0.1f\n",child->f);
        if(child->f < best_node->f){
            best_node=child;
            printf("dans le if f=%0.1f\n",best_node->f);
        }
    }
    // for(int j=1; j < node->T.J2.nb_vivant; j++ ){
    //     child = get_child_swt(node,node->T.J2.liste_pokemon[j],2);
    //     printf("dans les switch h = %0.1f\n",child->f);
    //     if(child->f < best_node->f){
    //         best_node=child;
    //     }
    // }
    return best_node;
}


Item *back_track(Item *node){
    Item *tmp = node;
    while(tmp->parent->depth != 0 ){
        tmp = tmp ->parent;
    }
    return tmp;
}