#include <stdio.h> 
#include <SDL/SDL.h>
#include<SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>

typedef struct {
    SDL_Surface* img[3];

    int valeur; 
}coin;

int quit=1;




void init_coin(coin* c){
    c->img[0] = IMG_Load("coin.png");
    c->img[1] = IMG_Load("2.png");
    c->img[2] = IMG_Load("3.png");
    c->img[3] = IMG_Load("4.png");
    c->valeur=10;
}


void main(){
    SDL_Event event;
    


int i=0 ;
coin c;
SDL_Rect pos; 
pos.x=0;
pos.y=0;
SDL_Surface* bg; 
SDL_Init(SDL_INIT_VIDEO);
bg=SDL_SetVideoMode(300,300,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
 SDL_WaitEvent(&event);

while(quit)
{ 
SDL_Delay(100);
init_coin(&c);
SDL_BlitSurface(c.img[i%3],NULL,bg,&pos); 
SDL_Flip(bg);
i++;
//SDL_WaitEvent(&event);
switch(event.type)
{
  case SDL_KEYDOWN:
switch (event.key.keysym.sym)
{
case SDL_QUIT:
quit=0;
break;

}
}

}
SDL_Quit();
}

