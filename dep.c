#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <time.h>

#define W_Screen 800
#define H_Screen 600
#define CMode 32

#define SPEED 2


#define SPRITE_H 148
#define SPRITE_W 102
#define MAX_FRAMES 6 



                     #define W_BackgImg 259
                     #define H_BackgImg 194

typedef struct enemy
{
	SDL_Surface* spriteleft;
	SDL_Surface* spriteright;

	SDL_Rect frame;
	SDL_Rect dst;
}Enemy;


int main(int argc, char** argv)
{
    SDL_Surface* screen = NULL;

	SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_NOPARACHUTE);
	screen = SDL_SetVideoMode(W_Screen, H_Screen, CMode, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_HWPALETTE /*| SDL_FULLSCREEN */| SDL_RESIZABLE /*| SDL_NOFRAME*/);

	Enemy enemy;
    
    SDL_Surface* backg = NULL;
    backg = IMG_Load("index.jpeg");
    SDL_BlitSurface(backg, NULL, screen, NULL);
    SDL_Flip(screen);

	enemy.spriteleft = IMG_Load("coin.png");
	enemy.spriteright = IMG_Load("coin.png");
	enemy.dst.x = 20;
	enemy.dst.y = 20;

	//Hide Cursor
	SDL_ShowCursor(SDL_DISABLE);

	int carryon = 1;
	while(carryon)
	{
		SDL_Event event;
		SDL_PollEvent(&event);

		int i;

		for(i = 0; i<MAX_FRAMES; i++)
		{
			enemy.frame.x = i*(Sint16)SPRITE_W;
			enemy.frame.y = 0;
			enemy.frame.w = SPRITE_W;
			enemy.frame.h = SPRITE_H;
			SDL_BlitSurface(backg, NULL, screen, NULL);
			SDL_BlitSurface(enemy.spriteright, &enemy.frame, screen, &enemy.dst);
			SDL_Flip(screen);
			SDL_Delay(100);
		}
		for(i = (MAX_FRAMES - 1); i>=0; i--)
		{
			enemy.frame.x = i*(Sint16)SPRITE_W;
			enemy.frame.y = 0;
			enemy.frame.w = SPRITE_W;
			enemy.frame.h = SPRITE_H;
			SDL_BlitSurface(backg, NULL, screen, NULL);
			SDL_BlitSurface(enemy.spriteleft, &enemy.frame, screen, &enemy.dst);
			SDL_Flip(screen);
			SDL_Delay(100);
		}

		switch(event.type)
		{
			case SDL_KEYDOWN:
			    if(event.key.keysym.sym == SDLK_ESCAPE)
			    {
			    	carryon = 0;
			    }
		}

	}
	SDL_Quit();
return 0;
}

