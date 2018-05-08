#pragma once
#include "stdafx.h"
#include "SDL\SDL.h"

class Utils
{
public:
	Utils();
	~Utils();

	static SDL_Surface* LoadSurface(std::string path, SDL_PixelFormat* format);
};

