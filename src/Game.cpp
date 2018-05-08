#include "stdafx.h"
#include "Game.h"
#include "Constants.h"



Game::Game()
{
	m_window = NULL;
	m_screenSurface = NULL;
	m_splash = NULL;
}


Game::~Game()
{
}


int Game::Init()
{

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return 100;
	}
	else
	{
		//Create window
		m_window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (m_window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			return 200;
		}
		else
		{
			//Initialize PNG loading
			int imgFlags = IMG_INIT_PNG;
			if (!(IMG_Init(imgFlags) & imgFlags))
			{
				printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
				return 300;
			}
			else
			{
				//Get window surface
				m_screenSurface = SDL_GetWindowSurface(m_window);
			}
		}
	}

	return 0;
}

void Game::Update()
{
	//Main loop flag
	bool quit = false;

	//Event handler
	SDL_Event e;

	while (!quit)
	{
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
			else if (e.type == SDL_KEYDOWN)
			{
				//Select surfaces based on key press
				switch (e.key.keysym.sym)
				{
				case SDLK_UP:
					printf("key_up \n");
					break;

				case SDLK_DOWN:
					printf("key_down \n");
					break;

				case SDLK_LEFT:
					printf("key_left \n");
					break;

				case SDLK_RIGHT:
					printf("key_right \n");
					break;

				default:
					printf("key_default \n");
					break;
				}
			}
		}

		Draw();
	}

}

void Game::Draw()
{
	if (m_window != NULL)
	{
		//Fill the surface white
		SDL_FillRect(m_screenSurface, NULL, SDL_MapRGB(m_screenSurface->format, 0xFF, 0xFF, 0xFF));

		//Update the surface
		SDL_UpdateWindowSurface(m_window);
	}
}

void Game::Close()
{
	SDL_FreeSurface(m_splash);
	m_splash = NULL;

	SDL_FreeSurface(m_screenSurface);
	m_screenSurface = NULL;

	//Destroy window
	SDL_DestroyWindow(m_window);
	m_window = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}