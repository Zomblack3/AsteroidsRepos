#include "game.h"

#include "raylib.h"
#include <iostream>

#include "mainMenu.h"
#include "gameplay.h"

namespace run
{
	ACTUAL_SCREEN actualScreen = MAIN_MENU;
	Button buttons[amountButtons];

	void game()
	{
		InitWindow(windowWidth, windowHeight, "DELETE THE VIRUS");

		mainMenuDrawing(buttons);

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