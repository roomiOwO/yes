#include "bar.h"
using namespace std;

//Bar constructor for setting values
Bar::Bar(SDL_Renderer* renderer, SDL_Texture* texture, int y, bool isUp) :
	renderer(renderer),
	texture(texture),
	y(y),
	isUp(isUp)
{

}

//each tick, reduction of X, resulting in bar moving left
void Bar::tick()
{
	x -= 0.25f;
}

//draw function to draw bar from an image
void Bar::draw()
{
	//Normal Bars
	if (!isUp)
	{
		SDL_Rect r;
		r.x = x - 128;
		r.y = y;
		r.w = 220;
		r.h = 720;

		auto res = SDL_RenderCopyEx(renderer, texture, nullptr, &r, 0, nullptr, SDL_FLIP_NONE);

		if (res != 0)
		cout << "Unable to run Bar Draw function" << endl;
	}

	//Upside-down bars
	else
	{
		SDL_Rect r;
		r.x = x - 128;
		r.y = y - Application::Height;
		r.w = 220;
		r.h = 720;

		auto res = SDL_RenderCopyEx(renderer, texture, nullptr, &r, 0, nullptr, SDL_FLIP_VERTICAL);

		if (res != 0)
			cout << "Unable to run Bar Draw function" << endl;
	}
}