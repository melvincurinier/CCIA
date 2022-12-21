#include "joueur.h"


// int main(){
//     pile p=create_empty_stack();
//     creer_pokedex(p);
//     //afficher_pokedex(p);
//     equipe J1,J2;
//     attaques att1, att2;
//     int tour=0;
//     J1 = init_equipe (p);
//     J2 = init_equipe (p);
//     terrain T = init_terrain(J1,J2);
//    J1 = switch_pokemon(J1, J1.liste_pokemon[2]);
//     while(!partie_fini(J1, J2)){
//         afficher_terrain(T,J1,J2);
//         printf("J1 : ");
//         att1 = choix_att_joueur(J1.liste_pokemon[0]);
//         att2 = choix_att_joueur(J2.liste_pokemon[0]);

//         J2.liste_pokemon[0] = applique_attaque(J1.liste_pokemon[0],J2.liste_pokemon[0],att1,tour);
//         J1.liste_pokemon[0] = applique_attaque(J2.liste_pokemon[0],J1.liste_pokemon[0],att2,tour);



//         J2.liste_pokemon[0]=gestion_statut(J2.liste_pokemon[0], tour - J2.liste_pokemon[0].tour_etat);

//         tour++;
//     }

//    // printf("degats : %d\n",calcul_pv_perdu(J1.liste_pokemon[0],J2.liste_pokemon[0], J1.liste_pokemon[0].attaque[0]));
//     // printf("%d \n", toucher(J1.liste_pokemon[0].attaque[0]));
//     // J1 = switch_pokemon(J1,J1.liste_pokemon[2]);
//     // afficher_terrain(T,J1,J2); 

