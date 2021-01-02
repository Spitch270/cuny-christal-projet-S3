//*#include "SDL.h"
//*#include <SDL/SDL_image.h>
 
int main ( int argc, char** argv )
{
    SDL_Surface* menu[2]={0};
    SDL_Surface* ecran=0;
    SDL_Rect pos={0,0,0,0};
    SDL_Event event;
    int i;
    int choix_menu=0;
 
    SDL_Init(SDL_INIT_VIDEO);
 
    menu[0]=IMG_Load("ressources/menu.bmp");
    menu[1]=IMG_Load("ressources/fond.bmp");
    
 
    ecran=SDL_SetVideoMode(800,600,32,SDL_HWSURFACE);
    i=1;
    while (i)
    {
        if (choix_menu>=2) choix_menu=0;
        SDL_WaitEvent(&event);
 
        switch (event.type)
        {
        case SDL_MOUSEBUTTONDOWN:
            if (event.button.button == SDL_BUTTON_LEFT)  choix_menu++;
 
            break;
        case SDL_QUIT:
            i=0;
            break;
        }
 
        SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,0,0,0));
        SDL_BlitSurface(menu[choix_menu],NULL,ecran,&pos);
        SDL_Flip(ecran);
    }
 
    for(i=0;i<2;i++) SDL_FreeSurface(menu[i]);
    SDL_Quit();
 
    return 0;
}
