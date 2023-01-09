#include "joueur.h"
#include <SDL.h>


int main(int argc,char **argv){
    SDL_version nb;
    SDL_VERSION(&nb);

    printf("SDL %d.%d.%d \n", nb.major,nb.minor,nb.patch);
}

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


/*
int main(){

    int choix1,choix2;
    attaques att1,att2;
    pokemon *poke1;
    pokemon *poke2;
    int tour=0;


    pile p=create_empty_stack();
    creer_pokedex(p);
    equipe *J1 = init_equipe (p);
    equipe *J2 = init_equipe (p);
    terrain *T = init_terrain(J1,J2);

    while(!partie_fini(J1, J2)){
//-------------------------------affichage du terrain ----------------------//
        afficher_terrain(T);

//--------------- choix des action -------------------//
    //le J1 joue
        printf("J1 : ");
        choix1 = choix_action_joueur();
        if(choix1 == 0){
            printf("J1 : ");
            att1= choix_att_joueur(T->pokeJ1);
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
            att2= choix_att_joueur(T->pokeJ2);
        }
        else{
            printf("J2 : ");
            poke2=choix_switch_joueur(J2);
        }

//-------------Deroulement du tour de jeu---------------//

    //si les deux joeurs ont attaqué
        if(choix1 == 0 && choix2 == 0){
            // si le premier pokemon est plus rapide que le deuxieme
            if(attaque_priorite(T->pokeJ1,T->pokeJ2)){
                applique_attaque(T,T->pokeJ1,T->pokeJ2,att1,tour);
                if(!mort(T->pokeJ2)){
                    applique_attaque(T,T->pokeJ2,T->pokeJ1,att2,tour);
                }
            }
            //si le J2 joue en premier
            else{
                applique_attaque(T,T->pokeJ2,T->pokeJ1,att2,tour);
                if(!mort(T->pokeJ1)){
                    applique_attaque(T,T->pokeJ1,T->pokeJ2,att1,tour);
                }
            }
        }
    // si le J1 attaque et le J2 switch
        else if( choix1 == 0 && choix2 == 1){
            switch_pokemon(T,poke2,2);
            applique_attaque(T,T->pokeJ1,T->pokeJ2,att1, tour);
        }
    // si le J2 attaque et le J1 switch
        else if( choix1 == 1 && choix2 == 0){
            switch_pokemon(T,poke1,1);
            applique_attaque(T,T->pokeJ2,T->pokeJ1,att2, tour);
        }
    // si les deux joueurs switch
        else{
            switch_pokemon(T,poke1,1);
            switch_pokemon(T,poke2,2);
        }


//----------------------- Gestion des statut ---------------------------//
    gestion_statut(T->pokeJ1, tour - T->pokeJ1->tour_etat);
    gestion_statut(T->pokeJ2, tour - T->pokeJ2->tour_etat);

//----------------------- CAS OU UN POKEMON SUR LE TERRAIN EST MORT ---------------------------//

        if(mort(T->pokeJ1) && J1->nb_vivant>1){
            //on retire le pokemon mort de l'equipe
            enlever_pokemon_equipe(J1,T->pokeJ1);
            //on en choisie un nouveau
            printf("Votre pokemon est mort veuillez en choisir un nouveau : \n");
            printf("J1 : ");
            poke1 = choix_switch_joueur(J1);
            switch_pokemon(T,poke1,1);
        }
        //dans ce cas c'est le dernier pokemon qui viens de mourir
        else if (mort(T->pokeJ1) && J1->nb_vivant <=1 ){
            //on met le nb de vivant a 0 pour que la partie se termine
            J1->nb_vivant=0;
        }


        if(mort(T->pokeJ2) && J2->nb_vivant>1){
            enlever_pokemon_equipe(J2,T->pokeJ2);
            printf("Votre pokemon est mort veuillez en choisir un nouveau : \n");
            printf("J2 : ");
            poke2 = choix_switch_joueur(J2);
            switch_pokemon(T,poke2,2);
        }
        else if (mort(T->pokeJ2) && J2->nb_vivant <=1 ){
        J2->nb_vivant=0;
        }
//----------------------- Gestion de la meteo ---------------------------//
    gestion_meteo(T,tour - T->tour_meteo);
    
    tour++;
    }

    printf("La partie est fini:\n");
    if(J1->nb_vivant == 0 ){
        printf("Le gagnant est J2 !\n");
    }
    else {
        printf("Le gagnant est J1 ! \n");
    }
}
*/