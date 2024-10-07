#include "raylib.h"
#include <iostream>

#include "game.h"

#include "mainMenu.h"
#include "gameplay.h"

namespace run
{
	ACTUAL_SCREEN actualScreen = MAIN_MENU;

	void game()
	{
		InitWindow(windowWidth, windowHeight, "DELETE THE VIRUS");

		while (!WindowShouldClose())
		{
			switch (actualScreen)
			{
			case MAIN_MENU:

				mainMenu(actualScreen);

				break;
			case GAMEPLAY:

				gameplay(actualScreen);

				break;
			default:
				break;
			}
		}
	}
}