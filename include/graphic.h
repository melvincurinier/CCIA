#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include "joueur.h"
//----- Taille Fenêtre -----//
#define WINDOW_WIDTH 800
#define WINDOW_HEIGTH 600 
//----- Definition de la limite des FPS -----//                                                                                                       
#define FPS_LIMIT 33
//----- Definition de l'index -----//
#define MAIN_MENU 0 // Menu Principal (default)
#define CHOOSE_PLAYER_MENU 1// Menu choix personnage
#define GAMEPLAY 2 // interface de la partie
//---------- Structure Pokemon -----------//
struct __s_pokemon_texture{
    SDL_Texture * texture_face;
    //SDL_Texture * texture_dos;
    int pokemon_width_face;
    int pokemon_height_face;
    int select;
   // int pokemon_width_dos;
   // int pokemon_height_dos;
};
typedef struct __s_pokemon_texture * pokemon_texture;

//---------------- structure contenant toute les info de notre affichage (hors pokemon) ------------//
struct __s_background
{
    SDL_Texture * background;
    int backgroundWidth;
    int backgroundHeight;
    int posX;
    int posY;
};
typedef struct __s_background * Background;


void SDL_ExitWithError(const char *);
void SDL_Destroyed(SDL_Renderer *,SDL_Window *,pokemon_texture);
void limit_fps(unsigned int);

//-------------------- Gestion de la creation et le stockage des menu ----------------------------//
Background initBackground(SDL_Renderer * _Renderer,SDL_Window * _Window,char * _TextureAdresse,int _Width,int _Height);
Background * initBackgroundTable();
Background * placeBackground(Background _Background,Background * _TableBackground,int pos);

//-------------------- Gestion de la creation et le stockage de Pokemon ----------------------------//
pokemon_texture initPokemon(SDL_Renderer * _Renderer,SDL_Window * _Window,char * _TexturePokemonAdresse,int _Width,int _Height);

//
void SDL_RectDef(SDL_Rect * _Rect,int _Width,int _Height,int _PosX,int _PosY);