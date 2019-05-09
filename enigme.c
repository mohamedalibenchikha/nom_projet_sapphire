/** 
 * @file enigf.c 
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include "enigme.h"
#include <math.h>
#include <time.h> 
/**  * @brief  To initialize the enigma . 
 * @param e the enigma   
 * @return Nothing  
*/
void init_enigme(enigme * e)
{
	e->p.x=0;
	e->p.y=0;	
	e->img=NULL;


}
/**  * @brief  generer et afficher l enigme e . 
 * @param the screen
 * @param image char
 * @parame the enigas
 * @param alea integer    
 * @return Nothing  
*/
 void generate_afficher (SDL_Surface * screen  , char image [],enigme *e,int *alea)
{ 
	//int test=*alea ;
//do{
 *alea =  rand()%2 +1;
//}while(*alea==test) ;
 sprintf(image ,"%d.jpg",*alea);
e->img = IMG_Load(image);
 SDL_BlitSurface(e->img,NULL,screen,&(e->p)) ;
  SDL_Flip(screen) ;
}
 /**  * @brief solution de l enigme . 
 * @param image char    
 * @return int
 */
 void solution_e1 (char image [],float *x1,float *x2)
 {      float delta ,a,b,c;
 	
 	
 	if(strcmp(image,"1.jpg")==0)
 	{
       a=1;
       b= -5;
       c=6;
       delta= pow(b,2) -4*a*c;
      *x1=  (-b- sqrt(delta))/(2*a) ;
      *x2= (-b+(sqrt(delta)))/(2*a);
     
  }
 	if(strcmp(image,"2.jpg")==0)
 	{
       a=1;
       b= -5;
       c=6;
       delta= pow(b,2) -4*a*c;
      *x1=  (-b- sqrt(delta))/(2*a) ;
      *x2= (-b+(sqrt(delta)))/(2*a);
     
  }	
 	/*else  	if(strcmp(image,"h2.jpg")==0)
 	{
 		solution =1;

 	}
 	else 	if(strcmp(image,"h3.jpg")==0)
 	{
 		solution =3;	
 	}
        else 	if(strcmp(image,"h4.jpg")==0)
 	{
 		solution =1;	
 	}
        else 	if(strcmp(image,"5.jpg")==0)
 	{
 		solution =3;	
 	}
        else 	if(strcmp(image,"6.jpg")==0)
 	{
 		solution =3;	
 	}*/

 }


/**  * @brief  resolution de lenigme . 
 * @param run eint
 * @param running int  
 * @return int
 */
int resolution1 (int * running,int *run )
{
	SDL_Event event ;
 int r=-1;
               SDL_WaitEvent(&event);
							    if( event.type == SDL_QUIT)
                 {
                * running= 0 ;
                *run = 0;
								 }
							    if( event.type == SDL_KEYDOWN )
                 {

            if( ( event.key.keysym.unicode >= ((Uint16)48) ) && ( event.key.keysym.unicode <= ((Uint16)57)	 ) )
            { 
							r=event.key.keysym.unicode-48  ;
							
						} 
								 }	
return r;

                 
	}




 /**  * @brief  affichage de resultat .
 * @param screen surface 
 * @params int
 * @paramr int 
 * @paramen enigme  
 * @return Nothing 
 */
 void afficher_resultat (SDL_Surface * screen,int r2,int r1,enigme *en,float x1,float x2)
 {
  FILE *f ;  
f=fopen("enigme_file","a") ;	 
 	if (((r1==x1)&&(r2==x2))||((r2==x1)&&(r1==x2)))
 	{
 		en->img=IMG_Load("10.png");
 fprintf(f,"/********correct answer*******/  \n x1= %d  x2= %d\n",r1,r2) ;				 
 		SDL_BlitSurface(en->img, NULL, screen, &(en->p)) ;
        SDL_Flip(screen);
 	}
 	else
 	{
fprintf(f,"wrong essai : \n x1= %d  x2= %d\n",r1,r2) ; 
 		en->img=IMG_Load("01.png");
 		SDL_BlitSurface(en->img, NULL, screen, &(en->p)) ;
        SDL_Flip(screen);
 	}
	 fclose(f) ;
 }
 
