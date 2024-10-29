#include "game.h"

#include "mainMenu.h"
#include "credits.h"
#include "gameplay.h"
#include "buttons.h"

namespace run
{
	const int amountButtonsMainMenu = 3;
	const int amountButtonsPause = 2;
	const int amountButtonsCredits = 4;

	ACTUAL_SCREEN actualScreen = MAIN_MENU;
	Buttons buttonsMainMenu[amountButtonsMainMenu];
	Buttons buttonsPause[amountButtonsPause];

	void game()
	{
		buttonsCreator(buttonsMainMenu, amountButtonsMainMenu);

		buttonsCreator(buttonsPause, amountButtonsPause);

		InitWindow(windowWidth, windowHeight, "DELETE THE VIRUS");

		InitAudioDevice();

		while (!WindowShouldClose())
		{
			switch (actualScreen)
			{
			case MAIN_MENU:

				mainMenu(actualScreen, buttonsMainMenu);

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