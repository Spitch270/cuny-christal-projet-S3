#include "affichage.h"
#include "gameplay.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "SDL.h"



int sprites_collide(int xMouse,int yMouse,int xObjet,int yObjet,int largeurObjet,int longueurObjet)
{
	if(xMouse < longueurObjet+xObjet && xMouse+longueurObjet > xObjet  && yMouse < largeurObjet+yObjet && yMouse+largeurObjet > yObjet )
	{
		return 1; //les sprites sont en collision
	}
	return 0;	//les sprites ne sont pas en collision
};

