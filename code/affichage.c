#include "gameplay.h"
#include "affichage.h"
#include "sdl2-ttf-light.h"


void clean_textures(ressources_t *textures)
{
    	clean_texture(textures->background);
	clean_font(textures->font);
};
void  init_textures(SDL_Renderer *renderer, ressources_t *textures)
{
    	textures->background = load_image( "ressources/fond.bmp",renderer);
};

void apply_background(SDL_Renderer *renderer, ressources_t *textures)
{
    if(textures->background != NULL)
	{
      		apply_texture(textures->background, renderer, 0, 0);
    	}
};
void apply_sprite(SDL_Renderer *renderer, SDL_Texture *texture, sprite_t *sprite)
{

};
void refresh_graphics(SDL_Renderer *renderer, world_t *world,ressources_t *textures)
{
    	clear_renderer(renderer);
	apply_background(renderer, textures);
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



