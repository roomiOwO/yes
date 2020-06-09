#pragma once
#include <iostream>
#include "SDL.h"
#include "application.h"
#include "load_texture.h"

//Heli class that draws and controls heli physics and position
class Heli
{
public:
	Heli(SDL_Renderer* renderer);
	~Heli();

	void draw();
	void tick(bool isMouseDown);
	float y = Application::Height / 2 - 50;
	const float x = Application::Width / 4 - 50;

private:
	SDL_Renderer* renderer;
	SDL_Texture* heli1;
	SDL_Texture* heli2;
	
	float v = 0.0f;
};