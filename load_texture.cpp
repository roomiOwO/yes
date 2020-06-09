#include "load_texture.h"
#include <iostream>

using namespace std;

//Loadtexture class function to loadtextures for any other class or entity
SDL_Texture* loadTexture(SDL_Renderer* renderer, const char* fileName)
{
	auto surface = SDL_LoadBMP(fileName);

	if (!surface)
	{
		cout << "Unable to load surface";
	}

	auto res = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
	return res;
}
