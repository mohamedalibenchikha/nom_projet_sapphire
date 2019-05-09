#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "work.h"
void init_positions(ecran *e,perso *p)
{
e->positionFond.x=0;
e->positionFond.y=0;

p->posPer.x=20;
p->posPer.y=350;

e->posmini.x=480;
e->posmini.y=20;


e->posnokta.x=485;
e->posnokta.y=100;

}

void init_affich(ecran *e,perso *p)
{
e->e=SDL_SetVideoMode(1200,600,32, SDL_HWSURFACE |SDL_DOUBLEBUF);
e->imageFond = SDL_LoadBMP("nature.bmp");
p->personnage = IMG_Load("personnage.png");
e->imagemini=IMG_Load("mini.png");
e->imagenokta=IMG_Load("nokta.png");



SDL_BlitSurface(e->imageFond, NULL, e->e , &e->positionFond);
SDL_BlitSurface(p->personnage, NULL, e->e, &p->posPer);
SDL_BlitSurface(e->imagemini,NULL,e->e,&e->posmini);
SDL_BlitSurface(e->imagenokta,NULL,e->e,&e->posnokta);

}


void key_event ( perso *p,ecran *e)
{


    while(p->continuer)
  {
        SDL_PollEvent(&p->event);
        switch(p->event.type){
        case SDL_QUIT:
        p->continuer=0;
        break;
        case SDL_KEYDOWN:
            switch(p->event.key.keysym.sym){
        case SDLK_RIGHT:
            if (p->posPer.x<1200-p->personnage->w){
          p->posPer.x+=7;
          e->posnokta.x+=2;
            }
            SDL_WaitEvent(&p->event);
            break;
        case SDLK_LEFT:
            if (p->posPer.x>0){
           p->posPer.x-=7;
           e->posnokta.x-=2;
            }
            SDL_WaitEvent(&p->event);
            break;
            }
           break;
       }

 SDL_BlitSurface(e->imageFond,NULL,e->e,&e->positionFond);
 SDL_BlitSurface(p->personnage,NULL,e->e,&p->posPer);
 SDL_BlitSurface(e->imagemini,NULL,e->e,&e->posmini);
 SDL_BlitSurface(e->imagenokta,NULL,e->e,&e->posnokta);
 SDL_Flip(e->e);
    }
}


