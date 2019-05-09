#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "work.h"
int main()
{
char pause;
ecran e;
perso p;
int done=1;
p.continuer = 1;
SDL_Init(SDL_INIT_EVERYTHING);



SDL_EnableKeyRepeat(30,30);
 init_positions(&e,&p);
while(done)
{

 init_affich(&e,&p);
 key_event ( &p,&e);
SDL_Flip(e.e);
}

SDL_Quit();
return 0 ;
}



