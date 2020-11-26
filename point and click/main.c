/**
 * \file main.c
 * \brief Programme principal initial du niveau 1
 * \author Mathieu Constant
 * \version 1.0
 * \date 18 mars 2020
 */
#include <math.h>
#include <string.h>
#include "gameplay.h"
#include "affichage.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdbool.h>


/**
 *  \brief programme principal qui implémente la boucle du jeu
 */


int main( int argc, char* args[] )
{
    srand(time(NULL));
    SDL_Event event;
    world_t world;
    ressources_t textures;
    SDL_Renderer *renderer;
    SDL_Window *window;
    int xMouse,yMouse;
	
	    //initialisation du jeu
	    init(&window,&renderer,&textures,&world);
	    while(!is_game_over(&world)){ //tant que le jeu n'est pas fini
	        //gestion des évènements
	        handle_events(&event,&world);
		
        
	        //mise à jour des données liée à la physique du monde
	        update_data(&world);
	        
	        //rafraichissement de l'écran
	        refresh_graphics(renderer,&world,&textures);
		
		while(SDL_PollEvent(&event))	
		{
			if(event.type == SDL_MOUSEBUTTONDOWN)
			{
			xMouse=event.button.x;
			yMouse=event.button.y;
			}
		}
		printf("x=%d\n",xMouse);
		printf("y=%d\n",yMouse);
        
	        // pause de 10 ms pour controler la vitesse de rafraichissement
	        pause(10);
    
	}
    
    //nettoyage final
    clean(window,renderer,&textures,&world);
   
       return 0;
}
