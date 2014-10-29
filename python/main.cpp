#include "main.hpp"

int main(int argc, char *argv[])
{
    const int FPS = 120;
    const int FRAME_TIME = 1000/FPS; //Temps entre chaque frame en ms
    
    long time = 0, lastTime = 0;
    
    SDL_Surface *ecran = NULL, *ballonTex = NULL;
    SDL_Rect posBallon;
    SDL_Event event;

    SDL_Init(SDL_INIT_VIDEO);

    ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Robocup Python POC", NULL);

    ballonTex = IMG_Load("football.png");
    if(ballonTex != NULL){
	    
	    StrategieEngine strategie; //Initialiseur de l'engin de stratégie

	    int exit = 0;
	    while (!exit){

		time = SDL_GetTicks(); //Temps depuis l'execution du programme

		strategie.setData(time); //Envoi de l'état du jeu (ici le temps)

		if(time - lastTime > FRAME_TIME){ //Voir s'il est temps de dessiner le prochain frame
			struct Vector pyPosition = strategie.getPosition(); //Reception de l'état du moteur de stratégie (ici une seule position)

			//Affichage
			setPosition(ballonTex, &posBallon, pyPosition.x * ecran->w/2 + ecran->w/2, pyPosition.y * ecran->h/2 + ecran->h/2);
			
			SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));	
			SDL_BlitSurface(ballonTex, NULL, ecran, &posBallon);

			SDL_Flip(ecran);

			lastTime = time;
		}
		else{
			SDL_Delay(FRAME_TIME - (time - lastTime)); //Attendre jusqu'au prochain frame
		}

		//Gestion d'events (Dans ce cas fermeture de fenêtre)
		SDL_PollEvent(&event); 
		switch(event.type)
		{
		    case SDL_QUIT:
			exit = 1;
			break;
		}

	    }
    }
    else{
	printf("Cannot find \"football.png\". Exiting...\n");
    }
    SDL_FreeSurface(ballonTex);
    SDL_Quit();

    return EXIT_SUCCESS;
}

//Permet de définir la position d'une texture en prenant son centre comme origine locale
static void setPosition(SDL_Surface *tex,SDL_Rect *pos, double x, double y){
	pos->x = x - tex->w/2;
	pos->y = y - tex->h/2;
}
