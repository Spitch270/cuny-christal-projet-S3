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

#define SHIP_SIZE 32

/**
 * \brief Taille du missile
*/
#define BOSS_H 70
/*taille du boss hauteur*/

#define BOSS_L 56
/*taille du boss largeur*/

#define MISSILE_SIZE 8/**
 * \brief Représentation d'un vaisseau
*/

#define VERTICAL_DIST 2*SHIP_SIZE

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


typedef struct world_s world_t;

/**
 * \brief fonction qui définie les regles du jeu
*/
void compute_game(world_t *world);

/**
 * \brief fonction qui calcule le score
*/
int calcul_score(world_t * world);

/**
 * \brief fonction retourne le champ score d'un sprite
*/
int lire_sprite_s(sprite_t *sprite);

/**
 * \brief fonction qui retourne le champ is_visible d'un sprite
*/

int lire_sprite_is_visible(sprite_t *sprite);

/**
 * \brief fonction qui initialise les données du jeu
*/

void init_data(world_t * world);


/**
 * \brief La fonction initialise les données du sprite
 */
void init_sprite(sprite_t *sprite, int x, int y, int w, int h, int v,int visible,int s,int b,int boss);

/**
 * \brief La fonction nettoie les données du monde
 * \param world les données du monde
 */


void clean_data(world_t *world);

/**
 * \brief La fonction affiche les champs d'un sprite
 */
void print_sprite(sprite_t * sprite);

/**
 * \brief La fonction indique si le jeu est fini en fonction des données du monde
 * \param world les données du monde
 * \return 1 si le jeu est fini, 0 sinon
 */

int is_game_over(world_t *world);

/**
*\brief La fonction qui met à jour la position de l'enemie
*/
void update_ennemies(world_t *world);

/**
 * \brief La fonction met à jour les données en tenant compte de la physique du monde
 * \param les données du monde
 */

void update_data(world_t *world);


/**
 * \brief La fonction gère les évènements ayant eu lieu et qui n'ont pas encore été traités
 * \param event paramètre qui contient les événements
 * \param world les données du monde
 */



void handle_events(SDL_Event *event,world_t *world);

/**
 * \brief fonction qui vérifie si le vaisseau sort de l'écran
*/

void limite_horizontale(sprite_t *sprite);

/**
 * \brief fonction qui vérifie si l'ennemie sort de l'écran
*/

void limite_verticale(sprite_t *sprite);


/**
 * \brief fonction qui indique si les sprites en paramètres sont encollisions
*\renvoie 1 en cas de collision 0 sinon
*/

int sprites_collide(sprite_t *sp2, sprite_t *sp1);

/**
 * \brief fonction qui rend invisibles les sprites en collision
*/
void handle_sprites_collision(sprite_t* s1,sprite_t* s2);

/**
 * \brief fonction qui initialise les ennemies
*/
void init_ennemies(world_t* world);

/**
 * \brief fonction qui initialise les étoiles pour le bouclier
*/

void init_etoiles(world_t* world);

/**
 * \brief fonction qui genère des un nombre aléatoire entre a et b
*/
int generate_number(int a,int b);

/**
*\brief La fonction qui met à jour la position des étoiles
*/
void update_etoile(world_t *world);

/**
*\brief La fonction qui gère la collision entre le vaisseau et l'étoile
*/
void handle_star_collision(sprite_t* s1,sprite_t* s2);

/**
*\brief La fonction qui gère le comportement du boss
*/
void boss(world_t* world);
#endif