//     return 0;
// } 



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

    while(!partie_fini(J1, J2)){
    
//-------------------------------affichage du terrain ----------------------//
    afficher_terrain(T,J1,J2);

//--------------- choix des action -------------------//
    //le J1 joue
        printf("J1 : ");
        choix1 = choix_action_joueur();
        if(choix1 == 0){
            printf("J1 : ");
            att1= choix_att_joueur(J1.liste_pokemon[0]);
        }
        else{
            printf("J1 : ");
            poke1=choix_switch_joueur(J1);
        }
    //le J2 joue a son tour
        printf("J2 : ");
        choix2 = choix_action_joueur();
        if(choix2 == 0){
            printf("J2 : ");
            att2= choix_att_joueur(J2.liste_pokemon[0]);
        }
        else{
            printf("J2 : ");
            poke2=choix_switch_joueur(J2);
        }

//-------------Deroulement du tour de jeu---------------//

    //si les deux joeurs ont attaqué
        if(choix1 == 0 && choix2 == 0){
            // si le premier pokemon est plus rapide que le deuxieme
            if(attaque_priorite(J1.liste_pokemon[0],J2.liste_pokemon[0])){
                touch = toucher(J1.liste_pokemon[0], att1);
                if(touch==0){
                    printf("le pokemon de J1 a raté son attaque\n");
                }
                //l'attaque a reussi
                else if(touch==1){
                    J2.liste_pokemon[0] = applique_attaque(J1.liste_pokemon[0],J2.liste_pokemon[0],att1,tour);
                    if(!mort(J2.liste_pokemon[0])){
                        touch = toucher(J2.liste_pokemon[0],att2);
                        if(touch==0){
                            printf("le pokemon de J2 a raté son attaque\n");
                        }
                        else if(touch==1){
                            J1.liste_pokemon[0] = applique_attaque(J2.liste_pokemon[0],J1.liste_pokemon[0],att2,tour);
                        }
                        else if(touch ==2){
                            J2.liste_pokemon[0] = applique_confusion(J2.liste_pokemon[0],att2);
                        }
                    }
                } 
                //le pokemon se blesse dans sa confusion
                else if(touch==2){
                    J1.liste_pokemon[0] = applique_confusion(J1.liste_pokemon[0],att1);
                    touch = toucher(J2.liste_pokemon[0],att2);
                        if(touch==0){
                            printf("le pokemon de J2 a raté son attaque\n");
                        }
                        else if(touch==1){
                            J1.liste_pokemon[0] = applique_attaque(J2.liste_pokemon[0],J1.liste_pokemon[0],att2,tour);
                        }
                        else if(touch ==2){
                            J2.liste_pokemon[0] = applique_confusion(J2.liste_pokemon[0],att2);
                        }
                }
            }
            //si le J2 joue en premier
            else{
                touch = toucher(J2.liste_pokemon[0], att2);
                if(touch==0){
                    printf("le pokemon de J2 a raté son attaque\n");
                }
                //l'attaque a reussi
                else if(touch==1){
                    J1.liste_pokemon[0] = applique_attaque(J2.liste_pokemon[0],J1.liste_pokemon[0],att2,tour);
                    if(!mort(J1.liste_pokemon[0])){
                        touch = toucher(J1.liste_pokemon[0],att1);
                        if(touch==0){
                            printf("le pokemon de J1 a raté son attaque\n");
                        }
                        else if(touch==1){
                            J2.liste_pokemon[0] = applique_attaque(J1.liste_pokemon[0],J2.liste_pokemon[0],att1,tour);
                        }
                        else if(touch ==2){
                            J1.liste_pokemon[0] = applique_confusion(J1.liste_pokemon[0],att1);
                        }
                    }
                }
                //le pokemon se blesse dans sa confusion
                else if(touch==2){
                    J2.liste_pokemon[0] = applique_confusion(J2.liste_pokemon[0],att2);
                    touch = toucher(J1.liste_pokemon[0],att1);
                        if(touch==0){
                            printf("le pokemon de J1 a raté son attaque\n");
                        }
                        else if(touch==1){
                            J2.liste_pokemon[0] = applique_attaque(J1.liste_pokemon[0],J2.liste_pokemon[0],att1,tour);
                        }
                        else if(touch ==2){
                            J1.liste_pokemon[0] = applique_confusion(J1.liste_pokemon[0],att1);
                        }
                }
            }
        }
    // si le J1 attaque et le J2 switch
        else if( choix1 == 0 && choix2 == 1){
            J2 = switch_pokemon(J2,poke2);
            touch = toucher(J1.liste_pokemon[0],att1);
            if(touch==0){
                printf("le pokemon de J1 a rater son attaque\n");
            }
            else if(touch==1){
                J2.liste_pokemon[0] = applique_attaque(J1.liste_pokemon[0],J2.liste_pokemon[0],att1, tour);
            }
            else if(touch==2){
                J1.liste_pokemon[0] = applique_confusion(J1.liste_pokemon[0],att1);
            }
        }
    // si le J2 attaque et le J1 switch
        else if( choix1 == 1 && choix2 == 0){
            J1 = switch_pokemon(J1,poke1);
            touch = toucher(J2.liste_pokemon[0],att2);
            if(touch==0){
                printf("le pokemon de J2 a rater son attaque\n");
            }
            else if(touch==1){
                J1.liste_pokemon[0] = applique_attaque(J2.liste_pokemon[0],J1.liste_pokemon[0],att2, tour);
            }
            else if(touch==2){
                J2.liste_pokemon[0] = applique_confusion(J2.liste_pokemon[0],att1);
            }
        }
    // si les deux joueurs switch
        else{
            J1 = switch_pokemon(J1,poke1);
            J2 = switch_pokemon(J2,poke2);
        }


//----------------------- Gestion des statut ---------------------------//
    J1.liste_pokemon[0]=gestion_statut(J1.liste_pokemon[0], tour - J1.liste_pokemon[0].tour_etat);
    J2.liste_pokemon[0]=gestion_statut(J2.liste_pokemon[0], tour - J2.liste_pokemon[0].tour_etat);


//----------------------- CAS OU UN POKEMON SUR LE TERRAIN EST MORT ---------------------------//

        if(mort(J1.liste_pokemon[0]) && J1.nb_vivant>1){
            //on retire le pokemon mort de l'equipe
            J1=enlever_pokemon_equipe(J1,J1.liste_pokemon[0]);
            //on en choisie un nouveau
            printf("Votre pokemon est mort veuillez en choisir un nouveau : \n");
            printf("J1 : ");
            poke1 = choix_switch_joueur(J1);
            J1 = switch_pokemon(J1,poke1);
        }
        //dans ce cas c'est le dernier pokemon qui viens de mourir
        else if (mort(J1.liste_pokemon[0]) && J1.nb_vivant <=1 ){
            //on met le nb de vivant a 0 pour que la partie se termine
            J1.nb_vivant=0;
        }


        if(mort(J2.liste_pokemon[0]) && J2.nb_vivant>1){
            J2=enlever_pokemon_equipe(J2,J2.liste_pokemon[0]);
            printf("Votre pokemon est mort veuillez en choisir un nouveau : \n");
            printf("J2 : ");
            poke2 = choix_switch_joueur(J2);
            J2 = switch_pokemon(J2,poke2);
        }
        else if (mort(J2.liste_pokemon[0]) && J2.nb_vivant <=1 ){
        J2.nb_vivant=0;
        }

        tour++;
    }

    printf("La partie est fini:\n");
    if(J1.nb_vivant == 0 ){
        printf("Le gagnant est J2 !\n");
    }
    else {
        printf("Le gagnant est J1 ! \n");
    }

}
