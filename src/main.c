#include "joueur.h"
#include "graphic.h"

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
}*/

int main(int arg,char **argv){
    SDL_Window * window = NULL;
    SDL_Renderer * renderer = NULL;
    SDL_Rect rectangle;
    //--------- Initialisation de la SDL --------//
        /*Verification du retour de la fonction d'initialisation*/
    if(SDL_Init(SDL_INIT_VIDEO) != 0) SDL_ExitWithError("Initialisation SDL Failed");
    //--------- Debut du programme ----------//
    //
    //----------- Creation de la fenètre ---------//
    window = SDL_CreateWindow("Poket Monster",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,WINDOW_WIDTH,WINDOW_HEIGTH,0);
        /*Verification de la bonne creation de la fenetre*/
    if(window == NULL) SDL_ExitWithError(" Window creation failed");
    //---------------------------------------------------//
    //
    //--------- Creation du rendu de la page ---------//
    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_SOFTWARE);
        /*Verification de la bonne creation du rendu*/
    if(renderer == NULL) SDL_ExitWithError("Renderer creation failed");
    //--------- Modification du rendu de la page ----------//
    //   /*Verification que le cahngement de couleur a bien été effectuer*/
    //if(SDL_SetRenderDrawColor(renderer,112,168,237,SDL_ALPHA_OPAQUE) != 0) SDL_ExitWithError("Renderer draw failed");
    //
    //if(SDL_RenderDrawPoint(renderer,100,450)!=0) SDL_ExitWithError("Renderer creation point failed");/*creation point*/
    //
    //if(SDL_RenderDrawLine(renderer,10,45,500,500)!=0) SDL_ExitWithError("Renderer creation line failed");/*creation ligne*/
    //
    //if(SDL_RenderFillRect(renderer,&rectangle)!=0) SDL_ExitWithError("Renderer creation rect failed");/*creation rectangle plein*/
    //----------------------------------------------------//
    //
    //----------- Creation de texture ---------//
   /*SDL_Surface * image =NULL;
    SDL_Texture * background =NULL;

    image = IMG_Load("src/ambiance.PNG");

    if(image == NULL){
        SDL_Destroyed(renderer,window);
        SDL_ExitWithError("Renderer load image failed");
    }

    background = SDL_CreateTextureFromSurface(renderer,image);
    SDL_FreeSurface(image);

    if(background == NULL){
        SDL_Destroyed(renderer,window);
        SDL_ExitWithError("Renderer texture creation failed"); 
    }

    if(SDL_QueryTexture(background,NULL,NULL,&rectangle.w,&rectangle.h) != 0){
        SDL_Destroyed(renderer,window);
        SDL_ExitWithError("Renderer load texture failed"); 
    }

    rectangle.x=(WINDOW_WIDTH - rectangle.w)/2;
    rectangle.y=(WINDOW_HEIGTH - rectangle.h)/2;

    if(SDL_RenderCopy(renderer,background,NULL,&rectangle) !=0){
        SDL_Destroyed(renderer,window);
        SDL_ExitWithError("Renderer texture failed");//affihage  
    }*/
    //------------ Creation de la boucle du programme -------//
    //
    //------------ Gestion de fps --------------//
    unsigned int frame_limit = 0;
        /*comment limité les fps*/
        /*
            30fps 1000/30=33
            60fps 1000/60=16 
        */
    frame_limit = SDL_GetTicks()+FPS_LIMIT; // en debut de programme 
        /* fonction de gestion de l'animation*/
    limit_fps(frame_limit);
        /* a mettre en fin animation */
    frame_limit = SDL_GetTicks()+FPS_LIMIT;
    //-----------------------------------------//
    SDL_bool program_lauched = SDL_TRUE;

    while(program_lauched){
        SDL_Event event;

        while(SDL_PollEvent(&event)){
            switch (event.type)
            {
                case SDL_QUIT://pour quitter le programme avec la croix
                    program_lauched= SDL_FALSE;
                    break;

                case SDL_MOUSEBUTTONDOWN:
                    //event.motion.x
                    printf("CLick %dx|%dy \n",event.button.x,event.button.y);
                    break;
            //case SDL_KEYDOWN:
            //    switch (event.key.keysym.sym)
            //    {
            //    case SDLK_b:
            //        printf("b touche");
            //        break;
            //    
            //    default:
            //        break;
            //    }
            //    break;
                default:
                    break;
            }
        }
    }
    //------------------------------------------------------//
    //
    //----------------------------------------------------//

    SDL_RenderPresent(renderer); /*Actualise le rendu*/ 
    //SDL_DestroyTexture(background);
    //-------------------------------------------------//
    //
    //--------- Fin du programme --------//
        /*Fermeture de la fenetre et fin du main*/
    SDL_Destroyed(renderer,window);
    SDL_Quit();
    return EXIT_SUCCESS;
}
