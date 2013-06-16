#include <SDL.h>

SDL_Surface *screen;

int main(int argc, char **argv)
{
	if(SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		return 1;
	}
	screen = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE);

	if(screen == NULL)
	{ 
		return 1;
	}

	while(true)
	{
		SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 255, 0));
		if(SDL_Flip(screen) == -1)
		{
			return 1;
		}
	}

	SDL_Quit();
	return 0;
}