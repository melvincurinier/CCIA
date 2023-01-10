#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#define WINDOW_WIDTH 800
#define WINDOW_HEIGTH 600                                                                                                        
#define FPS_LIMIT 33

void SDL_ExitWithError(const char *);
void SDL_Destroyed(SDL_Renderer *,SDL_Window *);
void limit_fps(unsigned int);
void menu_principal();
void menu_combattant();
void in_game();