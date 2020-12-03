#ifndef H_GAMEPLAY
#define H_GAMEPLAY
#include "sdl2-light.h"
#include "sdl2-ttf-light.h"




#define NB_ENNEMIES 6
#define NB_ETOILES 1

/**
 * \brief Largeur de l'écran de jeu
 */
#define SCREEN_WIDTH 250
/**
 * \brief Hauteur de l'écran de jeu
 */
#define SCREEN_HEIGHT 250


/**
 * \brief Taille d'un vaisseau
 */



struct sprite_s{
	int x;	/**abcsisse*/
	int y;	/**ordonnée*/
	int h;	/**hauteur*/
	int w;	/**largeur*/
	int v;	/**vitesse verticale*/
	int is_visible; /**sprite visible ou non*/
	int s; /** score ramener par cet ennemie*/
	int bouclier;
	int boss;/** indique au jeu si on doit mettre la taille du boss ou pas (0:non 1:oui)*/
};

/**
 * \brief Type qui correspond aux données d'un vaisseau
 */


typedef struct sprite_s sprite_t;

/**
 * \brief Représentation du monde du jeu
*/

struct world_s{
	//sprite_t * ennemie;	/**champ indiquant l'nenemi*/	
	sprite_t * ship;	/**champ indiquant le vaisseau*/
	sprite_t * missile;	/**champ indiquant le missile*/	
	sprite_t * ennemies[NB_ENNEMIES];	/**champ indiquant le tableau d'ennemies*/
	sprite_t * etoile[NB_ETOILES];	/**champ indiquant le tableau d'étoiles*/
	sprite_t * bouclier;/**champ indiquant le bouclier*/
	sprite_t * boss;/**champ indiquant le boss*/
	sprite_t * bm;/**champ indiquand le misslie du boss*/
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
