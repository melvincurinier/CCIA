#include "graphic.h"

//----------- affichage message d'erreur ----------//
void SDL_ExitWithError(const char * message){
    SDL_Log("Error : -> %s \n",message, SDL_GetError());
    SDL_Quit();
    exit(EXIT_FAILURE);
}

//------------ Liberation d'espace ----------------//
void SDL_Destroyed(SDL_Renderer * _Renderer,SDL_Window * _Window){
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