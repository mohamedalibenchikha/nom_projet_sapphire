#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "vie_score_temp.h"

void gestion_vie(Objet vie [],int *valeur_vie,Objet tabD [])
{
  if(*valeur_vie<4)
  (*valeur_vie)++ ;

  tabD[0].pos.x+=40;
  
}


void affiche_vie(SDL_Surface *screen , Objet vie [] ,int valeur_vie)
{
  if(valeur_vie<4)
  {
  SDL_BlitSurface (vie[valeur_vie].img,NULL,screen,&(vie[0].pos)) ;
  SDL_Flip(screen) ;
  }
  if(valeur_vie==4)
  {
  SDL_BlitSurface (vie[valeur_vie].img,NULL,screen,&(vie[4].pos)) ;
  SDL_Flip(screen) ;
  }

}
