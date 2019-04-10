#include <stdio.h>
#include <SDL/SDL.h>
#include <stdlib.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
typedef struct
{
SDL_Surface *back ;
Mix_Music *music ;
SDL_Rect positionback ;
}background ;

typedef struct 
{
SDL_Surface *image[2] ;
SDL_Rect positionimage ;
Mix_Chunk *bref ;
int num ;
}boutton ;

typedef struct
{
background b ;
int nbrBoutton ;
boutton *tab ;
SDL_Surface *animation ;
SDL_Rect positionanimation ;
}menu ;

background initialiser_background(char *cheminImage, char *cheminMusique) ;
boutton initialiser_boutton(char *cheminIm1 , char *cheminIm2 , int x,y,char *cheminSound ) ;
void afficher_background(background b,SDL_Surface *screen ) ;
//update_menu (int c ,int *pos

