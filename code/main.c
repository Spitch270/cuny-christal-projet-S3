
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
    int etat;
    etat=1;
	
	    //initialisation du jeu
	    init(&window,&renderer,&textures,&world);
	    while(etat==1)
	{ //tant que le jeu n'est pas fini

	  
		
        
	        //mise à jour des données liée à la physique du monde
	       
	        
	        //rafraichissement de l'écran
	        refresh_graphics(renderer,&world,&textures,etat);
		
		while(SDL_PollEvent(&event))	
		{
			if(event.type == SDL_MOUSEBUTTONDOWN)
			{
				xMouse=event.button.x;
				yMouse=event.button.y;
				//*printf("x=%d\n",xMouse);
				//*printf("y=%d\n",yMouse);
				//*quitter le menu
				if(sprites_collide(xMouse,yMouse,365,200,15,50)==1 && etat==1)
				{
					clean(window,renderer,&textures,&world);
					return 0;
				}
				//*jouer
				if(sprites_collide(xMouse,yMouse,365,150,15,50)==1 && etat==1)
				{
	
					etat=0;	
					printf("etat=%d\n",etat);
					
				}
				
			}
		}
		
		
        
	        // pause de 10 ms pour controler la vitesse de rafraichissement
	        pause(10);
    
	}
    
    //nettoyage final
    clean(window,renderer,&textures,&world);
	  
   
       return 0;
}
