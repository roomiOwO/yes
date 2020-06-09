#pragma once
#include <iostream>
#include "SDL.h"
#include "application.h"
#include "load_texture.h"


//Quite simple background draw function
class BGDraw
{
public:
	BGDraw(SDL_Renderer* renderer);
	~BGDraw();

	void draw();

private:
	SDL_Renderer* renderer;
	SDL_Texture* bgTex;
};