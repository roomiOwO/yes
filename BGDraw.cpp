#include "BGDraw.h"

//constructor to initialize values
BGDraw::BGDraw(SDL_Renderer* renderer) :
	renderer(renderer),
	bgTex(loadTexture(renderer, "images/bg.bmp"))
{

}

BGDraw::~BGDraw()
{
	SDL_DestroyTexture(bgTex);
}

//draw function to draw barckground from an image
void BGDraw::draw()
{
	SDL_Rect r;
	r.x = 0;
	r.y = 0;
	r.w = 1280;
	r.h = 720;

	auto res = SDL_RenderCopyEx(renderer, bgTex, nullptr, &r, 0, nullptr, SDL_FLIP_NONE);

}