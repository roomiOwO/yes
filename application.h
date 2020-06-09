#pragma once
#include "SDL.h"

class Application
{
public:
	//fixin window size
	static const auto Width = 1280;
	static const auto Height = 720;
	//Application constructor
	Application(SDL_Window* window, SDL_Renderer* renderer);
	
	//execute function to execute game
	int exec();

private:
	SDL_Surface* tmpSurface;
	SDL_Texture* gameBG;
	SDL_Window* window;
	SDL_Renderer* renderer;
};