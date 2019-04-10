void afficher_background(background b,SDL_Surface *screen )
{
	
	SDL_BlitSurface(b.back,NULL,screen,&b.positionback) ;
}
