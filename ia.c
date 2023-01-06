#include "ia.h"

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>



pokemon *choix_switch_ia_random(equipe *J1){
    srand(time(NULL));
    int x = rand() % J1->nb_vivant;
    pokemon *p = J1->liste_pokemon[x];
    printf("J2 switch sur : %s\n",p->nom);
    return p;
}

//créer toutes les possibilité de coup et les rajoutes à l'arbre
// renvoie le meilleur coup possible ( valeurs definie dans f et calculé dans d'autre fonction)
Item *ia(terrain *T, int tour){
    Item *cur_node=nodeAlloc();
    Item *child_p;
    list_t openList_p;
    initList(&openList_p);
    int i,j,k;
    initNode(cur_node,T);
    printf("\n-----------------------------\n--------CUR NODE--------\n---------------------------\n");
    printItem(cur_node);
    /* créer toutes les poissibilités d'attaques et de switch */
    //pour chaque attaque possible de J2
    for ( i = 0; i < cur_node->T->pokeJ2->nb_attaque; i++) {
        //pour chaque attaque possible de J1
        for( k=0; k < cur_node->T->pokeJ1->nb_attaque; k++ ){
             child_p = getChildNode_att_att(cur_node, cur_node->T->pokeJ1->attaque[0],cur_node->T->pokeJ2->attaque[0],tour);
             addFirst( &openList_p, child_p );
        }
        //pour chaque switch possible de J1
        for(j=0; j<cur_node->T->player1->nb_vivant;j++){
            child_p = getChildNode_swt_att(cur_node,cur_node->T->pokeJ2->attaque[i],cur_node->T->player1->liste_pokemon[j],tour);
            addLast (&openList_p, child_p);
        }
    }
   // pour chaque switch possible de J2
    for (int i=0; j<cur_node->T->player2->nb_vivant;j++){
        //pour chaque attaque possible de J1
        for( k=0; k < cur_node->T->pokeJ1->nb_attaque; k++ ){
            child_p = getChildNode_att_swt(cur_node, cur_node->T->pokeJ2->attaque[k],cur_node->T->player2->liste_pokemon[i],tour);
            addLast( &openList_p, child_p );
        }
        //pour chaque switch possible de J1
        for(j=0; j<cur_node->T->player1->nb_vivant;j++){
            child_p = getChildNode_swt_swt(cur_node,cur_node->T->player1->liste_pokemon[j],cur_node->T->player2->liste_pokemon[i],tour);
            addLast (&openList_p, child_p);
        }
    }
    //recupere le meilleur noeud en fonction des parametre definie
/*--------------------pour le moment : recupere le premier elément c'est a dire le premier coup-------------*/
    child_p = popFirst(&openList_p);
    printf("\n-----------------------------\n--------CUR NODE--------\n---------------------------\n");
    printItem(child_p);    

  return child_p;
}

