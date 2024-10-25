#include "game.h"

#include "mainMenu.h"
#include "credits.h"
#include "gameplay.h"

namespace run
{
	ACTUAL_SCREEN actualScreen = MAIN_MENU;
	Rectangle buttons[amountButtons];
	Color buttonState[amountButtons];

	void game()
	{
		InitWindow(windowWidth, windowHeight, "DELETE THE VIRUS");

		InitAudioDevice();

		mainMenuDrawing(buttons, buttonState);

		while (!WindowShouldClose())
		{
			switch (actualScreen)
			{
			case MAIN_MENU:

				mainMenu(actualScreen, buttons, buttonState);

				break;
			case CREDITS:

				credits(actualScreen);

				break;
			case GAMEPLAY:

				gameplay(actualScreen);

				break;
			default:
				break;
			}
		}

		CloseAudioDevice();
	}
}