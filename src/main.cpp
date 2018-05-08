// Learn.cpp : Defines the entry point for the application.
//
#include "main.h"
#include "Game.h"


#undef main


int main(int argc, char* args[])
{
	Game game;
	if (game.Init() == 0)
	{
		game.Update();
	}
	game.Close();
	return 0;
}