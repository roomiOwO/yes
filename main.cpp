#include "SDL.h"
#include "SDL_mixer.h"
#include "SDL_image.h"
#include <iostream>
#include "application.h"

using namespace std;


SDL_Texture* bgTexture, *rndm;

int simplemenu()
{
	SDL_Surface* bgSurface;

	//MENU BACKGROUND
	
	//Waiting for Mousepress
	for (auto done = false; !done;)
	{	
		//Event Processing
		SDL_Event e;
		if (SDL_PollEvent(&e))
		{
			switch (e.type)
			{
			case SDL_MOUSEBUTTONDOWN:
				return 1;

			case SDL_QUIT:
				done = true;
				break;
			}
		}
	}
}

int main(int argc, char* argv[])
{
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
	SDL_Surface * bgSurface;

	SDL_Init(SDL_INIT_EVERYTHING); // Initializing everything

	//Creating Window and Renderer
	SDL_CreateWindowAndRenderer(1280, 720, 0, &window, &renderer);
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
	SDL_SetWindowPosition(window, 65, 126);
	
	//Loading Music
	Mix_Music* music;
	Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);
	music = Mix_LoadMUS("audio/menu_music.wav");
	Mix_PlayMusic(music, -1);
	

	//Setting Icon and Title
	bgSurface = IMG_Load("images/icon.png");
	SDL_SetWindowIcon(window, bgSurface);
	SDL_SetWindowTitle(window, "H City");

	//Creating Application class object - this runs the whole game when exec function is called
	Application app(window, renderer);

	//Loading menu image
	bgSurface = IMG_Load("images/menu.png");
	if (bgSurface == NULL)
	{
		printf("Unable to load image! SDL_image Error %s\n", IMG_GetError());
	}
	bgTexture = SDL_CreateTextureFromSurface(renderer, bgSurface);
	SDL_RenderCopy(renderer, bgTexture, NULL, NULL);
	SDL_RenderPresent(renderer);

	simplemenu();
	Mix_FadeOutMusic(650);

	music = Mix_LoadMUS("audio/game_music.wav");
	Mix_PlayMusic(music, -1);

	app.exec();

	//FAIL BACKGROUND
	bgSurface = IMG_Load("images/fail.png");
	if (bgSurface == NULL)
	{
		printf("Unable to load image! SDL_image Error %s\n", IMG_GetError());
	}
	bgTexture = SDL_CreateTextureFromSurface(renderer, bgSurface);
	SDL_RenderCopy(renderer, bgTexture, NULL, NULL);
	SDL_RenderPresent(renderer);

	Mix_FadeOutMusic(50);

	music = Mix_LoadMUS("audio/fail_music.wav");
	Mix_PlayMusic(music, -1);

	Mix_FadeOutMusic(5000);
	SDL_Delay(5000);

	return 0;
}

