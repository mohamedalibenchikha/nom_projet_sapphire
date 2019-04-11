
#include "aff.h"
 
 
int main(int argc, char ** argv)
{SDL_Event event;
int quit=1;
SDL_Init(SDL_INIT_VIDEO);
screen=SDL_SetVideoMode(600,600,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
SDL_FillRect(screen, NULL, SDL_MapRGBA(screen->format, 0,0,0,0));

while(quit)
{ SDL_Delay(200);
  coin=IMG_Load("coin.png");
     pos.x =50 ;
     pos.y =50 ;

SDL_BlitSurface(coin, NULL, screen, &pos);
SDL_Flip(screen);

SDL_WaitEvent(&event); 
switch(event.type)
{ case SDL_KEYDOWN:
switch (event.key.keysym.sym)
{
case SDLK_ESCAPE:
quit=0;
break;
} 
}




}
            SDL_Quit();

        return 0;
}
