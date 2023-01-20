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
    //char * _nom[12] = {"Charizard","Venusaur","Tortoise","Ariados","Dragonite","Onix","Harbok","Raichu","Alakazam","Pidgeot","Snorlak","Machamp"};
    //char * _SourceFace[12] = {"sprites/Sprite_006_O.png","sprites/Sprite_003_O.png","sprites/Sprite_009_O.png","sprites/Sprite_168_A.png","sprites/Sprite_149_O.png","sprites/Sprite_095_A.png","sprites/Sprite_024_O.png","sprites/Sprite_026_O.png","sprites/Sprite_065_O.png","sprites/Sprite_018_A.png","sprites/Sprite_143_O.png","sprites/Sprite_068_O.png"};
    //char * _SourceDos[12] = {"Sprite_006_dos_OA.png","Sprite_003_dos_OA.png","Sprite_009_dos_OA.png","Sprite_168_dos_OA.png","Sprite_149_dos_OA.png","Sprite_095_dos_OA.png","Sprite_024_dos_OA.png","Sprite_026_dos_OA.png","Sprite_065_dos_OA.png","Sprite_018_dos_OA.png","Sprite_143_dos_OA.png","Sprite_068_dos_OA.png"};
    //int _Width_Face[12]={60,60,56,60,55,60,55,55,54,60,56,56};
    //int _Height_Face[12]={60,60,55,60,55,60,55,54,55,60,56,56};
    //int _Width_Dos[12]={48,48,48,48,46,47,47,46,48,60,47,48};
    //int _Height_Dos[12]={48,38,35,37,44,47,47,48,46,60,34,48};

