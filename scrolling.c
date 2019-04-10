#include "scrolling.h"
void centerScrollingOnPlayer(Hero *hero, Acteurs* acteurs)
{
//if(hero->a==1/* && hero->ground == OUI*/)
//{
//acteurs->camera.y = 30;	
//}
 //if( acteurs->camera.y <= 280  )
//{
//acteurs->camera.y +=15;
//}
if(acteurs->event.type == SDL_KEYDOWN)
	{
		if(acteurs->event.key.keysym.sym == SDLK_RIGHT || acteurs->event.key.keysym.sym == SDLK_SPACE )
	{
		if((hero->x + PLAYER_WIDTH/2) > SCREEN_WIDTH/2)
			{
				
				acteurs->camera.x += hero->PLAYER_SPEED;
			}
		if(acteurs->camera.x > Backg_W - SCREEN_WIDTH)
			{
				
				acteurs->camera.x = Backg_W - SCREEN_WIDTH;
			}
	}
	else if(acteurs->event.key.keysym.sym == SDLK_LEFT)
	{
				
				acteurs->camera.x -= hero->PLAYER_SPEED;

		if((hero->x + PLAYER_WIDTH/2) > (Backg_W - SCREEN_WIDTH/2))
		{
			
			acteurs->camera.x = Backg_W - SCREEN_WIDTH;
		}
			
		if(acteurs->camera.x < 0)
			{
				acteurs->camera.x = 0;
			}
	}
         	
 }
}

