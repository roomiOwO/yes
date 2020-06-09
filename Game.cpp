#include<iostream>
#include "Game.h"

using namespace std;

//Game constructor - Initializes variables and different classes
Game::Game(SDL_Renderer* renderer):
	renderer(renderer),
	barTexture(loadTexture(renderer, "images/bars.bmp")),
	heli(renderer), 
    bg(renderer)
{
}

bool Game::tick(bool isMouseDown)
{
	if (counter++ % 2100 == 0) // Bar/Pillar Spawner
	{
		auto y = rand() % (Application::Height - 350) + 100;  // Random Bar Placement

		static int flipper = 0;

		if(flipper % 2 == 0)
		barList.emplace_back(renderer, barTexture, y, false);  // Render bar normal

		else
		barList.emplace_back(renderer, barTexture, y, true);  // Render bar flipped

		flipper++;  //Flip bar next loop

	}

	heli.tick(isMouseDown);  //if mouse button is pressed, heli gains height
	
	//Collision Detection

	SDL_Rect heliRect;  // declaring rectangles for detecting intersection between textures
	heliRect.x = heli.x - 120 / 2;
	heliRect.y = heli.y - 35 / 2;
	heliRect.w = 120;
	heliRect.h = 35;

	SDL_Rect res;

	for (auto& bar : barList)
	{
		bar.tick();

		if (bar.isUp)
		{
			SDL_Rect barRect;
			barRect.x = bar.x - 128;
			barRect.y = bar.y - 10000;
			barRect.w = 220;
			barRect.h = 10000;
			
			//Checking if the rectangles of the heli and bars intersect
			if (SDL_IntersectRect(&heliRect, &barRect, &res))
				return false;
			
		}

		else
		{
			SDL_Rect barRect;
			barRect.x = bar.x - 128;
			barRect.y = bar.y;
			barRect.w = 220;
			barRect.h = 10000;

			//Checking if the rectangles of the heli and bars intersect
			if (SDL_IntersectRect(&heliRect, &barRect, &res))
				return false;

		}

	}

	return heli.y < Application::Height; // if heli goes below screen, end program
	
}


int Game::exec()
{
	// Getting milliseconds and updating program per millisecond
	auto oldTick = SDL_GetTicks();
	bool isMouseDown = false;

	//Event processing and input control
	for (auto done = false; !done;)
	{
		//Event Processing
		SDL_Event e;
		if (SDL_PollEvent(&e))
		{
			switch (e.type)
			{
				//Mouse button input checking 
			case SDL_MOUSEBUTTONDOWN:
				
				isMouseDown = true;
				break;
			case SDL_MOUSEBUTTONUP:
				isMouseDown = false;
				break;

			case SDL_QUIT:
				done = true;
				break;
			}
		}

		//Physics of the Heli
		auto currentTick = SDL_GetTicks();
		for (auto i = oldTick; i < currentTick; ++i)
		{
			
			if (!tick(isMouseDown)) // if this is false, the program ends
			{
				SDL_Delay(300); // mini delay before returning to main
				return 1;
			}
		
		}
			
		oldTick = currentTick;

		//Drawing Part
		SDL_SetRenderDrawColor(renderer, 0x00, 0xff, 0xff, 0xff);
		SDL_RenderClear(renderer);


		bg.draw(); // Drawing background
		heli.draw(); // Drawing helicopter
		 
		for (auto& bar : barList)
		bar.draw(); // Drawing Bars/poles

		SDL_RenderPresent(renderer); // To present the renderer even though unneeded
	}
	return 0;
}