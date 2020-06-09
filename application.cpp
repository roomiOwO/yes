#include "application.h"
#include "Game.h"
#include <iostream>

using namespace std;

Application::Application(SDL_Window* window, SDL_Renderer* renderer):
	window(window),
	renderer(renderer)
{
	/*auto res = 
	if (res != 0)
	{
		cout << "SDL Init Failed " << endl;
	} 

	SDL_CreateWindowAndRenderer(Width, Height, SDL_WINDOW_BORDERLESS, &window, &renderer);
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
	SDL_SetWindowPosition(window, 65, 126);
	*/
	// moved to int main
}

//game runner
int Application::exec()
{
	Game g(renderer);
	return g.exec();
}