int main(int arg,char **argv){
    //--------- Initialisation des paramètre de la page -----------//
    SDL_Window * window = NULL;
    SDL_Renderer * renderer = NULL;
    SDL_Event event;
    SDL_Rect pokemonPosition;
    SDL_Rect _background;
    int index = MAIN_MENU;

    //-------------- Initialisation des tableaux de texture -------------//
    //SDL_Texture ** Texture_Background;
    //pokemon_texture * Texture_Pokemon = CreatePokemonTable();
    //--------- Initialisation de la SDL --------//
        /*Verification du retour de la fonction d'initialisation*/
    if(SDL_Init(SDL_INIT_VIDEO) != 0) SDL_ExitWithError("Initialisation SDL Failed");
    //--------- Debut du programme ----------//
    //
    //----------- Creation de la fenètre ---------//
    window = SDL_CreateWindow("PokeMon",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,WINDOW_WIDTH,WINDOW_HEIGTH,0);
        /*Verification de la bonne creation de la fenetre*/
    if(window == NULL) SDL_ExitWithError(" Window creation failed");
    //---------------------------------------------------//
    //
    //--------- Creation du rendu de la page ---------//
    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_SOFTWARE);
        /*Verification de la bonne creation du rendu*/
    if(renderer == NULL) SDL_ExitWithError("Renderer creation failed");

    //--------------- Creation des tableau de texture ---------------//
    //-------------- Initialisation des pokemon --------------//
    pokemon_texture Charizard = initPokemon(renderer,window,"sprites/Sprite_006_O.png",60,60);
    pokemon_texture Vanusaur = initPokemon(renderer,window,"sprites/Sprite_003_O.png",60,60);
    pokemon_texture Tortoise = initPokemon(renderer,window,"sprites/Sprite_009_O.png",56,55);
    pokemon_texture Ariados = initPokemon(renderer,window,"sprites/Sprite_168_A.png",60,60);
    pokemon_texture Dragonite = initPokemon(renderer,window,"sprites/Sprite_149_O.png",55,55);
    pokemon_texture Onix = initPokemon(renderer,window,"sprites/Sprite_095_A.png",60,60);
    pokemon_texture Harbok = initPokemon(renderer,window,"sprites/Sprite_024_O.png",55,55);
    pokemon_texture Raichu = initPokemon(renderer,window,"sprites/Sprite_026_O.png",55,54);
    pokemon_texture Alakazam = initPokemon(renderer,window,"sprites/Sprite_065_O.png",54,55);
    pokemon_texture Pidgeot = initPokemon(renderer,window,"sprites/Sprite_018_A.png",60,60);
    pokemon_texture Snorlak = initPokemon(renderer,window,"sprites/Sprite_143_O.png",56,56);
    pokemon_texture Machamp = initPokemon(renderer,window,"sprites/Sprite_068_O.png",56,56);

    printf("bjr");
    //--------------- Initialisation des textures des Menu ----------------------//
    Background * Texture_Background = initBackgroundTable();
    Background menuPrincipale = initBackground(renderer,window,"sprites/sprite_background_menu.png",800,600);
    Background buttonMenuPricp = initBackground(renderer,window,"sprites/sprite_button_play.png",254,56);
    Background chooseMenuPalyer = initBackground(renderer,window,"sprites/Choose_player_menu.png",800,600);
    Texture_Background = placeBackground(menuPrincipale,Texture_Background);
    Texture_Background = placeBackground(buttonMenuPricp,Texture_Background);
    Texture_Background = placeBackground(chooseMenuPalyer,Texture_Background);
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
    
        /* a mettre en fin animation */
    
    //-----------------------------------------//
    SDL_bool program_lauched = SDL_TRUE;
    //------------------ Apparition du Menu Principal -------------//
    _background.h=Texture_Background[0]->backgroundHeight;
    _background.w=Texture_Background[0]->backgroundWidth;
    _background.x=(WINDOW_WIDTH - Texture_Background[0]->backgroundWidth)/2;
    _background.y=(WINDOW_HEIGTH - Texture_Background[0]->backgroundHeight)/2;
    SDL_RenderCopy(renderer,Texture_Background[0]->background,NULL,&_background);
    //------------------ Apparition du boutton -------------//
    _background.h=Texture_Background[1]->backgroundHeight;
    _background.w=Texture_Background[1]->backgroundWidth;
    _background.x=(WINDOW_WIDTH - Texture_Background[1]->backgroundWidth)/2;
    _background.y=((WINDOW_HEIGTH - Texture_Background[1]->backgroundHeight)/5)*4;
    SDL_RenderCopy(renderer,Texture_Background[1]->background,NULL,&_background);
    //-------------------------------------------------------//
    SDL_RenderPresent(renderer);/*Actualise le rendu*/
    while(program_lauched){
        while(SDL_PollEvent(&event)){
            switch (event.type)
            {
                case SDL_QUIT://pour quitter le programme avec la croix
                    program_lauched= SDL_FALSE;
                    break;

                case SDL_MOUSEMOTION:
                    if(index==CHOOSE_PLAYER_MENU){
                        //coté 90px
                        //haut 200px
                        //separation y 8 px
                        //separation X 26px
                        //button size 184*69
                        //cadre size 249*150
                        //----------------------------- Button Charizard ----------------//
                        if(event.motion.x >=90 && event.motion.x<=274 && event.motion.y>=200 && event.motion.y<=269){
                            printf("la souri est %dx|%dy \n",event.button.x,event.button.y);
                            //------ Affichage de pokemon -----------//
                            pokemonPosition.w=Charizard->pokemon_width_face*2;
                            pokemonPosition.h=Charizard->pokemon_height_face*2;
                            pokemonPosition.x=90+(249/2 - Charizard->pokemon_width_face);          //154.5;
                            pokemonPosition.y=34+(150-Charizard->pokemon_height_face*2);
                            SDL_RenderClear(renderer);
                            limit_fps(frame_limit);
                            _background.h=Texture_Background[2]->backgroundHeight;
                            _background.w=Texture_Background[2]->backgroundWidth;
                            _background.x=Texture_Background[2]->posX;
                            _background.y=Texture_Background[2]->posY;
                            SDL_RenderCopy(renderer,Texture_Background[2]->background,NULL,&_background);
                            SDL_RenderCopy(renderer,Charizard->texture_face,NULL,&pokemonPosition);
                            frame_limit = SDL_GetTicks()+FPS_LIMIT;
                            SDL_RenderPresent(renderer);
                        }
                        //-------------------------- Button Venuzaur --------------------------//
                        if(event.motion.x >= 306 && event.motion.x<=492 && event.motion.y>=200 && event.motion.y<=269){
                            printf("la souri est %dx|%dy Button Venuzaur \n",event.button.x,event.button.y);
                            //------ Affichage de pokemon -----------//
                           pokemonPosition.w=Vanusaur->pokemon_width_face*2;
                            pokemonPosition.h=Vanusaur->pokemon_height_face*2;
                            pokemonPosition.x=90+(249/2 - Vanusaur->pokemon_width_face);
                            pokemonPosition.y=34+(150 - Vanusaur->pokemon_height_face*2);
                            SDL_RenderClear(renderer);
                            limit_fps(frame_limit);
                            _background.h=Texture_Background[2]->backgroundHeight;
                            _background.w=Texture_Background[2]->backgroundWidth;
                            _background.x=Texture_Background[2]->posX;
                            _background.y=Texture_Background[2]->posY;
                            SDL_RenderCopy(renderer,Texture_Background[2]->background,NULL,&_background);
                            SDL_RenderCopy(renderer,Vanusaur->texture_face,NULL,&pokemonPosition);
                            frame_limit = SDL_GetTicks()+FPS_LIMIT;
                            SDL_RenderPresent(renderer);
                        }

                        //-------------------------- Button Totoise ---------------------//
                        if(event.motion.x >= 522 && event.motion.x <= 706 && event.motion.y>=200 && event.motion.y<=269){
                            printf("la souri est %dx|%dy Button Tortoise \n",event.button.x,event.button.y);
                            pokemonPosition.w=Tortoise->pokemon_width_face*2;
                            pokemonPosition.h=Tortoise->pokemon_height_face*2;
                            pokemonPosition.x=90+(249/2 - Tortoise->pokemon_width_face);
                            pokemonPosition.y=34+(145 - Tortoise->pokemon_height_face*2);
                            SDL_RenderClear(renderer);
                            limit_fps(frame_limit);
                            _background.h=Texture_Background[2]->backgroundHeight;
                            _background.w=Texture_Background[2]->backgroundWidth;
                            _background.x=Texture_Background[2]->posX;
                            _background.y=Texture_Background[2]->posY;
                            SDL_RenderCopy(renderer,Texture_Background[2]->background,NULL,&_background);
                            SDL_RenderCopy(renderer,Tortoise->texture_face,NULL,&pokemonPosition);
                            frame_limit = SDL_GetTicks()+FPS_LIMIT;
                            SDL_RenderPresent(renderer);
                        }

                        //-------------------------- Button Ariados ---------------------//
                        if(event.motion.x >=90 && event.motion.x<=274 && event.motion.y>=277 && event.motion.y<=346){
                            printf("la souri est %dx|%dy Button Ariados \n",event.button.x,event.button.y);
                            pokemonPosition.w=Ariados->pokemon_width_face*2;
                            pokemonPosition.h=Ariados->pokemon_height_face*2;
                            pokemonPosition.x=90+(249/2 - Ariados->pokemon_width_face);
                            pokemonPosition.y=34+(150 - Ariados->pokemon_height_face*2);
                            SDL_RenderClear(renderer);
                            limit_fps(frame_limit);
                            _background.h=Texture_Background[2]->backgroundHeight;
                            _background.w=Texture_Background[2]->backgroundWidth;
                            _background.x=Texture_Background[2]->posX;
                            _background.y=Texture_Background[2]->posY;
                            SDL_RenderCopy(renderer,Texture_Background[2]->background,NULL,&_background);
                            SDL_RenderCopy(renderer,Ariados->texture_face,NULL,&pokemonPosition);
                            frame_limit = SDL_GetTicks()+FPS_LIMIT;
                            SDL_RenderPresent(renderer);
                        }

                        //-------------------------- Button Dragonite --------------------//
                        if(event.motion.x >= 306 && event.motion.x<=492 && event.motion.y>=277 && event.motion.y<=346){
                            printf("la souri est %dx|%dy Button Dragonite \n",event.button.x,event.button.y);
                            pokemonPosition.w=Dragonite->pokemon_width_face*2;
                            pokemonPosition.h=Dragonite->pokemon_height_face*2;
                            pokemonPosition.x=90+(249/2 - Dragonite->pokemon_width_face);
                            pokemonPosition.y=34+(145 - Dragonite->pokemon_height_face*2);
                            SDL_RenderClear(renderer);
                            limit_fps(frame_limit);
                            _background.h=Texture_Background[2]->backgroundHeight;
                            _background.w=Texture_Background[2]->backgroundWidth;
                            _background.x=Texture_Background[2]->posX;
                            _background.y=Texture_Background[2]->posY;
                            SDL_RenderCopy(renderer,Texture_Background[2]->background,NULL,&_background);
                            SDL_RenderCopy(renderer,Dragonite->texture_face,NULL,&pokemonPosition);
                            frame_limit = SDL_GetTicks()+FPS_LIMIT;
                            SDL_RenderPresent(renderer);
                        }

                        //-------------------------- Button Onix ---------------------//
                        if(event.motion.x >= 522 && event.motion.x <= 706 && event.motion.y>=277 && event.motion.y<=346){
                            printf("la souri est %dx|%dy Button Onix \n",event.button.x,event.button.y);
                            pokemonPosition.w=Onix->pokemon_width_face*2;
                            pokemonPosition.h=Onix->pokemon_height_face*2;
                            pokemonPosition.x=90+(249/2 - Onix->pokemon_width_face);
                            pokemonPosition.y=34+(145 - Onix->pokemon_height_face*2);
                            SDL_RenderClear(renderer);
                            limit_fps(frame_limit);
                            _background.h=Texture_Background[2]->backgroundHeight;
                            _background.w=Texture_Background[2]->backgroundWidth;
                            _background.x=Texture_Background[2]->posX;
                            _background.y=Texture_Background[2]->posY;
                            SDL_RenderCopy(renderer,Texture_Background[2]->background,NULL,&_background);
                            SDL_RenderCopy(renderer,Onix->texture_face,NULL,&pokemonPosition);
                            frame_limit = SDL_GetTicks()+FPS_LIMIT;
                            SDL_RenderPresent(renderer);
                        }

                        //-------------------------- Button Harbok -----------------------//
                        if(event.motion.x >=90 && event.motion.x<=274 && event.motion.y>=354 && event.motion.y<=423){
                            printf("la souri est %dx|%dy Button harbok \n",event.button.x,event.button.y);
                            pokemonPosition.w=Harbok->pokemon_width_face*2;
                            pokemonPosition.h=Harbok->pokemon_height_face*2;
                            pokemonPosition.x=90+(249/2 - Harbok->pokemon_width_face);
                            pokemonPosition.y=34+(145 - Harbok->pokemon_height_face*2);
                            SDL_RenderClear(renderer);
                            limit_fps(frame_limit);
                            _background.h=Texture_Background[2]->backgroundHeight;
                            _background.w=Texture_Background[2]->backgroundWidth;
                            _background.x=Texture_Background[2]->posX;
                            _background.y=Texture_Background[2]->posY;
                            SDL_RenderCopy(renderer,Texture_Background[2]->background,NULL,&_background);
                            SDL_RenderCopy(renderer,Harbok->texture_face,NULL,&pokemonPosition);
                            frame_limit = SDL_GetTicks()+FPS_LIMIT;
                            SDL_RenderPresent(renderer);
                        }

                        //-------------------------- Button Raichu -----------------------//
                        if(event.motion.x >= 306 && event.motion.x<=492 && event.motion.y>=354 && event.motion.y<=423){
                            printf("la souri est %dx|%dy Button Raichu \n",event.button.x,event.button.y);
                            pokemonPosition.w=Raichu->pokemon_width_face*2;
                            pokemonPosition.h=Raichu->pokemon_height_face*2;
                            pokemonPosition.x=90+(249/2 - Raichu->pokemon_width_face);
                            pokemonPosition.y=34+(150 - Raichu->pokemon_height_face*2);
                            SDL_RenderClear(renderer);
                            limit_fps(frame_limit);
                            _background.h=Texture_Background[2]->backgroundHeight;
                            _background.w=Texture_Background[2]->backgroundWidth;
                            _background.x=Texture_Background[2]->posX;
                            _background.y=Texture_Background[2]->posY;
                            SDL_RenderCopy(renderer,Texture_Background[2]->background,NULL,&_background);
                            SDL_RenderCopy(renderer,Raichu->texture_face,NULL,&pokemonPosition);
                            frame_limit = SDL_GetTicks()+FPS_LIMIT;
                            SDL_RenderPresent(renderer);
                        }

                        //-------------------------- Button Alakazam ----------------------//
                        if(event.motion.x >= 522 && event.motion.x <= 706 && event.motion.y>=354 && event.motion.y<=423){
                            printf("la souri est %dx|%dy Button Alakazam \n",event.button.x,event.button.y);
                            pokemonPosition.w=Alakazam->pokemon_width_face*2;
                            pokemonPosition.h=Alakazam->pokemon_height_face*2;
                            pokemonPosition.x=90+(249/2 - Alakazam->pokemon_width_face);
                            pokemonPosition.y=34+(145 - Alakazam->pokemon_height_face*2);
                            SDL_RenderClear(renderer);
                            limit_fps(frame_limit);
                            _background.h=Texture_Background[2]->backgroundHeight;
                            _background.w=Texture_Background[2]->backgroundWidth;
                            _background.x=Texture_Background[2]->posX;
                            _background.y=Texture_Background[2]->posY;
                            SDL_RenderCopy(renderer,Texture_Background[2]->background,NULL,&_background);
                            SDL_RenderCopy(renderer,Alakazam->texture_face,NULL,&pokemonPosition);
                            frame_limit = SDL_GetTicks()+FPS_LIMIT;
                            SDL_RenderPresent(renderer);
                        }

                        //-------------------------- Button Pidgeot ----------------------//
                        if(event.motion.x >=90 && event.motion.x<=274 && event.motion.y>=431 && event.motion.y<=500){
                            printf("la souri est %dx|%dy Button Pidgeot \n",event.button.x,event.button.y);
                            pokemonPosition.w=Pidgeot->pokemon_width_face*2;
                            pokemonPosition.h=Pidgeot->pokemon_height_face*2;
                            pokemonPosition.x=90+(249/2 - Pidgeot->pokemon_width_face);
                            pokemonPosition.y=34+(150 - Pidgeot->pokemon_height_face*2);
                            SDL_RenderClear(renderer);
                            limit_fps(frame_limit);
                            _background.h=Texture_Background[2]->backgroundHeight;
                            _background.w=Texture_Background[2]->backgroundWidth;
                            _background.x=Texture_Background[2]->posX;
                            _background.y=Texture_Background[2]->posY;
                            SDL_RenderCopy(renderer,Texture_Background[2]->background,NULL,&_background);
                            SDL_RenderCopy(renderer,Pidgeot->texture_face,NULL,&pokemonPosition);
                            frame_limit = SDL_GetTicks()+FPS_LIMIT;
                            SDL_RenderPresent(renderer);
                        }

                        //-------------------------- Button Snorlak ----------------------//
                        if(event.motion.x >= 306 && event.motion.x<=492 && event.motion.y>=431 && event.motion.y<=500){
                            printf("la souri est %dx|%dy Button Snorlak \n",event.button.x,event.button.y);
                            pokemonPosition.w=Snorlak->pokemon_width_face*2;
                            pokemonPosition.h=Snorlak->pokemon_height_face*2;
                            pokemonPosition.x=90+(249/2 - Snorlak->pokemon_width_face);
                            pokemonPosition.y=34+(150 - Snorlak->pokemon_height_face*2);
                            SDL_RenderClear(renderer);
                            limit_fps(frame_limit);
                            _background.h=Texture_Background[2]->backgroundHeight;
                            _background.w=Texture_Background[2]->backgroundWidth;
                            _background.x=Texture_Background[2]->posX;
                            _background.y=Texture_Background[2]->posY;
                            SDL_RenderCopy(renderer,Texture_Background[2]->background,NULL,&_background);
                            SDL_RenderCopy(renderer,Snorlak->texture_face,NULL,&pokemonPosition);
                            frame_limit = SDL_GetTicks()+FPS_LIMIT;
                            SDL_RenderPresent(renderer);
                        }

                        //-------------------------- Button Machamp ---------------------//
                        if(event.motion.x >= 522 && event.motion.x <= 706 && event.motion.y>=431 && event.motion.y<=500){
                            printf("la souri est %dx|%dy Button Machamp \n",event.button.x,event.button.y);
                            pokemonPosition.w=Machamp->pokemon_width_face*2;
                            pokemonPosition.h=Machamp->pokemon_height_face*2;
                            pokemonPosition.x=90+(249/2 - Machamp->pokemon_width_face);
                            pokemonPosition.y=34+(144 - Machamp->pokemon_height_face*2);
                            SDL_RenderClear(renderer);
                            limit_fps(frame_limit);
                            _background.h=Texture_Background[2]->backgroundHeight;
                            _background.w=Texture_Background[2]->backgroundWidth;
                            _background.x=Texture_Background[2]->posX;
                            _background.y=Texture_Background[2]->posY;
                            SDL_RenderCopy(renderer,Texture_Background[2]->background,NULL,&_background);
                            SDL_RenderCopy(renderer,Machamp->texture_face,NULL,&pokemonPosition);
                            frame_limit = SDL_GetTicks()+FPS_LIMIT;
                            SDL_RenderPresent(renderer);
                        }
                    }
                    break;

                case SDL_MOUSEBUTTONDOWN:
                    if(index==MAIN_MENU){
                        if(event.button.x >=273 && event.button.x<=529 && event.button.y>=435.5 && event.button.y<=491.5){
                            printf("CLick sur le boutton %dx|%dy \n",event.button.x,event.button.y);
                            /*Verification de la bonne creation du rendu*/
                            index=CHOOSE_PLAYER_MENU;
                            limit_fps(frame_limit);
                            SDL_RenderClear(renderer);
                            _background.h=Texture_Background[2]->backgroundHeight;
                            _background.w=Texture_Background[2]->backgroundWidth;
                            _background.x=Texture_Background[2]->posX;
                            _background.y=Texture_Background[2]->posY;
                            SDL_RenderCopy(renderer,Texture_Background[2]->background,NULL,&_background);
                            frame_limit = SDL_GetTicks()+FPS_LIMIT;
                            SDL_RenderPresent(renderer);
                        }
                    }
                    //event.motion.x
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
    //-------------------------------------------------//
    //
    //--------- Fin du programme --------//
        /*Fermeture de la fenetre et fin du main*/
    SDL_Destroyed(NULL,NULL,Charizard);
    SDL_Destroyed(NULL,NULL,Vanusaur);
    SDL_Destroyed(NULL,NULL,Tortoise);
    SDL_Destroyed(NULL,NULL,Ariados);
    SDL_Destroyed(NULL,NULL,Dragonite);
    SDL_Destroyed(NULL,NULL,Onix);
    SDL_Destroyed(NULL,NULL,Harbok);
    SDL_Destroyed(NULL,NULL,Raichu);
    SDL_Destroyed(NULL,NULL,Alakazam);
    SDL_Destroyed(NULL,NULL,Pidgeot);
    SDL_Destroyed(NULL,NULL,Snorlak);
    SDL_Destroyed(NULL,NULL,Machamp);
    SDL_DestroyTexture(Texture_Background[0]->background);
    SDL_DestroyTexture(Texture_Background[1]->background);
    SDL_DestroyTexture(Texture_Background[2]->background);

    SDL_Destroyed(renderer,window,NULL);
    SDL_Quit();
    return EXIT_SUCCESS;
}
