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
	
	SDL_Event sdlevent;
	bool running = true;
	while(running)
	{
		while(SDL_PollEvent(&sdlevent))
		{
			switch(sdlevent.type)
			{
			case SDL_QUIT:
				{
					running = false;
				}
				break;
			}
		}
		SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 255));
		SDL_Flip(screen);
		SDL_Delay(20);
	}

	SDL_Quit();
	return 0;
}