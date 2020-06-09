#pragma once
#include "SDL.h"
#include "application.h"
#include "load_texture.h"
#include <iostream>

//Bar class to summon bars
class Bar
{
public:
	//constructor and functions
	Bar(SDL_Renderer* renderer, SDL_Texture* texture, int y, bool isUp);

	void tick();
	void draw();

private:
	SDL_Renderer* renderer;
	SDL_Texture* texture;

public:
	//dimensions
	float x = Application::Width + 128 ;
	float y;
	bool isUp;
};