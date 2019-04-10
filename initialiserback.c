#include "menu.h"
background initialiser_background(char *cheminImage, char *cheminMusique)
{
background b ;
b.back = IMG_Load(cheminImage) ;
b.music =  Mix_Music(cheminMusique) ;
b.positionback.x = 0 ;
b.positionback.y = 0 ;
return b ;
}
/*
boutton initialiser_boutton(char *cheminIm1 , char *cheminIm2 , int x,y,char *cheminSound )
{
boutton bt ;
bt.image[0] = IMG_Load(cheminIm1) ;
bt.image[1] = IMG_Load(cheminIm2) ;
bt.bref = Mix_Chunk(cheminsound) ;
bt.positionbt.x = x ;
bt.positionbt.y = y ;
bt.num = 0 ;
return bt ; 
}*/

