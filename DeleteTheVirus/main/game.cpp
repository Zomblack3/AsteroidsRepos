#include "game.h"

#include "mainMenu.h"
#include "credits.h"
#include "gameplay.h"
#include "gameOver.h"
#include "buttons.h"

namespace run
{
#include <raylib.h>

	const int amountButtonsMainMenu = 3;
	const int amountButtonsCredits = 4;
	const int amountButtonsGameplay = 1;
	const int amountButtonsPause = 2;
	const int amountButtonsGameOver = 2;

	int animFrames = 0;

	void game()
	{
		ACTUAL_SCREEN actualScreen = MAIN_MENU;
		Buttons buttonsMainMenu[amountButtonsMainMenu];
		Buttons buttonsCredits[amountButtonsCredits];
		Buttons buttonsGameplay[amountButtonsGameplay];
		Buttons buttonsPause[amountButtonsPause];
		Buttons buttonsGameOver[amountButtonsGameOver];

		Player player;

		buttonsCreator(buttonsMainMenu, amountButtonsMainMenu, (static_cast <float> (windowHeight) / 2) - 50, (windowWidth / 2) - 20, 100, 25);

		buttonsCreator(buttonsCredits, amountButtonsCredits, (static_cast <float> (windowHeight) / 2) - 155, (windowWidth / 2) - 175, 350, 25);

		buttonsCreator(buttonsGameOver, amountButtonsGameOver, (static_cast <float> (windowHeight) / 2) - 50, (windowWidth / 2) - 20, 100, 25);

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

				credits(actualScreen, buttonsCredits);

				break;
			case GAMEPLAY:

				gameplay(actualScreen, player);

				break;
			case GAME_OVER:

				gameOver(actualScreen, buttonsGameOver, player);

				break;
			default:
				break;
			}
		}

		CloseAudioDevice();
	}
}