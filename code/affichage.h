#ifndef H_AFFICHAGE
#define H_AFFICHAGE
#include "gameplay.h"
#include "sdl2-light.h"
#include "sdl2-ttf-light.h"


#define SCREEN_WIDTH 720
#define SCREEN_HEIGHT 420

struct ressources_s
{
    	SDL_Texture* background; 
	SDL_Texture* menu;
	SDL_Texture* scene1;
	TTF_Font * font; 
	
};


typedef struct ressources_s ressources_t;


typedef struct world_s world_t;




void handle_events(SDL_Event *event,world_t *world);


void clean_textures(ressources_t *textures);


void  init_textures(SDL_Renderer *renderer, ressources_t *textures);


void apply_background(SDL_Renderer *renderer, ressources_t *textures);

void apply_sprite(SDL_Renderer *renderer, SDL_Texture *texture, sprite_t *sprite);

void refresh_graphics(SDL_Renderer *renderer, world_t *world,ressources_t *textures,int etat);


void clean(SDL_Window *window, SDL_Renderer * renderer, ressources_t *textures, world_t * world);

void init(SDL_Window **window, SDL_Renderer ** renderer, ressources_t *textures, world_t * world);



#endif
