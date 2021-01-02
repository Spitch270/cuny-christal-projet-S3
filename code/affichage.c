#include "gameplay.h"
#include "affichage.h"
#include "sdl2-ttf-light.h"


void clean_textures(ressources_t *textures)
{
    	clean_texture(textures->background);
	clean_texture(textures->menu);
	clean_font(textures->font);
};
void  init_textures(SDL_Renderer *renderer, ressources_t *textures)
{
    	textures->background = load_image( "ressources/fond.bmp",renderer);
	textures->menu = load_image( "ressources/menu.bmp",renderer);
};

void apply_background(SDL_Renderer *renderer, ressources_t *textures)
{
    if(textures->background != NULL)
	{
      		apply_texture(textures->background, renderer, 0, 0);
    	}
};
void apply_menu(SDL_Renderer *renderer, ressources_t *textures)
{
	if(textures->menu != NULL)
	{
      		apply_texture(textures->menu,renderer,0,0);
    	}
};
void refresh_graphics(SDL_Renderer *renderer, world_t *world,ressources_t *textures,int etat)
{
    	clear_renderer(renderer);
	if (etat==0)	
	{
		apply_background(renderer, textures);
	}
	if (etat==1)
	{
		apply_menu(renderer, textures);
	}
    	update_screen(renderer);
	
};
void clean(SDL_Window *window, SDL_Renderer * renderer,ressources_t *textures, world_t * world)
{
    clean_textures(textures);
    clean_sdl(renderer,window);
};
void init(SDL_Window **window, SDL_Renderer ** renderer, ressources_t *textures, world_t * world){
	init_ttf();
    	init_sdl(window,renderer,SCREEN_WIDTH, SCREEN_HEIGHT);
    	init_textures(*renderer,textures);
	
};



