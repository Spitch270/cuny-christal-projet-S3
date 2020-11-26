#include "affichage.h"
#include "gameplay.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "SDL.h"



int generate_number(int a,int b){
	
}


void compute_game(world_t * world)
{
	

	


}



int lire_sprite_s(sprite_t *sprite)
{
	
}

int lire_sprite_is_visible(sprite_t *sprite)
{
	
}

void init_data(world_t * world){
	
};

void init_sprite(sprite_t *sprite, int x, int y, int w, int h, int v,int visible,int s,int b,int boss){
	
};

void clean_data(world_t *world){

};
void print_sprite(sprite_t * sprite)
{

};


int is_game_over(world_t *world){
    
};


void update_ennemies(world_t *world)
{	

}

void update_etoiles(world_t *world)
{	


}


void update_data(world_t *world){
	compute_game(world);
	
	
};


void handle_events(SDL_Event *event,world_t *world){
    
};
/**
 * \brief fonction qui vérifie si le vaisseau sort de l'écran*/

void limite_horizontale(sprite_t *sprite)
{

};


void limite_verticale(sprite_t *sprite){
	
};


int sprites_collide(sprite_t *sp2, sprite_t *sp1){
	
};


void handle_sprites_collision(sprite_t* s1,sprite_t* s2)
{
	
};

/**
*\brief La fonction qui gère la collision entre le vaisseau et l'étoile
*/
void handle_star_collision(sprite_t* s1,sprite_t* s2)
{
	
}

/**
 * \brief fonction qui initialise les ennemies
*/
void init_ennemies(world_t* world)
{

}

/**
 * \brief fonction qui initialise les etoiles
*/
void init_etoiles(world_t* world)
{
	
}

/**
*\brief La fonction qui gère le comportement du boss
*/
void boss(world_t* world)
{
	
	
}
