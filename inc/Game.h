#pragma once
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

class Game
{
public:
	Game();
	~Game();

	int Init();
	void Update();
	void Draw();
	void Close();

private:
	//The window we'll be rendering to
	SDL_Window* m_window;

	//The surface contained by the window
	SDL_Surface* m_screenSurface;

	SDL_Surface* m_splash;


};

