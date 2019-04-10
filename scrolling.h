#ifndef FONCTIONS_H_
#define FONCTIONS_H_


#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#define PLAYER_WIDTH 100
#define PLAYER_HEIGHT 200
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#define Backg_W 8000
#define Backg_H 720

#define NON 0
#define OUI 1


/*_________   structure numero 1  ____________ */



typedef struct Acteurs Acteurs;
struct Acteurs
{
	  SDL_Surface *screen;
    SDL_Event event ;

	//fond
	SDL_Surface *fond ;
	SDL_Rect posFond;

  //fond noir
  SDL_Surface* backg_collision;
  SDL_Surface* backg;
  SDL_Rect camera;

};


/*_________   structure de l hero (personage)  ____________ */

typedef struct Hero Hero ;
struct Hero 
{

SDL_Surface *sprite;

/* Coordonnées du héros */
Sint16 x , y ;
Sint16 Ysaut;

/* Variables utiles pour l'animation */
int frame_timer, frame_number,timee;
int etat  , direction ; 

float x1 , x2 , x3 , x4 , x5 , x6 , x7 , x8 , x9 , x10 , x11 , x12 , x13 , x14 , x15 , x16 ;  //points de verification de collision parfaite 
float y1 , y2 , y3 , y4 , y5 , y6 , y7 , y8 , y9 , y10 , y11 , y12 , y13 , y14 , y15 , y16 ;  // points de verification de collision parfaite 

int jump, ground,a,b,c,win;
int PLAYER_SPEED ;
float vies ; 

SDL_Surface *life_bar ;
int x_life_bar , y_life_bar , w_life_bar , h_life_bar ;

};


void centerScrollingOnPlayer(Hero *hero, Acteurs* acteurs) ;
