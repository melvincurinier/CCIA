#include "ia.h"


//J1 sera l'ia
int main(){

    int choix1,choix2;
    attaques att1,att2;
    pokemon poke1,poke2;
    int tour=0;
    int touch;

    pile p=create_empty_stack();
    creer_pokedex(p);
    equipe J1,J2;
    J1 = init_equipe (p);
    J2 = init_equipe (p);
    terrain T = init_terrain(J1,J2);
    int joueur = 0;
    

    initList(&openlist);
    // initList(&closedlist);
    
    
    Item *node = nodeAlloc();
    Item *res_ia = nodeAlloc();
    //Item *choix_ia = nodeAlloc();

    //initialisation ia
    // initNode( node,T,tour);
    // addFirst(&openlist,node);
    // res_ia = bfs( tour);
    // int tour_affiler=0;

    while(!partie_fini(T)){
        
//-------------------------------affichage du terrain ----------------------//
        afficher_terrain(T);

        if(joueur == 0){
    // -------------------- tour de J1 ------------------------------ //
            printf("J1 : ");
            choix1 = choix_action_joueur();
            if(choix1 == 0){
                printf("J1: ");
                att1= choix_att_joueur(T.J1.liste_pokemon[0]);
            }
            else{
                printf("J1 : ");
                poke1=choix_switch_joueur(T.J1);
            }

            if( choix1 == 0 ){
                touch = toucher(T.J1.liste_pokemon[0], att1);
                if(touch==0){
                    printf("le pokemon de J1 a raté son attaque\n");
                }
                //l'attaque a reussi
                else if(touch==1){
                    T = applique_attaque(T,1,att1,tour);
                } 
                //le pokemon se blesse dans sa confusion
                else if(touch==2){
                    T.J1.liste_pokemon[0] = applique_confusion(T,T.J1.liste_pokemon[0],att1);
                }
            }
            else{
                T = switch_pokemon(T,1,poke1);
            }
        //----------------------- Gestion des statut ---------------------------//

            T.J1.liste_pokemon[0]=gestion_statut(T.J1.liste_pokemon[0], tour - T.J1.liste_pokemon[0].tour_etat);

        //----------------------- Gestion de la meteo ---------------------------//
            T = gestion_meteo(T,1, tour - T.tour_meteo);

        //----------------------- CAS OU UN POKEMON SUR LE TERRAIN EST MORT ---------------------------//

            if(mort(T.J2.liste_pokemon[0]) && T.J2.nb_vivant>1){
                T=enlever_pokemon_equipe(T,2,T.J2.liste_pokemon[0]);
                printf("Le pokemon de J2 est mort ! \n");
                poke2 = best_switch_ia(T);
                T = switch_pokemon(T, 2, poke2);
            }
            else if (mort(T.J2.liste_pokemon[0]) && T.J2.nb_vivant <=1 ){
                T.J2.nb_vivant=0;
            }
            if(mort(T.J1.liste_pokemon[0]) && T.J1.nb_vivant>1){
                //on retire le pokemon mort de l'equipe
                T = enlever_pokemon_equipe(T, 1,T.J1.liste_pokemon[0]);
                //on en choisie un nouveau
                printf("Votre pokemon est mort veuillez en choisir un nouveau : \n");
                printf("J1 : ");
                poke1 = choix_switch_joueur(T.J1);
                T = switch_pokemon(T, 1, poke1);
            }
            //dans ce cas c'est le dernier pokemon qui viens de mourir
            else if (mort(T.J1.liste_pokemon[0]) && T.J1.nb_vivant <=1 ){
                //on met le nb de vivant a 0 pour que la partie se termine
                T.J1.nb_vivant=0;
            }
            
        }
    // -------------------- tour de J2 ------------------------------ //
        else{
            printf("J2 :");
            
            initNode( node,T);
            addFirst(&openlist,node);
            res_ia = astar( tour);
                // choix_ia = back_track(res_ia,tour_affiler);
                // if( choix_ia->T.J1.liste_pokemon[0].nom != T.J1.liste_pokemon[0].nom  || choix_ia->T.meteo != T.meteo || choix_ia->parent->T.J1.liste_pokemon[0].stat.PV == T.J1.liste_pokemon[0].stat.PV){
                //     res_ia = bfs( tour);
                //     choix_ia = back_track(res_ia,tour_affiler);
                //     tour_affiler=0;
                // }
                // }
            // initNode(node, T);
            // res_ia = solution_secours(node, tour);
             choix2 = res_ia->choix;
            if(choix2 == 0){
                att2 = res_ia->AT;
                printf("l'attaque choisi par l'ia : ");
                afficher_attaque(att2);
                printf("\n");
            }
            else{
                printf("J2 : ");
                poke2=res_ia->poke;
                printf("le pokemon choisi par l'ia : %s", poke2.nom);

            }
            // res = ia(T,tour);
            // choix2 = res->choix;
            // if(choix2 == 0){
            //     att2 = res->AT;
            // }
            // else if (choix2 ==1) {
            //     poke2 = res->poke;
            // }
        
            if(choix2 == 0){
                touch = toucher(T.J2.liste_pokemon[0], att2);
                if(touch==0){
                    printf("le pokemon de J2 a raté son attaque\n");
                }
                //l'attaque a reussi
                else if(touch==1){
                    T = applique_attaque(T,2,att2,tour);
                }
                //le pokemon se blesse dans sa confusion
                else if(touch==2){
                    T.J2.liste_pokemon[0] = applique_confusion(T,T.J2.liste_pokemon[0],att2);
                }
            }
            else {
                T = switch_pokemon(T,2,poke2);
            }
        //----------------------- Gestion des statut ---------------------------//

            T.J2.liste_pokemon[0]=gestion_statut(T.J2.liste_pokemon[0], tour - T.J2.liste_pokemon[0].tour_etat);

        //----------------------- Gestion de la meteo ---------------------------//
            T = gestion_meteo(T,2, tour - T.tour_meteo);
            
    //----------------------- CAS OU UN POKEMON SUR LE TERRAIN EST MORT ---------------------------//
            if(mort(T.J1.liste_pokemon[0]) && T.J1.nb_vivant>1){
                //on retire le pokemon mort de l'equipe
                T = enlever_pokemon_equipe(T, 1,T.J1.liste_pokemon[0]);
                //on en choisie un nouveau
                printf("Votre pokemon est mort veuillez en choisir un nouveau : \n");
                printf("J1 : ");
                poke1 = choix_switch_joueur(T.J1);
                T = switch_pokemon(T, 1, poke1);
            }
            //dans ce cas c'est le dernier pokemon qui viens de mourir
            else if (mort(T.J1.liste_pokemon[0]) && T.J1.nb_vivant <=1 ){
                //on met le nb de vivant a 0 pour que la partie se termine
                T.J1.nb_vivant=0;
            }
            if(mort(T.J2.liste_pokemon[0]) && T.J2.nb_vivant>1){
                T=enlever_pokemon_equipe(T,2,T.J2.liste_pokemon[0]);
                printf("Le pokemon de J2 est mort ! \n");
                poke2 = best_switch_ia(T);
                printf("l'ia switch sur : %s\n",poke2.nom);
                T = switch_pokemon(T, 2, poke2);
            }
            else if (mort(T.J2.liste_pokemon[0]) && T.J2.nb_vivant <=1 ){
                T.J2.nb_vivant=0;
            }
            
            tour++;
            cleanupList(&openlist);
        }
        joueur = (joueur + 1) %2 ; //changement de joueur
    }

    printf("La partie est fini\n");
    if(T.J1.nb_vivant == 0 ){
        printf("Le gagnant est J2 !\n");
    }
    else {
        printf("Le gagnant est J1 ! \n");
    }

}


