#ifndef H_GAMEPLAY
#define H_GAMEPLAY
#include "sdl2-light.h"
#include "sdl2-ttf-light.h"







/**
 * \brief Taille d'un vaisseau
 */



struct sprite_s{
	int x;	/**abcsisse*/
	int y;	/**ordonnée*/
	int h;	/**hauteur*/
	int w;	/**largeur*/
	int is_visible; /**sprite visible ou non*/
	
};

/**
 * \brief Type qui correspond aux données d'un vaisseau
 */


typedef struct sprite_s sprite_t;

/**
 * \brief Représentation du monde du jeu
*/

struct world_s{
	sprite_t * menu;
	sprite_t * scene1;
	int score;	/**champ indiquant le score*/
	int gameover; /*!< Champ indiquant si l'on est à la fin du jeu */
	int vague;	/**champ indiquant le numéro d ela vague*/
	int temp;	/**champ indiquant le temps*/

};
/**
 * \brief Type qui correspond aux données du monde
 */
int sprites_collide(int xMouse,int yMouse,int xObjet,int yObjet,int largeurObjet,int longueurObjet);

typedef struct world_s world_t;


#endif
