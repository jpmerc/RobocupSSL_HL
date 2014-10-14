#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "script.h"

int main(int argc, char *argv[])
{
    SDL_Surface *ecran = NULL, *ballonTex = NULL;
    SDL_Rect posBallon;

    SDL_Init(SDL_INIT_VIDEO);

    ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Chargement d'images en SDL", NULL);

    ballonTex = IMG_Load("football.png");
    
    posBallon.x = ecran->w/2 - ballonTex->w/2;
    posBallon.y = ecran->h/2 - ballonTex->h/2;

    scriptEngine_init();

    int t = 0;
    int exit = 0;
    while (t < 10000){

	struct Vector pyPosition = getPosition(t);
	setPosition(ballonTex, &posBallon, pyPosition.x * 100 + ecran->w/2, pyPosition.y * 100 + ecran->h/2);
	
	SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));	
	SDL_BlitSurface(ballonTex, NULL, ecran, &posBallon);

    	SDL_Flip(ecran);
    
	t++;
	exit = 0;
    }
    scriptEngine_finalize();
    SDL_FreeSurface(ballonTex);
    SDL_Quit();

    return EXIT_SUCCESS;
}

void setPosition(SDL_Surface *tex,SDL_Rect *pos, double x, double y){
	pos->x = x - tex->w/2;
	pos->y = y - tex->h/2;
}
