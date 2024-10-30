#include "gameOver.h"

void gameOver(ACTUAL_SCREEN& actualScreen, Buttons buttons[], Player& player)
{
	const int amountButtons = 2;

	static bool areTexturesLoaded = false;
	
	static Texture2D background;

	std::string buttonsTexts[amountButtons] = { "RESTART", "QUIT" };

	if (!areTexturesLoaded)
	{
		background = LoadTexture("../res/viruspixelados3.png");

		areTexturesLoaded = true;
	}

	updateGameOver(actualScreen, buttons, amountButtons, player);

	drawGameOver(buttons, background, amountButtons, buttonsTexts, player);
}

void drawGameOver(Buttons buttons[], Texture2D background, int amountButtons, std::string buttonsText[], Player player)
{
	BeginDrawing();

	ClearBackground(BLACK);

	DrawTexture(background, 0, 0, WHITE);

	DrawText(TextFormat("Score: %i", player.score), 200, 400, 25, BLACK);

	for (int i = 0; i < amountButtons; i++)
	{
		DrawRectangle(buttons[i].buttonRec.x, buttons[i].buttonRec.y, buttons[i].buttonRec.width, buttons[i].buttonRec.height, buttons[i].buttonColor);
		DrawText(buttonsText[i].c_str(), buttons[i].buttonRec.x + 5, buttons[i].buttonRec.y + 5, buttons[i].buttonRec.height - 10, WHITE);
	}

	EndDrawing();
}

void updateGameOver(ACTUAL_SCREEN& actualScreen, Buttons buttons[], int amountButtons, Player& player)
{
	for (int i = 0; i < amountButtons; i++)
	{
		if (CheckCollisionPointRec(GetMousePosition(), buttons[i].buttonRec))
			buttons[i].buttonColor = BLUE;
		else
			buttons[i].buttonColor = RED;
	}

	if (CheckCollisionPointRec(GetMousePosition(), buttons[0].buttonRec))
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			restartPlayer(player);

			actualScreen = GAMEPLAY;
		}

	if (CheckCollisionPointRec(GetMousePosition(), buttons[1].buttonRec))
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			restartPlayer(player);

			actualScreen = MAIN_MENU;
		}
}