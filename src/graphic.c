#include "graphic.h"

//----------- affichage message d'erreur ----------//
void SDL_ExitWithError(const char * message){
    SDL_Log("Error : -> %s \n",message, SDL_GetError());
    SDL_Quit();
    exit(EXIT_FAILURE);
}

//------------ Libérer la mémoire des texture -------------//
void Destroy_Pokemon_Texture(pokemon_texture _Pokemon_Texture){
    SDL_DestroyTexture(_Pokemon_Texture->texture_face);
    //SDL_DestroyTexture(_Pokemon_Texture->texture_dos);
}

//------------ Liberation d'espace ----------------//
void SDL_Destroyed(SDL_Renderer * _Renderer,SDL_Window * _Window,pokemon_texture _Pokemon_Texture){
    Destroy_Pokemon_Texture(_Pokemon_Texture);
    SDL_DestroyRenderer(_Renderer);
    SDL_DestroyWindow(_Window);
    SDL_Quit();
}
//------------- Garder un flux constant de FPS ------------//
void limit_fps(unsigned int limit){
    unsigned int ticks = SDL_GetTicks();
    if(limit< ticks) return;
    else if(limit >ticks+FPS_LIMIT)SDL_Delay(FPS_LIMIT);
    else SDL_Delay(limit-ticks);
}

//---------- Creation du pokemon ------------//
pokemon_texture initPokemon(SDL_Renderer * _Renderer,SDL_Window * _Window,char * _TexturePokemonAdresse,int _Width,int _Height){
    pokemon_texture pokemonTexture = malloc(sizeof(pokemon_texture));
    pokemonTexture->texture_face = IMG_LoadTexture(_Renderer,_TexturePokemonAdresse);
    if(pokemonTexture->texture_face == NULL){
        SDL_Destroyed(_Renderer,_Window,NULL);
        SDL_ExitWithError("Renderer texture creation failed");
    }
    pokemonTexture->pokemon_width_face = _Width;
    pokemonTexture->pokemon_height_face = _Height;
    return pokemonTexture;
} 

//---------------- Creation d'un background ---------------//
Background initBackground(SDL_Renderer * _Renderer,SDL_Window * _Window,char * _TextureAdresse,int _Width,int _Height){
    Background background = malloc(sizeof(Background));
    background->background=IMG_LoadTexture(_Renderer,_TextureAdresse);
    if(background->background == NULL){
        SDL_Destroyed(_Renderer,_Window,NULL);
        SDL_ExitWithError("Renderer texture creation failed");
    }
    background->backgroundWidth=_Width;
    background->backgroundHeight=_Height;
    return background;
}
//------------------ Creation de tableau stockant nos background ----------------//
Background * initBackgroundTable(){
    //char * Texture[4]={"sprites/sprite_background_menu.png","sprites/sprite_button_play.png","sprites/Choose_player_menu.png",""};
    Background * backgroundTable = malloc(4*sizeof(Background));   
    for(int i=0;i<3;i++){
        backgroundTable[i]=NULL;
    }
    return backgroundTable; 
}
//---------------- Stockage des background dans des tableau ----------------------//
Background * placeBackground(Background _Background,Background * _TableBackground){
    int i=0;
    int placement = 0;
    while(i<12 && placement == 0){
        if(_TableBackground[i]==NULL){
            _TableBackground[i]=_Background;
            placement=1;
        }
        i=i+1;
    }
    return _TableBackground;
}



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