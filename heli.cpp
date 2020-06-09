#include "heli.h"
#include <iostream>

using namespace std;

//constructor to load images to textures to render them on screen
Heli::Heli(SDL_Renderer* renderer):
	renderer(renderer),
	heli1(loadTexture(renderer, "images/heli_first.bmp")),
	heli2(loadTexture(renderer, "images/heli_second.bmp"))
{
}

//To Clean up / Release / delete resources
Heli::~Heli()
{
	SDL_DestroyTexture(heli1);
	SDL_DestroyTexture(heli2);
}

//To draw the helicopter
void Heli::draw()
{
	SDL_Rect r;
	r.x = x - 64; 
	r.y = y - 64; 
	r.w = 128;
	r.h = 128;

	//To render the heli using 2 images. I wish i made the images more diff tho
	auto res = SDL_RenderCopyEx(renderer, SDL_GetTicks() % 300 > 100 ? heli1 : heli2, nullptr, &r, -v * 22, nullptr, SDL_FLIP_NONE);
	
	if (res != 0)
		cout << "Unable to run Heli Draw function" << endl;
}

//Heli physics, natural gravity and mousedown to increase altitude
void Heli::tick(bool isMouseDown)
{
	v -= isMouseDown ? 0.003 : 0;
	v += 0.001;
	y += v;
}

