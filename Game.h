#pragma once
#include "SDL.h"
#include "application.h"
#include "load_texture.h"
#include "heli.h"
#include "bar.h"
#include <vector>
#include "SDL_image.h"
#include "BGDraw.h"

using namespace std;

class Game
{
public:
	Game(SDL_Renderer *renderer);
	int exec();

private:
	//Declaring different class objects for management and manipulation
	//Also SDL variables for creating stuff
	SDL_Renderer* renderer;
	SDL_Texture* barTexture;
	SDL_Texture* gameBG;
	BGDraw bg;
	Heli heli;
	vector<Bar> barList;
	bool tick(bool isMouseDown);
	int counter = 0;
};
