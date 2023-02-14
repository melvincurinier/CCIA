#include "graphic.h"
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
    int Character_select=0;
    //----------- Initialisation des paramètre in game & de l'ia -----------//
    
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
    Background chooseMenuPalyer = initBackground(renderer,window,"sprites/Choose_player_menu.png",800,600);
    Background CharizardButtonChoose = initBackground(renderer,window,"sprites/Charizard_button.png",186,69);
    Background VanusaurButtonChoose = initBackground(renderer,window,"sprites/Vanusaur_button.png",186,69);
    Background TortoiseButtonChoose = initBackground(renderer,window,"sprites/Tortoise_button.png",186,69);
    Background AriadosButtonChoose = initBackground(renderer,window,"sprites/Ariados_button.png",186,69);
    Background DragoniteButtonChoose = initBackground(renderer,window,"sprites/Dragonite_button.png",186,69);
    Background OnixButtonChoose = initBackground(renderer,window,"sprites/Onix_Button.png",186,69);
    Background HarbokButtonChoose = initBackground(renderer,window,"sprites/Harbok_Button.png",186,69);
    Background RaichuButtonChoose = initBackground(renderer,window,"sprites/Raichu_Button.png",186,69);
    Background AlakazamButtonChoose = initBackground(renderer,window,"sprites/Alakazam_button.png",186,69);
    Background PidgeotButtonChoose = initBackground(renderer,window,"sprites/Pidgeot_button.png",186,69);
    Background SnorlakButtonChoose = initBackground(renderer,window,"sprites/Snorlak_button.png",186,69);
    Background MachampButtonChoose = initBackground(renderer,window,"sprites/Machamp_button.png",186,69);
    //--------------- Initialisation des textures des Menu ----------------------//
    Background * Texture_Background = initBackgroundTable();
    Background menuPrincipale = initBackground(renderer,window,"sprites/sprite_background_menu.png",800,600);
    Background buttonMenuPricp = initBackground(renderer,window,"sprites/sprite_button_play.png",254,56); 
    Background gameplayTexture = initBackground(renderer,window,"sprites/Gameplay_texture.png",800,600);
    //----------------------------------------------------------------//
    Texture_Background = placeBackground(menuPrincipale,Texture_Background,0);
    Texture_Background = placeBackground(buttonMenuPricp,Texture_Background,1);
    Texture_Background = placeBackground(chooseMenuPalyer,Texture_Background,2);
    Texture_Background = placeBackground(CharizardButtonChoose,Texture_Background,3);
    Texture_Background = placeBackground(VanusaurButtonChoose,Texture_Background,4);
    Texture_Background = placeBackground(TortoiseButtonChoose,Texture_Background,5);
    Texture_Background = placeBackground(AriadosButtonChoose,Texture_Background,6);
    Texture_Background = placeBackground(DragoniteButtonChoose,Texture_Background,7);
    Texture_Background = placeBackground(OnixButtonChoose,Texture_Background,8);
    Texture_Background = placeBackground(HarbokButtonChoose,Texture_Background,9);
    Texture_Background = placeBackground(RaichuButtonChoose,Texture_Background,10);
    Texture_Background = placeBackground(AlakazamButtonChoose,Texture_Background,11);
    Texture_Background = placeBackground(PidgeotButtonChoose,Texture_Background,12);
    Texture_Background = placeBackground(SnorlakButtonChoose,Texture_Background,13);
    Texture_Background = placeBackground(MachampButtonChoose,Texture_Background,14);
    Texture_Background = placeBackground(gameplayTexture,Texture_Background,15);
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
    SDL_RectDef(&_background,Texture_Background[0]->backgroundWidth,Texture_Background[0]->backgroundHeight,(WINDOW_WIDTH - Texture_Background[0]->backgroundWidth)/2,(WINDOW_HEIGTH - Texture_Background[0]->backgroundHeight)/2);
    SDL_RenderCopy(renderer,Texture_Background[0]->background,NULL,&_background);
    //------------------ Apparition du boutton -------------//
    SDL_RectDef(&_background,Texture_Background[1]->backgroundWidth,Texture_Background[1]->backgroundHeight,273,500);
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
                        if(event.motion.x >=90 && event.motion.x<=274 && event.motion.y>=200 && event.motion.y<=269 && Charizard->select == 0){
                            printf("la souri est %dx|%dy \n",event.button.x,event.button.y);
                            //------ Affichage de pokemon -----------//
                            SDL_RectDef(&pokemonPosition,Charizard->pokemon_width_face*2,Charizard->pokemon_height_face*2,90+(249/2 - Charizard->pokemon_width_face),34+(150-Charizard->pokemon_height_face*2));
                            SDL_RenderClear(renderer);
                            limit_fps(frame_limit);
                            SDL_RectDef(&_background,Texture_Background[2]->backgroundWidth,Texture_Background[2]->backgroundHeight,(WINDOW_WIDTH - Texture_Background[2]->backgroundWidth)/2,(WINDOW_HEIGTH - Texture_Background[2]->backgroundHeight)/2);
                            SDL_RenderCopy(renderer,Texture_Background[2]->background,NULL,&_background);
                            SDL_RenderCopy(renderer,Charizard->texture_face,NULL,&pokemonPosition);
                            if(Vanusaur->select == 1){
                                SDL_RectDef(&_background,Texture_Background[4]->backgroundWidth,Texture_Background[4]->backgroundHeight,306,200);
                                SDL_RenderCopy(renderer,Texture_Background[4]->background,NULL,&_background);
                            }
                            if(Tortoise->select == 1){
                                SDL_RectDef(&_background,Texture_Background[5]->backgroundWidth,Texture_Background[5]->backgroundHeight,522,200);
                                SDL_RenderCopy(renderer,Texture_Background[5]->background,NULL,&_background);
                            }
                            if(Ariados->select == 1){
                                SDL_RectDef(&_background,Texture_Background[6]->backgroundWidth,Texture_Background[6]->backgroundHeight,90,277);
                                SDL_RenderCopy(renderer,Texture_Background[6]->background,NULL,&_background);
                            }
                            if(Dragonite->select == 1){
                                SDL_RectDef(&_background,Texture_Background[7]->backgroundWidth,Texture_Background[7]->backgroundHeight,306,277);
                                SDL_RenderCopy(renderer,Texture_Background[7]->background,NULL,&_background);
                            }
                            if(Onix->select == 1){
                                SDL_RectDef(&_background,Texture_Background[8]->backgroundWidth,Texture_Background[8]->backgroundHeight,522,277);
                                SDL_RenderCopy(renderer,Texture_Background[8]->background,NULL,&_background);
                            }
                            if(Harbok->select == 1){
                                SDL_RectDef(&_background,Texture_Background[9]->backgroundWidth,Texture_Background[9]->backgroundHeight,90,354);
                                SDL_RenderCopy(renderer,Texture_Background[9]->background,NULL,&_background);
                            }
                            if(Raichu->select == 1){
                                SDL_RectDef(&_background,Texture_Background[10]->backgroundWidth,Texture_Background[10]->backgroundHeight,306,354);
                                SDL_RenderCopy(renderer,Texture_Background[10]->background,NULL,&_background);
                            }
                            if(Alakazam->select == 1){
                                SDL_RectDef(&_background,Texture_Background[11]->backgroundWidth,Texture_Background[11]->backgroundHeight,522,354);
                                SDL_RenderCopy(renderer,Texture_Background[11]->background,NULL,&_background);
                            }
                            if(Pidgeot->select == 1){
                                SDL_RectDef(&_background,Texture_Background[12]->backgroundWidth,Texture_Background[10]->backgroundHeight,90,431);
                                SDL_RenderCopy(renderer,Texture_Background[12]->background,NULL,&_background); 
                            }
                            if(Snorlak->select==1){
                                SDL_RectDef(&_background,Texture_Background[13]->backgroundWidth,Texture_Background[13]->backgroundHeight,306,431);
                                SDL_RenderCopy(renderer,Texture_Background[13]->background,NULL,&_background);
                            }
                            if(Machamp->select ==1){
                                SDL_RectDef(&_background,Texture_Background[14]->backgroundWidth,Texture_Background[10]->backgroundHeight,522,431);
                                SDL_RenderCopy(renderer,Texture_Background[14]->background,NULL,&_background); 
                            }
                            frame_limit = SDL_GetTicks()+FPS_LIMIT;
                            SDL_RenderPresent(renderer);
                        }
                        //-------------------------- Button Venuzaur --------------------------//
                        if(event.motion.x >= 306 && event.motion.x<=492 && event.motion.y>=200 && event.motion.y<=269 && Vanusaur->select == 0){
                            printf("la souri est %dx|%dy Button Venuzaur \n",event.button.x,event.button.y);
                            //------ Affichage de pokemon -----------//
                            SDL_RectDef(&pokemonPosition,Vanusaur->pokemon_width_face*2,Vanusaur->pokemon_height_face*2,90+(249/2 - Vanusaur->pokemon_width_face),34+(150 - Vanusaur->pokemon_height_face*2));
                            SDL_RenderClear(renderer);
                            limit_fps(frame_limit);
                            SDL_RectDef(&_background,Texture_Background[2]->backgroundWidth,Texture_Background[2]->backgroundHeight,(WINDOW_WIDTH - Texture_Background[2]->backgroundWidth)/2,(WINDOW_HEIGTH - Texture_Background[2]->backgroundHeight)/2);
                            SDL_RenderCopy(renderer,Texture_Background[2]->background,NULL,&_background);
                            SDL_RenderCopy(renderer,Vanusaur->texture_face,NULL,&pokemonPosition);
                            if(Charizard->select == 1){
                                SDL_RectDef(&_background,Texture_Background[3]->backgroundWidth,Texture_Background[3]->backgroundHeight,90,200);
                                SDL_RenderCopy(renderer,Texture_Background[3]->background,NULL,&_background);
                            }
                            if(Tortoise->select == 1){
                                SDL_RectDef(&_background,Texture_Background[5]->backgroundWidth,Texture_Background[5]->backgroundHeight,522,200);
                                SDL_RenderCopy(renderer,Texture_Background[5]->background,NULL,&_background);
                            }
                            if(Ariados->select == 1){
                                SDL_RectDef(&_background,Texture_Background[6]->backgroundWidth,Texture_Background[6]->backgroundHeight,90,277);
                                SDL_RenderCopy(renderer,Texture_Background[6]->background,NULL,&_background);
                            }
                            if(Dragonite->select == 1){
                                SDL_RectDef(&_background,Texture_Background[7]->backgroundWidth,Texture_Background[7]->backgroundHeight,306,277);
                                SDL_RenderCopy(renderer,Texture_Background[7]->background,NULL,&_background);
                            }
                            if(Onix->select == 1){
                                SDL_RectDef(&_background,Texture_Background[8]->backgroundWidth,Texture_Background[8]->backgroundHeight,522,277);
                                SDL_RenderCopy(renderer,Texture_Background[8]->background,NULL,&_background);
                            }
                            if(Harbok->select == 1){
                                SDL_RectDef(&_background,Texture_Background[9]->backgroundWidth,Texture_Background[9]->backgroundHeight,90,354);
                                SDL_RenderCopy(renderer,Texture_Background[9]->background,NULL,&_background);
                            }
                            if(Raichu->select == 1){
                                SDL_RectDef(&_background,Texture_Background[10]->backgroundWidth,Texture_Background[10]->backgroundHeight,306,354);
                                SDL_RenderCopy(renderer,Texture_Background[10]->background,NULL,&_background);
                            }
                            if(Alakazam->select == 1){
                                SDL_RectDef(&_background,Texture_Background[11]->backgroundWidth,Texture_Background[11]->backgroundHeight,522,354);
                                SDL_RenderCopy(renderer,Texture_Background[11]->background,NULL,&_background);
                            }
                            if(Pidgeot->select == 1){
                                SDL_RectDef(&_background,Texture_Background[12]->backgroundWidth,Texture_Background[10]->backgroundHeight,90,431);
                                SDL_RenderCopy(renderer,Texture_Background[12]->background,NULL,&_background); 
                            }
                            if(Snorlak->select==1){
                                SDL_RectDef(&_background,Texture_Background[13]->backgroundWidth,Texture_Background[13]->backgroundHeight,306,431);
                                SDL_RenderCopy(renderer,Texture_Background[13]->background,NULL,&_background);
                            }
                            if(Machamp->select ==1){
                                SDL_RectDef(&_background,Texture_Background[14]->backgroundWidth,Texture_Background[10]->backgroundHeight,522,431);
                                SDL_RenderCopy(renderer,Texture_Background[14]->background,NULL,&_background); 
                            }
                            frame_limit = SDL_GetTicks()+FPS_LIMIT;
                            SDL_RenderPresent(renderer);
                        }

                        //-------------------------- Button Totoise ---------------------//
                        if(event.motion.x >= 522 && event.motion.x <= 706 && event.motion.y>=200 && event.motion.y<=269 && Tortoise->select == 0){
                            printf("la souri est %dx|%dy Button Tortoise \n",event.button.x,event.button.y);
                            SDL_RectDef(&pokemonPosition,Tortoise->pokemon_width_face*2,Tortoise->pokemon_height_face*2,90+(249/2 - Tortoise->pokemon_width_face),34+(145 - Tortoise->pokemon_height_face*2));
                            SDL_RenderClear(renderer);
                            limit_fps(frame_limit);
                            SDL_RectDef(&_background,Texture_Background[2]->backgroundWidth,Texture_Background[2]->backgroundHeight,(WINDOW_WIDTH - Texture_Background[2]->backgroundWidth)/2,(WINDOW_HEIGTH - Texture_Background[2]->backgroundHeight)/2);
                            SDL_RenderCopy(renderer,Texture_Background[2]->background,NULL,&_background);
                            SDL_RenderCopy(renderer,Tortoise->texture_face,NULL,&pokemonPosition);
                            if(Charizard->select == 1){
                                SDL_RectDef(&_background,Texture_Background[3]->backgroundWidth,Texture_Background[3]->backgroundHeight,90,200);
                                SDL_RenderCopy(renderer,Texture_Background[3]->background,NULL,&_background);
                            }
                            if(Vanusaur->select == 1){
                                SDL_RectDef(&_background,Texture_Background[4]->backgroundWidth,Texture_Background[4]->backgroundHeight,306,200);
                                SDL_RenderCopy(renderer,Texture_Background[4]->background,NULL,&_background);
                            }
                            if(Ariados->select == 1){
                                SDL_RectDef(&_background,Texture_Background[6]->backgroundWidth,Texture_Background[6]->backgroundHeight,90,277);
                                SDL_RenderCopy(renderer,Texture_Background[6]->background,NULL,&_background);
                            }
                            if(Dragonite->select == 1){
                                SDL_RectDef(&_background,Texture_Background[7]->backgroundWidth,Texture_Background[7]->backgroundHeight,306,277);
                                SDL_RenderCopy(renderer,Texture_Background[7]->background,NULL,&_background);
                            }
                            if(Onix->select == 1){
                                SDL_RectDef(&_background,Texture_Background[8]->backgroundWidth,Texture_Background[8]->backgroundHeight,522,277);
                                SDL_RenderCopy(renderer,Texture_Background[8]->background,NULL,&_background);
                            }
                            if(Harbok->select == 1){
                                SDL_RectDef(&_background,Texture_Background[9]->backgroundWidth,Texture_Background[9]->backgroundHeight,90,354);
                                SDL_RenderCopy(renderer,Texture_Background[9]->background,NULL,&_background);
                            }
                            if(Raichu->select == 1){
                                SDL_RectDef(&_background,Texture_Background[10]->backgroundWidth,Texture_Background[10]->backgroundHeight,306,354);
                                SDL_RenderCopy(renderer,Texture_Background[10]->background,NULL,&_background);
                            }
                            if(Alakazam->select == 1){
                                SDL_RectDef(&_background,Texture_Background[11]->backgroundWidth,Texture_Background[11]->backgroundHeight,522,354);
                                SDL_RenderCopy(renderer,Texture_Background[11]->background,NULL,&_background);
                            }
                            if(Pidgeot->select == 1){
                                SDL_RectDef(&_background,Texture_Background[12]->backgroundWidth,Texture_Background[10]->backgroundHeight,90,431);
                                SDL_RenderCopy(renderer,Texture_Background[12]->background,NULL,&_background); 
                            }
                            if(Snorlak->select==1){
                                SDL_RectDef(&_background,Texture_Background[13]->backgroundWidth,Texture_Background[13]->backgroundHeight,306,431);
                                SDL_RenderCopy(renderer,Texture_Background[13]->background,NULL,&_background);
                            }
                            if(Machamp->select ==1){
                                SDL_RectDef(&_background,Texture_Background[14]->backgroundWidth,Texture_Background[10]->backgroundHeight,522,431);
                                SDL_RenderCopy(renderer,Texture_Background[14]->background,NULL,&_background); 
                            }
                            frame_limit = SDL_GetTicks()+FPS_LIMIT;
                            SDL_RenderPresent(renderer);
                        }

                        //-------------------------- Button Ariados ---------------------//
                        if(event.motion.x >=90 && event.motion.x<=274 && event.motion.y>=277 && event.motion.y<=346 && Ariados->select == 0){
                            printf("la souri est %dx|%dy Button Ariados \n",event.button.x,event.button.y);
                            SDL_RectDef(&pokemonPosition,Ariados->pokemon_width_face*2,Ariados->pokemon_height_face*2,90+(249/2 - Ariados->pokemon_width_face),34+(150 - Ariados->pokemon_height_face*2));
                            SDL_RenderClear(renderer);
                            limit_fps(frame_limit);
                            SDL_RectDef(&_background,Texture_Background[2]->backgroundWidth,Texture_Background[2]->backgroundHeight,(WINDOW_WIDTH - Texture_Background[2]->backgroundWidth)/2,(WINDOW_HEIGTH - Texture_Background[2]->backgroundHeight)/2);
                            SDL_RenderCopy(renderer,Texture_Background[2]->background,NULL,&_background);
                            SDL_RenderCopy(renderer,Ariados->texture_face,NULL,&pokemonPosition);
                            if(Charizard->select == 1){
                                SDL_RectDef(&_background,Texture_Background[3]->backgroundWidth,Texture_Background[3]->backgroundHeight,90,200);
                                SDL_RenderCopy(renderer,Texture_Background[3]->background,NULL,&_background);
                            }
                            if(Vanusaur->select == 1){
                                SDL_RectDef(&_background,Texture_Background[4]->backgroundWidth,Texture_Background[4]->backgroundHeight,306,200);
                                SDL_RenderCopy(renderer,Texture_Background[4]->background,NULL,&_background);
                            }
                            if(Tortoise->select == 1){
                                SDL_RectDef(&_background,Texture_Background[5]->backgroundWidth,Texture_Background[5]->backgroundHeight,522,200);
                                SDL_RenderCopy(renderer,Texture_Background[5]->background,NULL,&_background);
                            }
                            if(Dragonite->select == 1){
                                SDL_RectDef(&_background,Texture_Background[7]->backgroundWidth,Texture_Background[7]->backgroundHeight,306,277);
                                SDL_RenderCopy(renderer,Texture_Background[7]->background,NULL,&_background);
                            }
                            if(Onix->select == 1){
                                SDL_RectDef(&_background,Texture_Background[8]->backgroundWidth,Texture_Background[8]->backgroundHeight,522,277);
                                SDL_RenderCopy(renderer,Texture_Background[8]->background,NULL,&_background);
                            }
                            if(Harbok->select == 1){
                                SDL_RectDef(&_background,Texture_Background[9]->backgroundWidth,Texture_Background[9]->backgroundHeight,90,354);
                                SDL_RenderCopy(renderer,Texture_Background[9]->background,NULL,&_background);
                            }
                            if(Raichu->select == 1){
                                SDL_RectDef(&_background,Texture_Background[10]->backgroundWidth,Texture_Background[10]->backgroundHeight,306,354);
                                SDL_RenderCopy(renderer,Texture_Background[10]->background,NULL,&_background);
                            }
                            if(Alakazam->select == 1){
                                SDL_RectDef(&_background,Texture_Background[11]->backgroundWidth,Texture_Background[11]->backgroundHeight,522,354);
                                SDL_RenderCopy(renderer,Texture_Background[11]->background,NULL,&_background);
                            }
                            if(Pidgeot->select == 1){
                                SDL_RectDef(&_background,Texture_Background[12]->backgroundWidth,Texture_Background[10]->backgroundHeight,90,431);
                                SDL_RenderCopy(renderer,Texture_Background[12]->background,NULL,&_background); 
                            }
                            if(Snorlak->select==1){
                                SDL_RectDef(&_background,Texture_Background[13]->backgroundWidth,Texture_Background[13]->backgroundHeight,306,431);
                                SDL_RenderCopy(renderer,Texture_Background[13]->background,NULL,&_background);
                            }
                            if(Machamp->select ==1){
                                SDL_RectDef(&_background,Texture_Background[14]->backgroundWidth,Texture_Background[10]->backgroundHeight,522,431);
                                SDL_RenderCopy(renderer,Texture_Background[14]->background,NULL,&_background); 
                            }
                            frame_limit = SDL_GetTicks()+FPS_LIMIT;
                            SDL_RenderPresent(renderer);
                        }

                        //-------------------------- Button Dragonite --------------------//
                        if(event.motion.x >= 306 && event.motion.x<=492 && event.motion.y>=277 && event.motion.y<=346 && Dragonite->select==0){
                            printf("la souri est %dx|%dy Button Dragonite \n",event.button.x,event.button.y);
                            SDL_RectDef(&pokemonPosition,Dragonite->pokemon_width_face*2,Dragonite->pokemon_height_face*2,90+(249/2 - Dragonite->pokemon_width_face),34+(145 - Dragonite->pokemon_height_face*2));
                            SDL_RenderClear(renderer);
                            limit_fps(frame_limit);
                            SDL_RectDef(&_background,Texture_Background[2]->backgroundWidth,Texture_Background[2]->backgroundHeight,(WINDOW_WIDTH - Texture_Background[2]->backgroundWidth)/2,(WINDOW_HEIGTH - Texture_Background[2]->backgroundHeight)/2);
                            SDL_RenderCopy(renderer,Texture_Background[2]->background,NULL,&_background);
                            SDL_RenderCopy(renderer,Dragonite->texture_face,NULL,&pokemonPosition);
                            if(Charizard->select == 1){
                                SDL_RectDef(&_background,Texture_Background[3]->backgroundWidth,Texture_Background[3]->backgroundHeight,90,200);
                                SDL_RenderCopy(renderer,Texture_Background[3]->background,NULL,&_background);
                            }
                            if(Vanusaur->select == 1){
                                SDL_RectDef(&_background,Texture_Background[4]->backgroundWidth,Texture_Background[4]->backgroundHeight,306,200);
                                SDL_RenderCopy(renderer,Texture_Background[4]->background,NULL,&_background);
                            }
                            if(Tortoise->select == 1){
                                SDL_RectDef(&_background,Texture_Background[5]->backgroundWidth,Texture_Background[5]->backgroundHeight,522,200);
                                SDL_RenderCopy(renderer,Texture_Background[5]->background,NULL,&_background);
                            }
                            if(Ariados->select == 1){
                                SDL_RectDef(&_background,Texture_Background[6]->backgroundWidth,Texture_Background[6]->backgroundHeight,90,277);
                                SDL_RenderCopy(renderer,Texture_Background[6]->background,NULL,&_background);
                            }
                            if(Onix->select == 1){
                                SDL_RectDef(&_background,Texture_Background[8]->backgroundWidth,Texture_Background[8]->backgroundHeight,522,277);
                                SDL_RenderCopy(renderer,Texture_Background[8]->background,NULL,&_background);
                            }
                            if(Harbok->select == 1){
                                SDL_RectDef(&_background,Texture_Background[9]->backgroundWidth,Texture_Background[9]->backgroundHeight,90,354);
                                SDL_RenderCopy(renderer,Texture_Background[9]->background,NULL,&_background);
                            }
                            if(Raichu->select == 1){
                                SDL_RectDef(&_background,Texture_Background[10]->backgroundWidth,Texture_Background[10]->backgroundHeight,306,354);
                                SDL_RenderCopy(renderer,Texture_Background[10]->background,NULL,&_background);
                            }
                            if(Alakazam->select == 1){
                                SDL_RectDef(&_background,Texture_Background[11]->backgroundWidth,Texture_Background[11]->backgroundHeight,522,354);
                                SDL_RenderCopy(renderer,Texture_Background[11]->background,NULL,&_background);
                            }
                            if(Pidgeot->select == 1){
                                SDL_RectDef(&_background,Texture_Background[12]->backgroundWidth,Texture_Background[10]->backgroundHeight,90,431);
                                SDL_RenderCopy(renderer,Texture_Background[12]->background,NULL,&_background); 
                            }
                            if(Snorlak->select==1){
                                SDL_RectDef(&_background,Texture_Background[13]->backgroundWidth,Texture_Background[13]->backgroundHeight,306,431);
                                SDL_RenderCopy(renderer,Texture_Background[13]->background,NULL,&_background);
                            }
                            if(Machamp->select ==1){
                                SDL_RectDef(&_background,Texture_Background[14]->backgroundWidth,Texture_Background[10]->backgroundHeight,522,431);
                                SDL_RenderCopy(renderer,Texture_Background[14]->background,NULL,&_background); 
                            }
                            frame_limit = SDL_GetTicks()+FPS_LIMIT;
                            SDL_RenderPresent(renderer);
                        }

                        //-------------------------- Button Onix ---------------------//
                        if(event.motion.x >= 522 && event.motion.x <= 706 && event.motion.y>=277 && event.motion.y<=346 && Onix->select==0){
                            printf("la souri est %dx|%dy Button Onix \n",event.button.x,event.button.y);
                            SDL_RectDef(&pokemonPosition,Onix->pokemon_width_face*2,Onix->pokemon_height_face*2,90+(249/2 - Onix->pokemon_width_face),34+(145 - Onix->pokemon_height_face*2));
                            SDL_RenderClear(renderer);
                            limit_fps(frame_limit);
                            SDL_RectDef(&_background,Texture_Background[2]->backgroundWidth,Texture_Background[2]->backgroundHeight,(WINDOW_WIDTH - Texture_Background[2]->backgroundWidth)/2,(WINDOW_HEIGTH - Texture_Background[2]->backgroundHeight)/2);
                            SDL_RenderCopy(renderer,Texture_Background[2]->background,NULL,&_background);
                            SDL_RenderCopy(renderer,Onix->texture_face,NULL,&pokemonPosition);
                            if(Charizard->select == 1){
                                SDL_RectDef(&_background,Texture_Background[3]->backgroundWidth,Texture_Background[3]->backgroundHeight,90,200);
                                SDL_RenderCopy(renderer,Texture_Background[3]->background,NULL,&_background);
                            }
                            if(Vanusaur->select == 1){
                                SDL_RectDef(&_background,Texture_Background[4]->backgroundWidth,Texture_Background[4]->backgroundHeight,306,200);
                                SDL_RenderCopy(renderer,Texture_Background[4]->background,NULL,&_background);
                            }
                            if(Tortoise->select == 1){
                                SDL_RectDef(&_background,Texture_Background[5]->backgroundWidth,Texture_Background[5]->backgroundHeight,522,200);
                                SDL_RenderCopy(renderer,Texture_Background[5]->background,NULL,&_background);
                            }
                            if(Ariados->select == 1){
                                SDL_RectDef(&_background,Texture_Background[6]->backgroundWidth,Texture_Background[6]->backgroundHeight,90,277);
                                SDL_RenderCopy(renderer,Texture_Background[6]->background,NULL,&_background);
                            }
                            if(Dragonite->select == 1){
                                SDL_RectDef(&_background,Texture_Background[7]->backgroundWidth,Texture_Background[7]->backgroundHeight,306,277);
                                SDL_RenderCopy(renderer,Texture_Background[7]->background,NULL,&_background);
                            }
                            if(Harbok->select == 1){
                                SDL_RectDef(&_background,Texture_Background[9]->backgroundWidth,Texture_Background[9]->backgroundHeight,90,354);
                                SDL_RenderCopy(renderer,Texture_Background[9]->background,NULL,&_background);
                            }
                            if(Raichu->select == 1){
                                SDL_RectDef(&_background,Texture_Background[10]->backgroundWidth,Texture_Background[10]->backgroundHeight,306,354);
                                SDL_RenderCopy(renderer,Texture_Background[10]->background,NULL,&_background);
                            }
                            if(Alakazam->select == 1){
                                SDL_RectDef(&_background,Texture_Background[11]->backgroundWidth,Texture_Background[11]->backgroundHeight,522,354);
                                SDL_RenderCopy(renderer,Texture_Background[11]->background,NULL,&_background);
                            }
                            if(Pidgeot->select == 1){
                                SDL_RectDef(&_background,Texture_Background[12]->backgroundWidth,Texture_Background[10]->backgroundHeight,90,431);
                                SDL_RenderCopy(renderer,Texture_Background[12]->background,NULL,&_background); 
                            }
                            if(Snorlak->select==1){
                                SDL_RectDef(&_background,Texture_Background[13]->backgroundWidth,Texture_Background[13]->backgroundHeight,306,431);
                                SDL_RenderCopy(renderer,Texture_Background[13]->background,NULL,&_background);
                            }
                            if(Machamp->select ==1){
                                SDL_RectDef(&_background,Texture_Background[14]->backgroundWidth,Texture_Background[10]->backgroundHeight,522,431);
                                SDL_RenderCopy(renderer,Texture_Background[14]->background,NULL,&_background); 
                            }
                            frame_limit = SDL_GetTicks()+FPS_LIMIT;
                            SDL_RenderPresent(renderer);
                        }

                        //-------------------------- Button Harbok -----------------------//
                        if(event.motion.x >=90 && event.motion.x<=274 && event.motion.y>=354 && event.motion.y<=423 && Harbok->select==0){
                            printf("la souri est %dx|%dy Button harbok \n",event.button.x,event.button.y);
                            SDL_RectDef(&pokemonPosition,Harbok->pokemon_width_face*2,Harbok->pokemon_height_face*2,90+(249/2 - Harbok->pokemon_width_face),34+(145 - Harbok->pokemon_height_face*2));
                            SDL_RenderClear(renderer);
                            limit_fps(frame_limit);
                            SDL_RectDef(&_background,Texture_Background[2]->backgroundWidth,Texture_Background[2]->backgroundHeight,(WINDOW_WIDTH - Texture_Background[2]->backgroundWidth)/2,(WINDOW_HEIGTH - Texture_Background[2]->backgroundHeight)/2);
                            SDL_RenderCopy(renderer,Texture_Background[2]->background,NULL,&_background);
                            SDL_RenderCopy(renderer,Harbok->texture_face,NULL,&pokemonPosition);
                            if(Charizard->select == 1){
                                SDL_RectDef(&_background,Texture_Background[3]->backgroundWidth,Texture_Background[3]->backgroundHeight,90,200);
                                SDL_RenderCopy(renderer,Texture_Background[3]->background,NULL,&_background);
                            }
                            if(Vanusaur->select == 1){
                                SDL_RectDef(&_background,Texture_Background[4]->backgroundWidth,Texture_Background[4]->backgroundHeight,306,200);
                                SDL_RenderCopy(renderer,Texture_Background[4]->background,NULL,&_background);
                            }
                            if(Tortoise->select == 1){
                                SDL_RectDef(&_background,Texture_Background[5]->backgroundWidth,Texture_Background[5]->backgroundHeight,522,200);
                                SDL_RenderCopy(renderer,Texture_Background[5]->background,NULL,&_background);
                            }
                            if(Ariados->select == 1){
                                SDL_RectDef(&_background,Texture_Background[6]->backgroundWidth,Texture_Background[6]->backgroundHeight,90,277);
                                SDL_RenderCopy(renderer,Texture_Background[6]->background,NULL,&_background);
                            }
                            if(Dragonite->select == 1){
                                SDL_RectDef(&_background,Texture_Background[7]->backgroundWidth,Texture_Background[7]->backgroundHeight,306,277);
                                SDL_RenderCopy(renderer,Texture_Background[7]->background,NULL,&_background);
                            }
                            if(Onix->select == 1){
                                SDL_RectDef(&_background,Texture_Background[8]->backgroundWidth,Texture_Background[8]->backgroundHeight,522,277);
                                SDL_RenderCopy(renderer,Texture_Background[8]->background,NULL,&_background);
                            }
                            if(Raichu->select == 1){
                                SDL_RectDef(&_background,Texture_Background[10]->backgroundWidth,Texture_Background[10]->backgroundHeight,306,354);
                                SDL_RenderCopy(renderer,Texture_Background[10]->background,NULL,&_background);
                            }
                            if(Alakazam->select == 1){
                                SDL_RectDef(&_background,Texture_Background[11]->backgroundWidth,Texture_Background[11]->backgroundHeight,522,354);
                                SDL_RenderCopy(renderer,Texture_Background[11]->background,NULL,&_background);
                            }
                            if(Pidgeot->select == 1){
                                SDL_RectDef(&_background,Texture_Background[12]->backgroundWidth,Texture_Background[10]->backgroundHeight,90,431);
                                SDL_RenderCopy(renderer,Texture_Background[12]->background,NULL,&_background); 
                            }
                            if(Snorlak->select==1){
                                SDL_RectDef(&_background,Texture_Background[13]->backgroundWidth,Texture_Background[13]->backgroundHeight,306,431);
                                SDL_RenderCopy(renderer,Texture_Background[13]->background,NULL,&_background);
                            }
                            if(Machamp->select ==1){
                                SDL_RectDef(&_background,Texture_Background[14]->backgroundWidth,Texture_Background[10]->backgroundHeight,522,431);
                                SDL_RenderCopy(renderer,Texture_Background[14]->background,NULL,&_background); 
                            }
                            frame_limit = SDL_GetTicks()+FPS_LIMIT;
                            SDL_RenderPresent(renderer);
                        }

                        //-------------------------- Button Raichu -----------------------//
                        if(event.motion.x >= 306 && event.motion.x<=492 && event.motion.y>=354 && event.motion.y<=423 && Raichu->select==0){
                            printf("la souri est %dx|%dy Button Raichu \n",event.button.x,event.button.y);
                            SDL_RectDef(&pokemonPosition,Raichu->pokemon_width_face*2,Raichu->pokemon_height_face*2,90+(249/2 - Raichu->pokemon_width_face),34+(150 - Raichu->pokemon_height_face*2));
                            SDL_RenderClear(renderer);
                            limit_fps(frame_limit);
                            SDL_RectDef(&_background,Texture_Background[2]->backgroundWidth,Texture_Background[2]->backgroundHeight,(WINDOW_WIDTH - Texture_Background[2]->backgroundWidth)/2,(WINDOW_HEIGTH - Texture_Background[2]->backgroundHeight)/2);
                            SDL_RenderCopy(renderer,Texture_Background[2]->background,NULL,&_background);
                            SDL_RenderCopy(renderer,Raichu->texture_face,NULL,&pokemonPosition);
                            if(Charizard->select == 1){
                                SDL_RectDef(&_background,Texture_Background[3]->backgroundWidth,Texture_Background[3]->backgroundHeight,90,200);
                                SDL_RenderCopy(renderer,Texture_Background[3]->background,NULL,&_background);
                            }
                            if(Vanusaur->select == 1){
                                SDL_RectDef(&_background,Texture_Background[4]->backgroundWidth,Texture_Background[4]->backgroundHeight,306,200);
                                SDL_RenderCopy(renderer,Texture_Background[4]->background,NULL,&_background);
                            }
                            if(Tortoise->select == 1){
                                SDL_RectDef(&_background,Texture_Background[5]->backgroundWidth,Texture_Background[5]->backgroundHeight,522,200);
                                SDL_RenderCopy(renderer,Texture_Background[5]->background,NULL,&_background);
                            }
                            if(Ariados->select == 1){
                                SDL_RectDef(&_background,Texture_Background[6]->backgroundWidth,Texture_Background[6]->backgroundHeight,90,277);
                                SDL_RenderCopy(renderer,Texture_Background[6]->background,NULL,&_background);
                            }
                            if(Dragonite->select == 1){
                                SDL_RectDef(&_background,Texture_Background[7]->backgroundWidth,Texture_Background[7]->backgroundHeight,306,277);
                                SDL_RenderCopy(renderer,Texture_Background[7]->background,NULL,&_background);
                            }
                            if(Onix->select == 1){
                                SDL_RectDef(&_background,Texture_Background[8]->backgroundWidth,Texture_Background[8]->backgroundHeight,522,277);
                                SDL_RenderCopy(renderer,Texture_Background[8]->background,NULL,&_background);
                            }
                            if(Harbok->select == 1){
                                SDL_RectDef(&_background,Texture_Background[9]->backgroundWidth,Texture_Background[9]->backgroundHeight,90,354);
                                SDL_RenderCopy(renderer,Texture_Background[9]->background,NULL,&_background);
                            }
                            if(Alakazam->select == 1){
                                SDL_RectDef(&_background,Texture_Background[11]->backgroundWidth,Texture_Background[11]->backgroundHeight,522,354);
                                SDL_RenderCopy(renderer,Texture_Background[11]->background,NULL,&_background);
                            }
                            if(Pidgeot->select == 1){
                                SDL_RectDef(&_background,Texture_Background[12]->backgroundWidth,Texture_Background[10]->backgroundHeight,90,431);
                                SDL_RenderCopy(renderer,Texture_Background[12]->background,NULL,&_background); 
                            }
                            if(Snorlak->select==1){
                                SDL_RectDef(&_background,Texture_Background[13]->backgroundWidth,Texture_Background[13]->backgroundHeight,306,431);
                                SDL_RenderCopy(renderer,Texture_Background[13]->background,NULL,&_background);
                            }
                            if(Machamp->select ==1){
                                SDL_RectDef(&_background,Texture_Background[14]->backgroundWidth,Texture_Background[10]->backgroundHeight,522,431);
                                SDL_RenderCopy(renderer,Texture_Background[14]->background,NULL,&_background); 
                            }
                            frame_limit = SDL_GetTicks()+FPS_LIMIT;
                            SDL_RenderPresent(renderer);
                        }

                        //-------------------------- Button Alakazam ----------------------//
                        if(event.motion.x >= 522 && event.motion.x <= 706 && event.motion.y>=354 && event.motion.y<=423 && Alakazam->select==0){
                            printf("la souri est %dx|%dy Button Alakazam \n",event.button.x,event.button.y);
                            SDL_RectDef(&pokemonPosition,Alakazam->pokemon_width_face*2,Alakazam->pokemon_height_face*2,90+(249/2 - Alakazam->pokemon_width_face),34+(145 - Alakazam->pokemon_height_face*2));
                            SDL_RenderClear(renderer);
                            limit_fps(frame_limit);
                            SDL_RectDef(&_background,Texture_Background[2]->backgroundWidth,Texture_Background[2]->backgroundHeight,(WINDOW_WIDTH - Texture_Background[2]->backgroundWidth)/2,(WINDOW_HEIGTH - Texture_Background[2]->backgroundHeight)/2);
                            SDL_RenderCopy(renderer,Texture_Background[2]->background,NULL,&_background);
                            SDL_RenderCopy(renderer,Alakazam->texture_face,NULL,&pokemonPosition);
                            if(Charizard->select == 1){
                                SDL_RectDef(&_background,Texture_Background[3]->backgroundWidth,Texture_Background[3]->backgroundHeight,90,200);
                                SDL_RenderCopy(renderer,Texture_Background[3]->background,NULL,&_background);
                            }
                            if(Vanusaur->select == 1){
                                SDL_RectDef(&_background,Texture_Background[4]->backgroundWidth,Texture_Background[4]->backgroundHeight,306,200);
                                SDL_RenderCopy(renderer,Texture_Background[4]->background,NULL,&_background);
                            }
                            if(Tortoise->select == 1){
                                SDL_RectDef(&_background,Texture_Background[5]->backgroundWidth,Texture_Background[5]->backgroundHeight,522,200);
                                SDL_RenderCopy(renderer,Texture_Background[5]->background,NULL,&_background);
                            }
                            if(Ariados->select == 1){
                                SDL_RectDef(&_background,Texture_Background[6]->backgroundWidth,Texture_Background[6]->backgroundHeight,90,277);
                                SDL_RenderCopy(renderer,Texture_Background[6]->background,NULL,&_background);
                            }
                            if(Dragonite->select == 1){
                                SDL_RectDef(&_background,Texture_Background[7]->backgroundWidth,Texture_Background[7]->backgroundHeight,306,277);
                                SDL_RenderCopy(renderer,Texture_Background[7]->background,NULL,&_background);
                            }
                            if(Onix->select == 1){
                                SDL_RectDef(&_background,Texture_Background[8]->backgroundWidth,Texture_Background[8]->backgroundHeight,522,277);
                                SDL_RenderCopy(renderer,Texture_Background[8]->background,NULL,&_background);
                            }
                            if(Harbok->select == 1){
                                SDL_RectDef(&_background,Texture_Background[9]->backgroundWidth,Texture_Background[9]->backgroundHeight,306,354);
                                SDL_RenderCopy(renderer,Texture_Background[9]->background,NULL,&_background);
                            }
                            if(Raichu->select == 1){
                                SDL_RectDef(&_background,Texture_Background[10]->backgroundWidth,Texture_Background[10]->backgroundHeight,90,277);
                                SDL_RenderCopy(renderer,Texture_Background[10]->background,NULL,&_background);
                            }
                            if(Pidgeot->select == 1){
                                SDL_RectDef(&_background,Texture_Background[12]->backgroundWidth,Texture_Background[10]->backgroundHeight,90,431);
                                SDL_RenderCopy(renderer,Texture_Background[12]->background,NULL,&_background); 
                            }
                            if(Snorlak->select==1){
                                SDL_RectDef(&_background,Texture_Background[13]->backgroundWidth,Texture_Background[13]->backgroundHeight,306,431);
                                SDL_RenderCopy(renderer,Texture_Background[13]->background,NULL,&_background);
                            }
                            if(Machamp->select ==1){
                                SDL_RectDef(&_background,Texture_Background[14]->backgroundWidth,Texture_Background[10]->backgroundHeight,522,431);
                                SDL_RenderCopy(renderer,Texture_Background[14]->background,NULL,&_background); 
                            }
                            frame_limit = SDL_GetTicks()+FPS_LIMIT;
                            SDL_RenderPresent(renderer);
                        }

                        //-------------------------- Button Pidgeot ----------------------//
                        if(event.motion.x >=90 && event.motion.x<=274 && event.motion.y>=431 && event.motion.y<=500 && Pidgeot->select==0){
                            printf("la souri est %dx|%dy Button Pidgeot \n",event.button.x,event.button.y);
                            SDL_RectDef(&pokemonPosition,Pidgeot->pokemon_width_face*2,Pidgeot->pokemon_height_face*2,90+(249/2 - Pidgeot->pokemon_width_face),34+(150 - Pidgeot->pokemon_height_face*2));
                            SDL_RenderClear(renderer);
                            limit_fps(frame_limit);
                            SDL_RectDef(&_background,Texture_Background[2]->backgroundWidth,Texture_Background[2]->backgroundHeight,(WINDOW_WIDTH - Texture_Background[2]->backgroundWidth)/2,(WINDOW_HEIGTH - Texture_Background[2]->backgroundHeight)/2);
                            SDL_RenderCopy(renderer,Texture_Background[2]->background,NULL,&_background);
                            SDL_RenderCopy(renderer,Pidgeot->texture_face,NULL,&pokemonPosition);
                            if(Charizard->select == 1){
                                SDL_RectDef(&_background,Texture_Background[3]->backgroundWidth,Texture_Background[3]->backgroundHeight,90,200);
                                SDL_RenderCopy(renderer,Texture_Background[3]->background,NULL,&_background);
                            }
                            if(Vanusaur->select == 1){
                                SDL_RectDef(&_background,Texture_Background[4]->backgroundWidth,Texture_Background[4]->backgroundHeight,306,200);
                                SDL_RenderCopy(renderer,Texture_Background[4]->background,NULL,&_background);
                            }
                            if(Tortoise->select == 1){
                                SDL_RectDef(&_background,Texture_Background[5]->backgroundWidth,Texture_Background[5]->backgroundHeight,522,200);
                                SDL_RenderCopy(renderer,Texture_Background[5]->background,NULL,&_background);
                            }
                            if(Ariados->select == 1){
                                SDL_RectDef(&_background,Texture_Background[6]->backgroundWidth,Texture_Background[6]->backgroundHeight,90,277);
                                SDL_RenderCopy(renderer,Texture_Background[6]->background,NULL,&_background);
                            }
                            if(Dragonite->select == 1){
                                SDL_RectDef(&_background,Texture_Background[7]->backgroundWidth,Texture_Background[7]->backgroundHeight,306,277);
                                SDL_RenderCopy(renderer,Texture_Background[7]->background,NULL,&_background);
                            }
                            if(Onix->select == 1){
                                SDL_RectDef(&_background,Texture_Background[8]->backgroundWidth,Texture_Background[8]->backgroundHeight,522,277);
                                SDL_RenderCopy(renderer,Texture_Background[8]->background,NULL,&_background);
                            }
                            if(Harbok->select == 1){
                                SDL_RectDef(&_background,Texture_Background[9]->backgroundWidth,Texture_Background[9]->backgroundHeight,90,354);
                                SDL_RenderCopy(renderer,Texture_Background[9]->background,NULL,&_background);
                            }
                            if(Raichu->select == 1){
                                SDL_RectDef(&_background,Texture_Background[10]->backgroundWidth,Texture_Background[10]->backgroundHeight,306,354);
                                SDL_RenderCopy(renderer,Texture_Background[10]->background,NULL,&_background);
                            }
                            if(Alakazam->select == 1){
                                SDL_RectDef(&_background,Texture_Background[11]->backgroundWidth,Texture_Background[11]->backgroundHeight,522,354);
                                SDL_RenderCopy(renderer,Texture_Background[11]->background,NULL,&_background);
                            }
                            if(Snorlak->select==1){
                                SDL_RectDef(&_background,Texture_Background[13]->backgroundWidth,Texture_Background[13]->backgroundHeight,306,431);
                                SDL_RenderCopy(renderer,Texture_Background[13]->background,NULL,&_background);
                            }
                            if(Machamp->select ==1){
                                SDL_RectDef(&_background,Texture_Background[14]->backgroundWidth,Texture_Background[10]->backgroundHeight,522,431);
                                SDL_RenderCopy(renderer,Texture_Background[14]->background,NULL,&_background); 
                            }
                            frame_limit = SDL_GetTicks()+FPS_LIMIT;
                            SDL_RenderPresent(renderer);
                        }

                        //-------------------------- Button Snorlak ----------------------//
                        if(event.motion.x >= 306 && event.motion.x<=492 && event.motion.y>=431 && event.motion.y<=500 && Snorlak->select==0){
                            printf("la souri est %dx|%dy Button Snorlak \n",event.button.x,event.button.y);
                            SDL_RectDef(&pokemonPosition,Snorlak->pokemon_width_face*2,Snorlak->pokemon_height_face*2,90+(249/2 - Snorlak->pokemon_width_face),34+(150 - Snorlak->pokemon_height_face*2));
                            SDL_RenderClear(renderer);
                            limit_fps(frame_limit);
                            SDL_RectDef(&_background,Texture_Background[2]->backgroundWidth,Texture_Background[2]->backgroundHeight,(WINDOW_WIDTH - Texture_Background[2]->backgroundWidth)/2,(WINDOW_HEIGTH - Texture_Background[2]->backgroundHeight)/2);
                            SDL_RenderCopy(renderer,Texture_Background[2]->background,NULL,&_background);
                            SDL_RenderCopy(renderer,Snorlak->texture_face,NULL,&pokemonPosition);
                            if(Charizard->select == 1){
                                SDL_RectDef(&_background,Texture_Background[3]->backgroundWidth,Texture_Background[3]->backgroundHeight,90,200);
                                SDL_RenderCopy(renderer,Texture_Background[3]->background,NULL,&_background);
                            }
                            if(Vanusaur->select == 1){
                                SDL_RectDef(&_background,Texture_Background[4]->backgroundWidth,Texture_Background[4]->backgroundHeight,306,200);
                                SDL_RenderCopy(renderer,Texture_Background[4]->background,NULL,&_background);
                            }
                            if(Tortoise->select == 1){
                                SDL_RectDef(&_background,Texture_Background[5]->backgroundWidth,Texture_Background[5]->backgroundHeight,522,200);
                                SDL_RenderCopy(renderer,Texture_Background[5]->background,NULL,&_background);
                            }
                            if(Ariados->select == 1){
                                SDL_RectDef(&_background,Texture_Background[6]->backgroundWidth,Texture_Background[6]->backgroundHeight,90,277);
                                SDL_RenderCopy(renderer,Texture_Background[6]->background,NULL,&_background);
                            }
                            if(Dragonite->select == 1){
                                SDL_RectDef(&_background,Texture_Background[7]->backgroundWidth,Texture_Background[7]->backgroundHeight,306,277);
                                SDL_RenderCopy(renderer,Texture_Background[7]->background,NULL,&_background);
                            }
                            if(Onix->select == 1){
                                SDL_RectDef(&_background,Texture_Background[8]->backgroundWidth,Texture_Background[8]->backgroundHeight,522,277);
                                SDL_RenderCopy(renderer,Texture_Background[8]->background,NULL,&_background);
                            }
                            if(Harbok->select == 1){
                                SDL_RectDef(&_background,Texture_Background[9]->backgroundWidth,Texture_Background[9]->backgroundHeight,90,354);
                                SDL_RenderCopy(renderer,Texture_Background[9]->background,NULL,&_background);
                            }
                            if(Raichu->select == 1){
                                SDL_RectDef(&_background,Texture_Background[10]->backgroundWidth,Texture_Background[10]->backgroundHeight,306,354);
                                SDL_RenderCopy(renderer,Texture_Background[10]->background,NULL,&_background);
                            }
                            if(Alakazam->select == 1){
                                SDL_RectDef(&_background,Texture_Background[11]->backgroundWidth,Texture_Background[11]->backgroundHeight,522,354);
                                SDL_RenderCopy(renderer,Texture_Background[11]->background,NULL,&_background);
                            }
                            if(Pidgeot->select == 1){
                                SDL_RectDef(&_background,Texture_Background[12]->backgroundWidth,Texture_Background[10]->backgroundHeight,90,431);
                                SDL_RenderCopy(renderer,Texture_Background[12]->background,NULL,&_background); 
                            }
                            if(Machamp->select ==1){
                                SDL_RectDef(&_background,Texture_Background[14]->backgroundWidth,Texture_Background[10]->backgroundHeight,522,431);
                                SDL_RenderCopy(renderer,Texture_Background[14]->background,NULL,&_background); 
                            }
                            frame_limit = SDL_GetTicks()+FPS_LIMIT;
                            SDL_RenderPresent(renderer);
                        }

                        //-------------------------- Button Machamp ---------------------//
                        if(event.motion.x >= 522 && event.motion.x <= 706 && event.motion.y>=431 && event.motion.y<=500 && Machamp->select == 0){
                            printf("la souri est %dx|%dy Button Machamp \n",event.button.x,event.button.y);
                            SDL_RectDef(&pokemonPosition,Machamp->pokemon_width_face*2,Machamp->pokemon_height_face*2,90+(249/2 - Machamp->pokemon_width_face),34+(144 - Machamp->pokemon_height_face*2));
                            SDL_RenderClear(renderer);
                            limit_fps(frame_limit);
                            SDL_RectDef(&_background,Texture_Background[2]->backgroundWidth,Texture_Background[2]->backgroundHeight,(WINDOW_WIDTH - Texture_Background[2]->backgroundWidth)/2,(WINDOW_HEIGTH - Texture_Background[2]->backgroundHeight)/2);
                            SDL_RenderCopy(renderer,Texture_Background[2]->background,NULL,&_background);
                            SDL_RenderCopy(renderer,Machamp->texture_face,NULL,&pokemonPosition);
                            if(Charizard->select == 1){
                                SDL_RectDef(&_background,Texture_Background[3]->backgroundWidth,Texture_Background[3]->backgroundHeight,90,200);
                                SDL_RenderCopy(renderer,Texture_Background[3]->background,NULL,&_background);
                            }
                            if(Vanusaur->select == 1){
                                SDL_RectDef(&_background,Texture_Background[4]->backgroundWidth,Texture_Background[4]->backgroundHeight,306,200);
                                SDL_RenderCopy(renderer,Texture_Background[4]->background,NULL,&_background);
                            }
                            if(Tortoise->select == 1){
                                SDL_RectDef(&_background,Texture_Background[5]->backgroundWidth,Texture_Background[5]->backgroundHeight,522,200);
                                SDL_RenderCopy(renderer,Texture_Background[5]->background,NULL,&_background);
                            }
                            if(Ariados->select == 1){
                                SDL_RectDef(&_background,Texture_Background[6]->backgroundWidth,Texture_Background[6]->backgroundHeight,90,277);
                                SDL_RenderCopy(renderer,Texture_Background[6]->background,NULL,&_background);
                            }
                            if(Dragonite->select == 1){
                                SDL_RectDef(&_background,Texture_Background[7]->backgroundWidth,Texture_Background[7]->backgroundHeight,306,277);
                                SDL_RenderCopy(renderer,Texture_Background[7]->background,NULL,&_background);
                            }
                            if(Onix->select == 1){
                                SDL_RectDef(&_background,Texture_Background[8]->backgroundWidth,Texture_Background[8]->backgroundHeight,522,277);
                                SDL_RenderCopy(renderer,Texture_Background[8]->background,NULL,&_background);
                            }
                            if(Harbok->select == 1){
                                SDL_RectDef(&_background,Texture_Background[9]->backgroundWidth,Texture_Background[9]->backgroundHeight,90,354);
                                SDL_RenderCopy(renderer,Texture_Background[9]->background,NULL,&_background);
                            }
                            if(Raichu->select == 1){
                                SDL_RectDef(&_background,Texture_Background[10]->backgroundWidth,Texture_Background[10]->backgroundHeight,306,354);
                                SDL_RenderCopy(renderer,Texture_Background[10]->background,NULL,&_background);
                            }
                            if(Alakazam->select == 1){
                                SDL_RectDef(&_background,Texture_Background[11]->backgroundWidth,Texture_Background[11]->backgroundHeight,522,354);
                                SDL_RenderCopy(renderer,Texture_Background[11]->background,NULL,&_background);
                            }
                            if(Pidgeot->select == 1){
                                SDL_RectDef(&_background,Texture_Background[12]->backgroundWidth,Texture_Background[10]->backgroundHeight,90,431);
                                SDL_RenderCopy(renderer,Texture_Background[12]->background,NULL,&_background); 
                            }
                            if(Snorlak->select==1){
                                SDL_RectDef(&_background,Texture_Background[13]->backgroundWidth,Texture_Background[13]->backgroundHeight,306,431);
                                SDL_RenderCopy(renderer,Texture_Background[13]->background,NULL,&_background);
                            }
                            frame_limit = SDL_GetTicks()+FPS_LIMIT;
                            SDL_RenderPresent(renderer);
                        }
                    }
                    break;

                case SDL_MOUSEBUTTONDOWN:
                    if(index==MAIN_MENU){
                        if(event.button.x >=273 && event.button.x<=529 && event.button.y>=500 && event.button.y<=556){
                            printf("CLick sur le boutton %dx|%dy \n",event.button.x,event.button.y);
                            /*Verification de la bonne creation du rendu*/
                            limit_fps(frame_limit);
                            SDL_RenderClear(renderer);
                            SDL_RectDef(&_background,Texture_Background[2]->backgroundWidth,Texture_Background[2]->backgroundHeight,(WINDOW_WIDTH - Texture_Background[2]->backgroundWidth)/2,(WINDOW_HEIGTH - Texture_Background[2]->backgroundHeight)/2);
                            SDL_RenderCopy(renderer,Texture_Background[2]->background,NULL,&_background);
                            frame_limit = SDL_GetTicks()+FPS_LIMIT;
                            SDL_RenderPresent(renderer);
                            index=CHOOSE_PLAYER_MENU;
                        }
                    }
                    if(index == CHOOSE_PLAYER_MENU){
                        if(Character_select == 3 && event.button.x >= 320 && event.button.x <=475 && event.button.y>=526 && event.button.y <= 579){
                             printf("CLick sur le boutton play %dx|%dy \n",event.button.x,event.button.y);
                            /*Verification de la bonne creation du rendu*/
                            limit_fps(frame_limit);
                            SDL_RenderClear(renderer);
                            SDL_RectDef(&_background,Texture_Background[15]->backgroundWidth,Texture_Background[15]->backgroundHeight,(WINDOW_WIDTH - Texture_Background[15]->backgroundWidth)/2,(WINDOW_HEIGTH - Texture_Background[15]->backgroundHeight)/2);
                            SDL_RenderCopy(renderer,Texture_Background[15]->background,NULL,&_background);
                            frame_limit = SDL_GetTicks()+FPS_LIMIT;
                            SDL_RenderPresent(renderer);
                            index=GAMEPLAY;
                        }
                        //----------------------------- Button Charizard ----------------//
                        if(event.button.x >=90 && event.button.x<=274 && event.button.y>=200 && event.button.y<=269 && Charizard->select == 0 && Character_select<3){
                            printf("Click sur Charizard %dx|%dy \n",event.button.x,event.button.y);
                            //------ Affichage de pokemon -----------//
                            SDL_RenderClear(renderer);
                            limit_fps(frame_limit);
                            SDL_RectDef(&_background,Texture_Background[2]->backgroundWidth,Texture_Background[2]->backgroundHeight,(WINDOW_WIDTH - Texture_Background[2]->backgroundWidth)/2,(WINDOW_HEIGTH - Texture_Background[2]->backgroundHeight)/2);
                            SDL_RenderCopy(renderer,Texture_Background[2]->background,NULL,&_background);
                            SDL_RectDef(&_background,Texture_Background[3]->backgroundWidth,Texture_Background[3]->backgroundHeight,90,200);
                            SDL_RenderCopy(renderer,Texture_Background[3]->background,NULL,&_background);
                            if(Vanusaur->select == 1){
                                SDL_RectDef(&_background,Texture_Background[4]->backgroundWidth,Texture_Background[4]->backgroundHeight,306,200);
                                SDL_RenderCopy(renderer,Texture_Background[4]->background,NULL,&_background);
                            }
                            if(Tortoise->select == 1){
                                SDL_RectDef(&_background,Texture_Background[5]->backgroundWidth,Texture_Background[5]->backgroundHeight,522,200);
                                SDL_RenderCopy(renderer,Texture_Background[5]->background,NULL,&_background);
                            }
                            if(Ariados->select == 1){
                                SDL_RectDef(&_background,Texture_Background[6]->backgroundWidth,Texture_Background[6]->backgroundHeight,90,277);
                                SDL_RenderCopy(renderer,Texture_Background[6]->background,NULL,&_background);
                            }
                            if(Dragonite->select == 1){
                                SDL_RectDef(&_background,Texture_Background[7]->backgroundWidth,Texture_Background[7]->backgroundHeight,306,277);
                                SDL_RenderCopy(renderer,Texture_Background[7]->background,NULL,&_background);
                            }
                            if(Onix->select == 1){
                                SDL_RectDef(&_background,Texture_Background[8]->backgroundWidth,Texture_Background[8]->backgroundHeight,522,277);
                                SDL_RenderCopy(renderer,Texture_Background[8]->background,NULL,&_background);
                            }
                            if(Harbok->select == 1){
                                SDL_RectDef(&_background,Texture_Background[9]->backgroundWidth,Texture_Background[9]->backgroundHeight,90,354);
                                SDL_RenderCopy(renderer,Texture_Background[9]->background,NULL,&_background);
                            }
                            if(Raichu->select == 1){
                                SDL_RectDef(&_background,Texture_Background[10]->backgroundWidth,Texture_Background[10]->backgroundHeight,306,354);
                                SDL_RenderCopy(renderer,Texture_Background[10]->background,NULL,&_background);
                            }
                            if(Alakazam->select == 1){
                                SDL_RectDef(&_background,Texture_Background[11]->backgroundWidth,Texture_Background[11]->backgroundHeight,522,354);
                                SDL_RenderCopy(renderer,Texture_Background[11]->background,NULL,&_background);
                            }
                            if(Pidgeot->select == 1){
                                SDL_RectDef(&_background,Texture_Background[12]->backgroundWidth,Texture_Background[10]->backgroundHeight,90,431);
                                SDL_RenderCopy(renderer,Texture_Background[12]->background,NULL,&_background); 
                            }
                            if(Snorlak->select==1){
                                SDL_RectDef(&_background,Texture_Background[13]->backgroundWidth,Texture_Background[13]->backgroundHeight,306,431);
                                SDL_RenderCopy(renderer,Texture_Background[13]->background,NULL,&_background);
                            }
                            if(Machamp->select ==1){
                                SDL_RectDef(&_background,Texture_Background[14]->backgroundWidth,Texture_Background[10]->backgroundHeight,522,431);
                                SDL_RenderCopy(renderer,Texture_Background[14]->background,NULL,&_background); 
                            }
                            frame_limit = SDL_GetTicks()+FPS_LIMIT;
                            SDL_RenderPresent(renderer);
                            Charizard->select=1;
                            Character_select++;
                        }
                        //-------------------------- Button Venuzaur --------------------------//
                        if(event.button.x >= 306 && event.button.x<=492 && event.button.y>=200 && event.button.y<=269 && Vanusaur->select==0 && Character_select<3){
                            printf("Click sur venusaur %dx|%dy Button Venuzaur \n",event.button.x,event.button.y);
                            SDL_RenderClear(renderer);
                            limit_fps(frame_limit);
                            SDL_RectDef(&_background,Texture_Background[2]->backgroundWidth,Texture_Background[2]->backgroundHeight,(WINDOW_WIDTH - Texture_Background[2]->backgroundWidth)/2,(WINDOW_HEIGTH - Texture_Background[2]->backgroundHeight)/2);
                            SDL_RenderCopy(renderer,Texture_Background[2]->background,NULL,&_background);
                            SDL_RectDef(&_background,Texture_Background[4]->backgroundWidth,Texture_Background[4]->backgroundHeight,306,200);
                            SDL_RenderCopy(renderer,Texture_Background[4]->background,NULL,&_background);
                            if(Charizard->select == 1){
                                SDL_RectDef(&_background,Texture_Background[3]->backgroundWidth,Texture_Background[3]->backgroundHeight,90,200);
                                SDL_RenderCopy(renderer,Texture_Background[3]->background,NULL,&_background);
                            }
                            if(Tortoise->select == 1){
                                SDL_RectDef(&_background,Texture_Background[5]->backgroundWidth,Texture_Background[5]->backgroundHeight,522,200);
                                SDL_RenderCopy(renderer,Texture_Background[5]->background,NULL,&_background);
                            }
                            if(Ariados->select == 1){
                                SDL_RectDef(&_background,Texture_Background[6]->backgroundWidth,Texture_Background[6]->backgroundHeight,90,277);
                                SDL_RenderCopy(renderer,Texture_Background[6]->background,NULL,&_background);
                            }
                            if(Dragonite->select == 1){
                                SDL_RectDef(&_background,Texture_Background[7]->backgroundWidth,Texture_Background[7]->backgroundHeight,306,277);
                                SDL_RenderCopy(renderer,Texture_Background[7]->background,NULL,&_background);
                            }
                            if(Onix->select == 1){
                                SDL_RectDef(&_background,Texture_Background[8]->backgroundWidth,Texture_Background[8]->backgroundHeight,522,277);
                                SDL_RenderCopy(renderer,Texture_Background[8]->background,NULL,&_background);
                            }
                            if(Harbok->select == 1){
                                SDL_RectDef(&_background,Texture_Background[9]->backgroundWidth,Texture_Background[9]->backgroundHeight,90,354);
                                SDL_RenderCopy(renderer,Texture_Background[9]->background,NULL,&_background);
                            }
                            if(Raichu->select == 1){
                                SDL_RectDef(&_background,Texture_Background[10]->backgroundWidth,Texture_Background[10]->backgroundHeight,306,354);
                                SDL_RenderCopy(renderer,Texture_Background[10]->background,NULL,&_background);
                            }
                            if(Alakazam->select == 1){
                                SDL_RectDef(&_background,Texture_Background[11]->backgroundWidth,Texture_Background[11]->backgroundHeight,522,354);
                                SDL_RenderCopy(renderer,Texture_Background[11]->background,NULL,&_background);
                            }
                            if(Pidgeot->select == 1){
                                SDL_RectDef(&_background,Texture_Background[12]->backgroundWidth,Texture_Background[10]->backgroundHeight,90,431);
                                SDL_RenderCopy(renderer,Texture_Background[12]->background,NULL,&_background); 
                            }
                            if(Snorlak->select==1){
                                SDL_RectDef(&_background,Texture_Background[13]->backgroundWidth,Texture_Background[13]->backgroundHeight,306,431);
                                SDL_RenderCopy(renderer,Texture_Background[13]->background,NULL,&_background);
                            }
                            if(Machamp->select ==1){
                                SDL_RectDef(&_background,Texture_Background[14]->backgroundWidth,Texture_Background[10]->backgroundHeight,522,431);
                                SDL_RenderCopy(renderer,Texture_Background[14]->background,NULL,&_background); 
                            }
                            frame_limit = SDL_GetTicks()+FPS_LIMIT;
                            SDL_RenderPresent(renderer);
                            Vanusaur->select=1;
                            Character_select++;
                        }
                        //-------------------------- Button Totoise ---------------------//
                        if(event.motion.x >= 522 && event.motion.x <= 706 && event.motion.y>=200 && event.motion.y<=269 && Tortoise->select==0 && Character_select<3){
                            printf("Click sur Tortoise %dx|%dy Button Venuzaur \n",event.button.x,event.button.y);
                            SDL_RenderClear(renderer);
                            limit_fps(frame_limit);
                            SDL_RectDef(&_background,Texture_Background[2]->backgroundWidth,Texture_Background[2]->backgroundHeight,(WINDOW_WIDTH - Texture_Background[2]->backgroundWidth)/2,(WINDOW_HEIGTH - Texture_Background[2]->backgroundHeight)/2);
                            SDL_RenderCopy(renderer,Texture_Background[2]->background,NULL,&_background);
                            SDL_RectDef(&_background,Texture_Background[5]->backgroundWidth,Texture_Background[5]->backgroundHeight,522,200);
                            SDL_RenderCopy(renderer,Texture_Background[5]->background,NULL,&_background);
                            if(Charizard->select == 1){
                                SDL_RectDef(&_background,Texture_Background[3]->backgroundWidth,Texture_Background[3]->backgroundHeight,90,200);
                                SDL_RenderCopy(renderer,Texture_Background[3]->background,NULL,&_background);
                            }
                            if(Vanusaur->select == 1){
                                SDL_RectDef(&_background,Texture_Background[4]->backgroundWidth,Texture_Background[4]->backgroundHeight,306,200);
                                SDL_RenderCopy(renderer,Texture_Background[4]->background,NULL,&_background);
                            }
                            if(Ariados->select == 1){
                                SDL_RectDef(&_background,Texture_Background[6]->backgroundWidth,Texture_Background[6]->backgroundHeight,90,277);
                                SDL_RenderCopy(renderer,Texture_Background[6]->background,NULL,&_background);
                            }
                            if(Dragonite->select == 1){
                                SDL_RectDef(&_background,Texture_Background[7]->backgroundWidth,Texture_Background[7]->backgroundHeight,306,277);
                                SDL_RenderCopy(renderer,Texture_Background[7]->background,NULL,&_background);
                            }
                            if(Onix->select == 1){
                                SDL_RectDef(&_background,Texture_Background[8]->backgroundWidth,Texture_Background[8]->backgroundHeight,522,277);
                                SDL_RenderCopy(renderer,Texture_Background[8]->background,NULL,&_background);
                            }
                            if(Harbok->select == 1){
                                SDL_RectDef(&_background,Texture_Background[9]->backgroundWidth,Texture_Background[9]->backgroundHeight,90,354);
                                SDL_RenderCopy(renderer,Texture_Background[9]->background,NULL,&_background);
                            }
                            if(Raichu->select == 1){
                                SDL_RectDef(&_background,Texture_Background[10]->backgroundWidth,Texture_Background[10]->backgroundHeight,306,354);
                                SDL_RenderCopy(renderer,Texture_Background[10]->background,NULL,&_background);
                            }
                            if(Alakazam->select == 1){
                                SDL_RectDef(&_background,Texture_Background[11]->backgroundWidth,Texture_Background[11]->backgroundHeight,522,354);
                                SDL_RenderCopy(renderer,Texture_Background[11]->background,NULL,&_background);
                            }
                            if(Pidgeot->select == 1){
                                SDL_RectDef(&_background,Texture_Background[12]->backgroundWidth,Texture_Background[10]->backgroundHeight,90,431);
                                SDL_RenderCopy(renderer,Texture_Background[12]->background,NULL,&_background); 
                            }
                            if(Snorlak->select==1){
                                SDL_RectDef(&_background,Texture_Background[13]->backgroundWidth,Texture_Background[13]->backgroundHeight,306,431);
                                SDL_RenderCopy(renderer,Texture_Background[13]->background,NULL,&_background);
                            }
                            if(Machamp->select ==1){
                                SDL_RectDef(&_background,Texture_Background[14]->backgroundWidth,Texture_Background[10]->backgroundHeight,522,431);
                                SDL_RenderCopy(renderer,Texture_Background[14]->background,NULL,&_background); 
                            }
                            frame_limit = SDL_GetTicks()+FPS_LIMIT;
                            SDL_RenderPresent(renderer);
                            Tortoise->select=1;
                            Character_select++;
                        }
                        //-------------------------- Button Ariados ---------------------//
                        if(event.motion.x >=90 && event.motion.x<=274 && event.motion.y>=277 && event.motion.y<=346 && Ariados->select==0 && Character_select<3){
                            printf("Click sur Ariados %dx|%dy Button Venuzaur \n",event.button.x,event.button.y);
                            SDL_RenderClear(renderer);
                            limit_fps(frame_limit);
                            SDL_RectDef(&_background,Texture_Background[2]->backgroundWidth,Texture_Background[2]->backgroundHeight,(WINDOW_WIDTH - Texture_Background[2]->backgroundWidth)/2,(WINDOW_HEIGTH - Texture_Background[2]->backgroundHeight)/2);
                            SDL_RenderCopy(renderer,Texture_Background[2]->background,NULL,&_background);
                            SDL_RectDef(&_background,Texture_Background[6]->backgroundWidth,Texture_Background[6]->backgroundHeight,90,277);
                            SDL_RenderCopy(renderer,Texture_Background[6]->background,NULL,&_background);
                            if(Charizard->select == 1){
                                SDL_RectDef(&_background,Texture_Background[3]->backgroundWidth,Texture_Background[3]->backgroundHeight,90,200);
                                SDL_RenderCopy(renderer,Texture_Background[3]->background,NULL,&_background);
                            }
                            if(Vanusaur->select == 1){
                                SDL_RectDef(&_background,Texture_Background[4]->backgroundWidth,Texture_Background[4]->backgroundHeight,306,200);
                                SDL_RenderCopy(renderer,Texture_Background[4]->background,NULL,&_background);
                            }
                            if(Tortoise->select == 1){
                                SDL_RectDef(&_background,Texture_Background[5]->backgroundWidth,Texture_Background[5]->backgroundHeight,522,200);
                                SDL_RenderCopy(renderer,Texture_Background[5]->background,NULL,&_background);
                            }
                            if(Dragonite->select == 1){
                                SDL_RectDef(&_background,Texture_Background[7]->backgroundWidth,Texture_Background[7]->backgroundHeight,306,277);
                                SDL_RenderCopy(renderer,Texture_Background[7]->background,NULL,&_background);
                            }
                            if(Onix->select == 1){
                                SDL_RectDef(&_background,Texture_Background[8]->backgroundWidth,Texture_Background[8]->backgroundHeight,522,277);
                                SDL_RenderCopy(renderer,Texture_Background[8]->background,NULL,&_background);
                            }
                            if(Harbok->select == 1){
                                SDL_RectDef(&_background,Texture_Background[9]->backgroundWidth,Texture_Background[9]->backgroundHeight,90,354);
                                SDL_RenderCopy(renderer,Texture_Background[9]->background,NULL,&_background);
                            }
                            if(Raichu->select == 1){
                                SDL_RectDef(&_background,Texture_Background[10]->backgroundWidth,Texture_Background[10]->backgroundHeight,306,354);
                                SDL_RenderCopy(renderer,Texture_Background[10]->background,NULL,&_background);
                            }
                            if(Alakazam->select == 1){
                                SDL_RectDef(&_background,Texture_Background[11]->backgroundWidth,Texture_Background[11]->backgroundHeight,522,354);
                                SDL_RenderCopy(renderer,Texture_Background[11]->background,NULL,&_background);
                            }
                            if(Pidgeot->select == 1){
                                SDL_RectDef(&_background,Texture_Background[12]->backgroundWidth,Texture_Background[10]->backgroundHeight,90,431);
                                SDL_RenderCopy(renderer,Texture_Background[12]->background,NULL,&_background); 
                            }
                            if(Snorlak->select==1){
                                SDL_RectDef(&_background,Texture_Background[13]->backgroundWidth,Texture_Background[13]->backgroundHeight,306,431);
                                SDL_RenderCopy(renderer,Texture_Background[13]->background,NULL,&_background);
                            }
                            if(Machamp->select ==1){
                                SDL_RectDef(&_background,Texture_Background[14]->backgroundWidth,Texture_Background[10]->backgroundHeight,522,431);
                                SDL_RenderCopy(renderer,Texture_Background[14]->background,NULL,&_background); 
                            }
                            frame_limit = SDL_GetTicks()+FPS_LIMIT;
                            SDL_RenderPresent(renderer);
                            Ariados->select=1;
                            Character_select++;
                        }
                        //--------------------------- Button Dragonite ---------------------------//
                        if(event.motion.x >= 306 && event.motion.x<=492 && event.motion.y>=277 && event.motion.y<=346 && Dragonite->select==0 && Character_select<3){
                            printf("Click sur Dragonite %dx|%dy Button Venuzaur \n",event.button.x,event.button.y);
                            SDL_RenderClear(renderer);
                            limit_fps(frame_limit);
                            SDL_RectDef(&_background,Texture_Background[2]->backgroundWidth,Texture_Background[2]->backgroundHeight,(WINDOW_WIDTH - Texture_Background[2]->backgroundWidth)/2,(WINDOW_HEIGTH - Texture_Background[2]->backgroundHeight)/2);
                            SDL_RenderCopy(renderer,Texture_Background[2]->background,NULL,&_background);
                            SDL_RectDef(&_background,Texture_Background[7]->backgroundWidth,Texture_Background[7]->backgroundHeight,306,277);
                            SDL_RenderCopy(renderer,Texture_Background[7]->background,NULL,&_background);
                            if(Charizard->select == 1){
                                SDL_RectDef(&_background,Texture_Background[3]->backgroundWidth,Texture_Background[3]->backgroundHeight,90,200);
                                SDL_RenderCopy(renderer,Texture_Background[3]->background,NULL,&_background);
                            }
                            if(Vanusaur->select == 1){
                                SDL_RectDef(&_background,Texture_Background[4]->backgroundWidth,Texture_Background[4]->backgroundHeight,306,200);
                                SDL_RenderCopy(renderer,Texture_Background[4]->background,NULL,&_background);
                            }
                            if(Tortoise->select == 1){
                                SDL_RectDef(&_background,Texture_Background[5]->backgroundWidth,Texture_Background[5]->backgroundHeight,522,200);
                                SDL_RenderCopy(renderer,Texture_Background[5]->background,NULL,&_background);
                            }
                            if(Ariados->select == 1){
                                SDL_RectDef(&_background,Texture_Background[6]->backgroundWidth,Texture_Background[6]->backgroundHeight,90,277);
                                SDL_RenderCopy(renderer,Texture_Background[6]->background,NULL,&_background);
                            }
                            if(Onix->select == 1){
                                SDL_RectDef(&_background,Texture_Background[8]->backgroundWidth,Texture_Background[8]->backgroundHeight,522,277);
                                SDL_RenderCopy(renderer,Texture_Background[8]->background,NULL,&_background);
                            }
                            if(Harbok->select == 1){
                                SDL_RectDef(&_background,Texture_Background[9]->backgroundWidth,Texture_Background[9]->backgroundHeight,90,354);
                                SDL_RenderCopy(renderer,Texture_Background[9]->background,NULL,&_background);
                            }
                            if(Raichu->select == 1){
                                SDL_RectDef(&_background,Texture_Background[10]->backgroundWidth,Texture_Background[10]->backgroundHeight,306,354);
                                SDL_RenderCopy(renderer,Texture_Background[10]->background,NULL,&_background);
                            }
                            if(Alakazam->select == 1){
                                SDL_RectDef(&_background,Texture_Background[11]->backgroundWidth,Texture_Background[11]->backgroundHeight,522,354);
                                SDL_RenderCopy(renderer,Texture_Background[11]->background,NULL,&_background);
                            }
                            if(Pidgeot->select == 1){
                                SDL_RectDef(&_background,Texture_Background[12]->backgroundWidth,Texture_Background[10]->backgroundHeight,90,431);
                                SDL_RenderCopy(renderer,Texture_Background[12]->background,NULL,&_background); 
                            }
                            if(Snorlak->select==1){
                                SDL_RectDef(&_background,Texture_Background[13]->backgroundWidth,Texture_Background[13]->backgroundHeight,306,431);
                                SDL_RenderCopy(renderer,Texture_Background[13]->background,NULL,&_background);
                            }
                            if(Machamp->select ==1){
                                SDL_RectDef(&_background,Texture_Background[14]->backgroundWidth,Texture_Background[10]->backgroundHeight,522,431);
                                SDL_RenderCopy(renderer,Texture_Background[14]->background,NULL,&_background); 
                            }
                            frame_limit = SDL_GetTicks()+FPS_LIMIT;
                            SDL_RenderPresent(renderer);
                            Dragonite->select=1;
                            Character_select++;
                        }
                        //-------------------------- Button Onix ---------------------//
                        if(event.motion.x >= 522 && event.motion.x <= 706 && event.motion.y>=277 && event.motion.y<=346 && Onix->select==0 && Character_select<3){
                            printf("Click sur Onix %dx|%dy Button Venuzaur \n",event.button.x,event.button.y);
                            SDL_RenderClear(renderer);
                            limit_fps(frame_limit);
                            SDL_RectDef(&_background,Texture_Background[2]->backgroundWidth,Texture_Background[2]->backgroundHeight,(WINDOW_WIDTH - Texture_Background[2]->backgroundWidth)/2,(WINDOW_HEIGTH - Texture_Background[2]->backgroundHeight)/2);
                            SDL_RenderCopy(renderer,Texture_Background[2]->background,NULL,&_background);
                            SDL_RectDef(&_background,Texture_Background[8]->backgroundWidth,Texture_Background[8]->backgroundHeight,522,277);
                            SDL_RenderCopy(renderer,Texture_Background[8]->background,NULL,&_background);
                            if(Charizard->select == 1){
                                SDL_RectDef(&_background,Texture_Background[3]->backgroundWidth,Texture_Background[3]->backgroundHeight,90,200);
                                SDL_RenderCopy(renderer,Texture_Background[3]->background,NULL,&_background);
                            }
                            if(Vanusaur->select == 1){
                                SDL_RectDef(&_background,Texture_Background[4]->backgroundWidth,Texture_Background[4]->backgroundHeight,306,200);
                                SDL_RenderCopy(renderer,Texture_Background[4]->background,NULL,&_background);
                            }
                            if(Tortoise->select == 1){
                                SDL_RectDef(&_background,Texture_Background[5]->backgroundWidth,Texture_Background[5]->backgroundHeight,522,200);
                                SDL_RenderCopy(renderer,Texture_Background[5]->background,NULL,&_background);
                            }
                            if(Ariados->select == 1){
                                SDL_RectDef(&_background,Texture_Background[6]->backgroundWidth,Texture_Background[6]->backgroundHeight,90,277);
                                SDL_RenderCopy(renderer,Texture_Background[6]->background,NULL,&_background);
                            }
                            if(Dragonite->select == 1){
                                SDL_RectDef(&_background,Texture_Background[7]->backgroundWidth,Texture_Background[7]->backgroundHeight,306,277);
                                SDL_RenderCopy(renderer,Texture_Background[7]->background,NULL,&_background);
                            }
                            if(Harbok->select == 1){
                                SDL_RectDef(&_background,Texture_Background[9]->backgroundWidth,Texture_Background[9]->backgroundHeight,90,354);
                                SDL_RenderCopy(renderer,Texture_Background[9]->background,NULL,&_background);
                            }
                            if(Raichu->select == 1){
                                SDL_RectDef(&_background,Texture_Background[10]->backgroundWidth,Texture_Background[10]->backgroundHeight,306,354);
                                SDL_RenderCopy(renderer,Texture_Background[10]->background,NULL,&_background);
                            }
                            if(Alakazam->select == 1){
                                SDL_RectDef(&_background,Texture_Background[11]->backgroundWidth,Texture_Background[11]->backgroundHeight,522,354);
                                SDL_RenderCopy(renderer,Texture_Background[11]->background,NULL,&_background);
                            }
                            if(Pidgeot->select == 1){
                                SDL_RectDef(&_background,Texture_Background[12]->backgroundWidth,Texture_Background[10]->backgroundHeight,90,431);
                                SDL_RenderCopy(renderer,Texture_Background[12]->background,NULL,&_background); 
                            }
                            if(Snorlak->select==1){
                                SDL_RectDef(&_background,Texture_Background[13]->backgroundWidth,Texture_Background[13]->backgroundHeight,306,431);
                                SDL_RenderCopy(renderer,Texture_Background[13]->background,NULL,&_background);
                            }
                            if(Machamp->select ==1){
                                SDL_RectDef(&_background,Texture_Background[14]->backgroundWidth,Texture_Background[10]->backgroundHeight,522,431);
                                SDL_RenderCopy(renderer,Texture_Background[14]->background,NULL,&_background); 
                            }
                            frame_limit = SDL_GetTicks()+FPS_LIMIT;
                            SDL_RenderPresent(renderer);
                            Onix->select = 1;
                            Character_select++;
                        }
                        //-------------------------- Button Harbok -----------------------//
                        if(event.motion.x >=90 && event.motion.x<=274 && event.motion.y>=354 && event.motion.y<=423 && Harbok->select==0 && Character_select<3){
                            printf("Click sur Harbok %dx|%dy Button Venuzaur \n",event.button.x,event.button.y);
                            SDL_RenderClear(renderer);
                            limit_fps(frame_limit);
                            SDL_RectDef(&_background,Texture_Background[2]->backgroundWidth,Texture_Background[2]->backgroundHeight,(WINDOW_WIDTH - Texture_Background[2]->backgroundWidth)/2,(WINDOW_HEIGTH - Texture_Background[2]->backgroundHeight)/2);
                            SDL_RenderCopy(renderer,Texture_Background[2]->background,NULL,&_background);
                            SDL_RectDef(&_background,Texture_Background[9]->backgroundWidth,Texture_Background[9]->backgroundHeight,90,354);
                            SDL_RenderCopy(renderer,Texture_Background[9]->background,NULL,&_background);
                            if(Charizard->select == 1){
                                SDL_RectDef(&_background,Texture_Background[3]->backgroundWidth,Texture_Background[3]->backgroundHeight,90,200);
                                SDL_RenderCopy(renderer,Texture_Background[3]->background,NULL,&_background);
                            }
                            if(Vanusaur->select == 1){
                                SDL_RectDef(&_background,Texture_Background[4]->backgroundWidth,Texture_Background[4]->backgroundHeight,306,200);
                                SDL_RenderCopy(renderer,Texture_Background[4]->background,NULL,&_background);
                            }
                            if(Tortoise->select == 1){
                                SDL_RectDef(&_background,Texture_Background[5]->backgroundWidth,Texture_Background[5]->backgroundHeight,522,200);
                                SDL_RenderCopy(renderer,Texture_Background[5]->background,NULL,&_background);
                            }
                            if(Ariados->select == 1){
                                SDL_RectDef(&_background,Texture_Background[6]->backgroundWidth,Texture_Background[6]->backgroundHeight,90,277);
                                SDL_RenderCopy(renderer,Texture_Background[6]->background,NULL,&_background);
                            }
                            if(Dragonite->select == 1){
                                SDL_RectDef(&_background,Texture_Background[7]->backgroundWidth,Texture_Background[7]->backgroundHeight,306,277);
                                SDL_RenderCopy(renderer,Texture_Background[7]->background,NULL,&_background);
                            }
                            if(Onix->select == 1){
                                SDL_RectDef(&_background,Texture_Background[8]->backgroundWidth,Texture_Background[8]->backgroundHeight,522,277);
                                SDL_RenderCopy(renderer,Texture_Background[8]->background,NULL,&_background);
                            }
                            if(Raichu->select == 1){
                                SDL_RectDef(&_background,Texture_Background[10]->backgroundWidth,Texture_Background[10]->backgroundHeight,306,354);
                                SDL_RenderCopy(renderer,Texture_Background[10]->background,NULL,&_background);
                            }
                            if(Alakazam->select == 1){
                                SDL_RectDef(&_background,Texture_Background[11]->backgroundWidth,Texture_Background[11]->backgroundHeight,522,354);
                                SDL_RenderCopy(renderer,Texture_Background[11]->background,NULL,&_background);
                            }
                            if(Pidgeot->select == 1){
                                SDL_RectDef(&_background,Texture_Background[12]->backgroundWidth,Texture_Background[10]->backgroundHeight,90,431);
                                SDL_RenderCopy(renderer,Texture_Background[12]->background,NULL,&_background); 
                            }
                            if(Snorlak->select==1){
                                SDL_RectDef(&_background,Texture_Background[13]->backgroundWidth,Texture_Background[13]->backgroundHeight,306,431);
                                SDL_RenderCopy(renderer,Texture_Background[13]->background,NULL,&_background);
                            }
                            if(Machamp->select ==1){
                                SDL_RectDef(&_background,Texture_Background[14]->backgroundWidth,Texture_Background[10]->backgroundHeight,522,431);
                                SDL_RenderCopy(renderer,Texture_Background[14]->background,NULL,&_background); 
                            }
                            frame_limit = SDL_GetTicks()+FPS_LIMIT;
                            SDL_RenderPresent(renderer);
                            Harbok->select=1;
                            Character_select++;
                        }
                        //-------------------------- Button Raichu -----------------------//
                        if(event.motion.x >= 306 && event.motion.x<=492 && event.motion.y>=354 && event.motion.y<=423 && Raichu->select == 0 && Character_select<3){
                            printf("Click sur Raichu %dx|%dy Button Venuzaur \n",event.button.x,event.button.y);
                            SDL_RenderClear(renderer);
                            limit_fps(frame_limit);
                            SDL_RectDef(&_background,Texture_Background[2]->backgroundWidth,Texture_Background[2]->backgroundHeight,(WINDOW_WIDTH - Texture_Background[2]->backgroundWidth)/2,(WINDOW_HEIGTH - Texture_Background[2]->backgroundHeight)/2);
                            SDL_RenderCopy(renderer,Texture_Background[2]->background,NULL,&_background);
                            SDL_RectDef(&_background,Texture_Background[10]->backgroundWidth,Texture_Background[10]->backgroundHeight,306,354);
                            SDL_RenderCopy(renderer,Texture_Background[10]->background,NULL,&_background);
                            if(Charizard->select == 1){
                                SDL_RectDef(&_background,Texture_Background[3]->backgroundWidth,Texture_Background[3]->backgroundHeight,90,200);
                                SDL_RenderCopy(renderer,Texture_Background[3]->background,NULL,&_background);
                            }
                            if(Vanusaur->select == 1){
                                SDL_RectDef(&_background,Texture_Background[4]->backgroundWidth,Texture_Background[4]->backgroundHeight,306,200);
                                SDL_RenderCopy(renderer,Texture_Background[4]->background,NULL,&_background);
                            }
                            if(Tortoise->select == 1){
                                SDL_RectDef(&_background,Texture_Background[5]->backgroundWidth,Texture_Background[5]->backgroundHeight,522,200);
                                SDL_RenderCopy(renderer,Texture_Background[5]->background,NULL,&_background);
                            }
                            if(Ariados->select == 1){
                                SDL_RectDef(&_background,Texture_Background[6]->backgroundWidth,Texture_Background[6]->backgroundHeight,90,277);
                                SDL_RenderCopy(renderer,Texture_Background[6]->background,NULL,&_background);
                            }
                            if(Dragonite->select == 1){
                                SDL_RectDef(&_background,Texture_Background[7]->backgroundWidth,Texture_Background[7]->backgroundHeight,306,277);
                                SDL_RenderCopy(renderer,Texture_Background[7]->background,NULL,&_background);
                            }
                            if(Onix->select == 1){
                                SDL_RectDef(&_background,Texture_Background[8]->backgroundWidth,Texture_Background[8]->backgroundHeight,522,277);
                                SDL_RenderCopy(renderer,Texture_Background[8]->background,NULL,&_background);
                            }
                            if(Harbok->select == 1){
                                SDL_RectDef(&_background,Texture_Background[9]->backgroundWidth,Texture_Background[9]->backgroundHeight,90,354);
                                SDL_RenderCopy(renderer,Texture_Background[9]->background,NULL,&_background);
                            }
                            if(Alakazam->select == 1){
                                SDL_RectDef(&_background,Texture_Background[11]->backgroundWidth,Texture_Background[11]->backgroundHeight,522,354);
                                SDL_RenderCopy(renderer,Texture_Background[11]->background,NULL,&_background);
                            }
                            if(Pidgeot->select == 1){
                                SDL_RectDef(&_background,Texture_Background[12]->backgroundWidth,Texture_Background[10]->backgroundHeight,90,431);
                                SDL_RenderCopy(renderer,Texture_Background[12]->background,NULL,&_background); 
                            }
                            if(Snorlak->select==1){
                                SDL_RectDef(&_background,Texture_Background[13]->backgroundWidth,Texture_Background[13]->backgroundHeight,306,431);
                                SDL_RenderCopy(renderer,Texture_Background[13]->background,NULL,&_background);
                            }
                            if(Machamp->select ==1){
                                SDL_RectDef(&_background,Texture_Background[14]->backgroundWidth,Texture_Background[10]->backgroundHeight,522,431);
                                SDL_RenderCopy(renderer,Texture_Background[14]->background,NULL,&_background); 
                            }
                            frame_limit = SDL_GetTicks()+FPS_LIMIT;
                            SDL_RenderPresent(renderer);
                            Raichu->select=1;
                            Character_select++;
                        }
                        //-------------------------- Button Alakazam ----------------------//
                        if(event.motion.x >= 522 && event.motion.x <= 706 && event.motion.y>=354 && event.motion.y<=423 && Alakazam->select==0 && Character_select<3){
                            printf("Click sur Raichu %dx|%dy Button Venuzaur \n",event.button.x,event.button.y);
                            SDL_RenderClear(renderer);
                            limit_fps(frame_limit);
                            SDL_RectDef(&_background,Texture_Background[2]->backgroundWidth,Texture_Background[2]->backgroundHeight,(WINDOW_WIDTH - Texture_Background[2]->backgroundWidth)/2,(WINDOW_HEIGTH - Texture_Background[2]->backgroundHeight)/2);
                            SDL_RenderCopy(renderer,Texture_Background[2]->background,NULL,&_background);
                            SDL_RectDef(&_background,Texture_Background[11]->backgroundWidth,Texture_Background[11]->backgroundHeight,522,354);
                            SDL_RenderCopy(renderer,Texture_Background[11]->background,NULL,&_background);
                            if(Charizard->select == 1){
                                SDL_RectDef(&_background,Texture_Background[3]->backgroundWidth,Texture_Background[3]->backgroundHeight,90,200);
                                SDL_RenderCopy(renderer,Texture_Background[3]->background,NULL,&_background);
                            }
                            if(Vanusaur->select == 1){
                                SDL_RectDef(&_background,Texture_Background[4]->backgroundWidth,Texture_Background[4]->backgroundHeight,306,200);
                                SDL_RenderCopy(renderer,Texture_Background[4]->background,NULL,&_background);
                            }
                            if(Tortoise->select == 1){
                                SDL_RectDef(&_background,Texture_Background[5]->backgroundWidth,Texture_Background[5]->backgroundHeight,522,200);
                                SDL_RenderCopy(renderer,Texture_Background[5]->background,NULL,&_background);
                            }
                            if(Ariados->select == 1){
                                SDL_RectDef(&_background,Texture_Background[6]->backgroundWidth,Texture_Background[6]->backgroundHeight,90,277);
                                SDL_RenderCopy(renderer,Texture_Background[6]->background,NULL,&_background);
                            }
                            if(Dragonite->select == 1){
                                SDL_RectDef(&_background,Texture_Background[7]->backgroundWidth,Texture_Background[7]->backgroundHeight,306,277);
                                SDL_RenderCopy(renderer,Texture_Background[7]->background,NULL,&_background);
                            }
                            if(Onix->select == 1){
                                SDL_RectDef(&_background,Texture_Background[8]->backgroundWidth,Texture_Background[8]->backgroundHeight,522,277);
                                SDL_RenderCopy(renderer,Texture_Background[8]->background,NULL,&_background);
                            }
                            if(Harbok->select == 1){
                                SDL_RectDef(&_background,Texture_Background[9]->backgroundWidth,Texture_Background[9]->backgroundHeight,90,354);
                                SDL_RenderCopy(renderer,Texture_Background[9]->background,NULL,&_background);
                            }
                            if(Raichu->select == 1){
                                SDL_RectDef(&_background,Texture_Background[10]->backgroundWidth,Texture_Background[10]->backgroundHeight,306,354);
                                SDL_RenderCopy(renderer,Texture_Background[10]->background,NULL,&_background);
                            }
                            if(Pidgeot->select == 1){
                                SDL_RectDef(&_background,Texture_Background[12]->backgroundWidth,Texture_Background[10]->backgroundHeight,90,431);
                                SDL_RenderCopy(renderer,Texture_Background[12]->background,NULL,&_background); 
                            }
                            if(Snorlak->select==1){
                                SDL_RectDef(&_background,Texture_Background[13]->backgroundWidth,Texture_Background[13]->backgroundHeight,306,431);
                                SDL_RenderCopy(renderer,Texture_Background[13]->background,NULL,&_background);
                            }
                            if(Machamp->select ==1){
                                SDL_RectDef(&_background,Texture_Background[14]->backgroundWidth,Texture_Background[10]->backgroundHeight,522,431);
                                SDL_RenderCopy(renderer,Texture_Background[14]->background,NULL,&_background); 
                            }
                            frame_limit = SDL_GetTicks()+FPS_LIMIT;
                            SDL_RenderPresent(renderer);
                            Alakazam->select=1;
                            Character_select++;
                        }
                        //-------------------------- Button Pidgeot ----------------------//
                        if(event.motion.x >=90 && event.motion.x<=274 && event.motion.y>=431 && event.motion.y<=500 && Pidgeot->select==0 && Character_select<3){
                            printf("Click sur Pidgeot %dx|%dy Button Venuzaur \n",event.button.x,event.button.y);
                            SDL_RenderClear(renderer);
                            limit_fps(frame_limit);
                            SDL_RectDef(&_background,Texture_Background[2]->backgroundWidth,Texture_Background[2]->backgroundHeight,(WINDOW_WIDTH - Texture_Background[2]->backgroundWidth)/2,(WINDOW_HEIGTH - Texture_Background[2]->backgroundHeight)/2);
                            SDL_RenderCopy(renderer,Texture_Background[2]->background,NULL,&_background);
                            SDL_RectDef(&_background,Texture_Background[12]->backgroundWidth,Texture_Background[12]->backgroundHeight,90,431);
                            SDL_RenderCopy(renderer,Texture_Background[12]->background,NULL,&_background);
                            if(Charizard->select == 1){
                                SDL_RectDef(&_background,Texture_Background[3]->backgroundWidth,Texture_Background[3]->backgroundHeight,90,200);
                                SDL_RenderCopy(renderer,Texture_Background[3]->background,NULL,&_background);
                            }
                            if(Vanusaur->select == 1){
                                SDL_RectDef(&_background,Texture_Background[4]->backgroundWidth,Texture_Background[4]->backgroundHeight,306,200);
                                SDL_RenderCopy(renderer,Texture_Background[4]->background,NULL,&_background);
                            }
                            if(Tortoise->select == 1){
                                SDL_RectDef(&_background,Texture_Background[5]->backgroundWidth,Texture_Background[5]->backgroundHeight,522,200);
                                SDL_RenderCopy(renderer,Texture_Background[5]->background,NULL,&_background);
                            }
                            if(Ariados->select == 1){
                                SDL_RectDef(&_background,Texture_Background[6]->backgroundWidth,Texture_Background[6]->backgroundHeight,90,277);
                                SDL_RenderCopy(renderer,Texture_Background[6]->background,NULL,&_background);
                            }
                            if(Dragonite->select == 1){
                                SDL_RectDef(&_background,Texture_Background[7]->backgroundWidth,Texture_Background[7]->backgroundHeight,306,277);
                                SDL_RenderCopy(renderer,Texture_Background[7]->background,NULL,&_background);
                            }
                            if(Onix->select == 1){
                                SDL_RectDef(&_background,Texture_Background[8]->backgroundWidth,Texture_Background[8]->backgroundHeight,522,277);
                                SDL_RenderCopy(renderer,Texture_Background[8]->background,NULL,&_background);
                            }
                            if(Harbok->select == 1){
                                SDL_RectDef(&_background,Texture_Background[9]->backgroundWidth,Texture_Background[9]->backgroundHeight,90,354);
                                SDL_RenderCopy(renderer,Texture_Background[9]->background,NULL,&_background);
                            }
                            if(Raichu->select == 1){
                                SDL_RectDef(&_background,Texture_Background[10]->backgroundWidth,Texture_Background[10]->backgroundHeight,306,354);
                                SDL_RenderCopy(renderer,Texture_Background[10]->background,NULL,&_background);
                            }
                            if(Alakazam->select == 1){
                                SDL_RectDef(&_background,Texture_Background[11]->backgroundWidth,Texture_Background[11]->backgroundHeight,522,354);
                                SDL_RenderCopy(renderer,Texture_Background[11]->background,NULL,&_background);
                            }
                            if(Snorlak->select==1){
                                SDL_RectDef(&_background,Texture_Background[13]->backgroundWidth,Texture_Background[13]->backgroundHeight,306,431);
                                SDL_RenderCopy(renderer,Texture_Background[13]->background,NULL,&_background);
                            }
                            if(Machamp->select ==1){
                                SDL_RectDef(&_background,Texture_Background[14]->backgroundWidth,Texture_Background[10]->backgroundHeight,522,431);
                                SDL_RenderCopy(renderer,Texture_Background[14]->background,NULL,&_background); 
                            }
                            frame_limit = SDL_GetTicks()+FPS_LIMIT;
                            SDL_RenderPresent(renderer);
                            Pidgeot->select=1;
                            Character_select++;
                        }
                        //-------------------------- Button Snorlak ----------------------//
                        if(event.motion.x >= 306 && event.motion.x<=492 && event.motion.y>=431 && event.motion.y<=500 && Snorlak->select==0 && Character_select<3){
                            printf("Click sur Snorlak %dx|%dy Button Venuzaur \n",event.button.x,event.button.y);
                            SDL_RenderClear(renderer);
                            limit_fps(frame_limit);
                            SDL_RectDef(&_background,Texture_Background[2]->backgroundWidth,Texture_Background[2]->backgroundHeight,(WINDOW_WIDTH - Texture_Background[2]->backgroundWidth)/2,(WINDOW_HEIGTH - Texture_Background[2]->backgroundHeight)/2);
                            SDL_RenderCopy(renderer,Texture_Background[2]->background,NULL,&_background);
                            SDL_RectDef(&_background,Texture_Background[13]->backgroundWidth,Texture_Background[13]->backgroundHeight,306,431);
                            SDL_RenderCopy(renderer,Texture_Background[13]->background,NULL,&_background);
                            if(Charizard->select == 1){
                                SDL_RectDef(&_background,Texture_Background[3]->backgroundWidth,Texture_Background[3]->backgroundHeight,90,200);
                                SDL_RenderCopy(renderer,Texture_Background[3]->background,NULL,&_background);
                            }
                            if(Vanusaur->select == 1){
                                SDL_RectDef(&_background,Texture_Background[4]->backgroundWidth,Texture_Background[4]->backgroundHeight,306,200);
                                SDL_RenderCopy(renderer,Texture_Background[4]->background,NULL,&_background);
                            }
                            if(Tortoise->select == 1){
                                SDL_RectDef(&_background,Texture_Background[5]->backgroundWidth,Texture_Background[5]->backgroundHeight,522,200);
                                SDL_RenderCopy(renderer,Texture_Background[5]->background,NULL,&_background);
                            }
                            if(Ariados->select == 1){
                                SDL_RectDef(&_background,Texture_Background[6]->backgroundWidth,Texture_Background[6]->backgroundHeight,90,277);
                                SDL_RenderCopy(renderer,Texture_Background[6]->background,NULL,&_background);
                            }
                            if(Dragonite->select == 1){
                                SDL_RectDef(&_background,Texture_Background[7]->backgroundWidth,Texture_Background[7]->backgroundHeight,306,277);
                                SDL_RenderCopy(renderer,Texture_Background[7]->background,NULL,&_background);
                            }
                            if(Onix->select == 1){
                                SDL_RectDef(&_background,Texture_Background[8]->backgroundWidth,Texture_Background[8]->backgroundHeight,522,277);
                                SDL_RenderCopy(renderer,Texture_Background[8]->background,NULL,&_background);
                            }
                            if(Harbok->select == 1){
                                SDL_RectDef(&_background,Texture_Background[9]->backgroundWidth,Texture_Background[9]->backgroundHeight,90,354);
                                SDL_RenderCopy(renderer,Texture_Background[9]->background,NULL,&_background);
                            }
                            if(Raichu->select == 1){
                                SDL_RectDef(&_background,Texture_Background[10]->backgroundWidth,Texture_Background[10]->backgroundHeight,306,354);
                                SDL_RenderCopy(renderer,Texture_Background[10]->background,NULL,&_background);
                            }
                            if(Alakazam->select == 1){
                                SDL_RectDef(&_background,Texture_Background[11]->backgroundWidth,Texture_Background[11]->backgroundHeight,522,354);
                                SDL_RenderCopy(renderer,Texture_Background[11]->background,NULL,&_background);
                            }
                            if(Pidgeot->select == 1){
                                SDL_RectDef(&_background,Texture_Background[12]->backgroundWidth,Texture_Background[10]->backgroundHeight,90,431);
                                SDL_RenderCopy(renderer,Texture_Background[12]->background,NULL,&_background); 
                            }
                            if(Machamp->select ==1){
                                SDL_RectDef(&_background,Texture_Background[14]->backgroundWidth,Texture_Background[10]->backgroundHeight,522,431);
                                SDL_RenderCopy(renderer,Texture_Background[14]->background,NULL,&_background); 
                            }
                            frame_limit = SDL_GetTicks()+FPS_LIMIT;
                            SDL_RenderPresent(renderer);
                            Snorlak->select=1;
                            Character_select++;
                        }
                        //-------------------------- Button Machamp ---------------------//
                        if(event.motion.x >= 522 && event.motion.x <= 706 && event.motion.y>=431 && event.motion.y<=500 && Machamp->select==0 && Character_select<3){
                            printf("Click sur Machamp %dx|%dy Button Machamp \n",event.button.x,event.button.y);
                            SDL_RenderClear(renderer);
                            limit_fps(frame_limit);
                            SDL_RectDef(&_background,Texture_Background[2]->backgroundWidth,Texture_Background[2]->backgroundHeight,(WINDOW_WIDTH - Texture_Background[2]->backgroundWidth)/2,(WINDOW_HEIGTH - Texture_Background[2]->backgroundHeight)/2);
                            SDL_RenderCopy(renderer,Texture_Background[2]->background,NULL,&_background);
                            SDL_RectDef(&_background,Texture_Background[14]->backgroundWidth,Texture_Background[14]->backgroundHeight,522,431);
                            SDL_RenderCopy(renderer,Texture_Background[14]->background,NULL,&_background);
                            if(Charizard->select == 1){
                                SDL_RectDef(&_background,Texture_Background[3]->backgroundWidth,Texture_Background[3]->backgroundHeight,90,200);
                                SDL_RenderCopy(renderer,Texture_Background[3]->background,NULL,&_background);
                            }
                            if(Vanusaur->select == 1){
                                SDL_RectDef(&_background,Texture_Background[4]->backgroundWidth,Texture_Background[4]->backgroundHeight,306,200);
                                SDL_RenderCopy(renderer,Texture_Background[4]->background,NULL,&_background);
                            }
                            if(Tortoise->select == 1){
                                SDL_RectDef(&_background,Texture_Background[5]->backgroundWidth,Texture_Background[5]->backgroundHeight,522,200);
                                SDL_RenderCopy(renderer,Texture_Background[5]->background,NULL,&_background);
                            }
                            if(Ariados->select == 1){
                                SDL_RectDef(&_background,Texture_Background[6]->backgroundWidth,Texture_Background[6]->backgroundHeight,90,277);
                                SDL_RenderCopy(renderer,Texture_Background[6]->background,NULL,&_background);
                            }
                            if(Dragonite->select == 1){
                                SDL_RectDef(&_background,Texture_Background[7]->backgroundWidth,Texture_Background[7]->backgroundHeight,306,277);
                                SDL_RenderCopy(renderer,Texture_Background[7]->background,NULL,&_background);
                            }
                            if(Onix->select == 1){
                                SDL_RectDef(&_background,Texture_Background[8]->backgroundWidth,Texture_Background[8]->backgroundHeight,522,277);
                                SDL_RenderCopy(renderer,Texture_Background[8]->background,NULL,&_background);
                            }
                            if(Harbok->select == 1){
                                SDL_RectDef(&_background,Texture_Background[9]->backgroundWidth,Texture_Background[9]->backgroundHeight,90,354);
                                SDL_RenderCopy(renderer,Texture_Background[9]->background,NULL,&_background);
                            }
                            if(Raichu->select == 1){
                                SDL_RectDef(&_background,Texture_Background[10]->backgroundWidth,Texture_Background[10]->backgroundHeight,306,354);
                                SDL_RenderCopy(renderer,Texture_Background[10]->background,NULL,&_background);
                            }
                            if(Alakazam->select == 1){
                                SDL_RectDef(&_background,Texture_Background[11]->backgroundWidth,Texture_Background[11]->backgroundHeight,522,354);
                                SDL_RenderCopy(renderer,Texture_Background[11]->background,NULL,&_background);
                            }
                            if(Pidgeot->select == 1){
                                SDL_RectDef(&_background,Texture_Background[12]->backgroundWidth,Texture_Background[10]->backgroundHeight,90,431);
                                SDL_RenderCopy(renderer,Texture_Background[12]->background,NULL,&_background); 
                            }
                            if(Snorlak->select==1){
                                SDL_RectDef(&_background,Texture_Background[13]->backgroundWidth,Texture_Background[13]->backgroundHeight,306,431);
                                SDL_RenderCopy(renderer,Texture_Background[13]->background,NULL,&_background);
                            }
                            frame_limit = SDL_GetTicks()+FPS_LIMIT;
                            SDL_RenderPresent(renderer);
                            Machamp->select=1;
                            Character_select++;
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
    SDL_DestroyTexture(Texture_Background[3]->background);
    SDL_DestroyTexture(Texture_Background[4]->background);
    SDL_DestroyTexture(Texture_Background[5]->background);
    SDL_DestroyTexture(Texture_Background[6]->background);
    SDL_DestroyTexture(Texture_Background[7]->background);
    SDL_DestroyTexture(Texture_Background[8]->background);
    SDL_DestroyTexture(Texture_Background[9]->background);
    SDL_DestroyTexture(Texture_Background[10]->background);
    SDL_DestroyTexture(Texture_Background[11]->background);
    SDL_DestroyTexture(Texture_Background[12]->background);
    SDL_DestroyTexture(Texture_Background[13]->background);
    SDL_DestroyTexture(Texture_Background[14]->background);
    SDL_Destroyed(renderer,window,NULL);
    SDL_Quit();
    return EXIT_SUCCESS;
}
