#include "credits.h"

void credits(ACTUAL_SCREEN& actualScreen, Buttons buttons[])
{
	const int amountButtons = 4;

	std::string buttonsText[amountButtons] = { "Game created by Santiago Britos", "Library: Raylib.h", "Audio Tool: Chiptone", "Textures by Milagros Gubert" };

	drawCredits(amountButtons, buttonsText, buttons);

	updateCredits(actualScreen, amountButtons, buttons);
}

void drawCredits(int amountButtons, std::string buttonsText[], Buttons buttons[])
{
	const int textAmount = 4;

	int principalTextFontSize = 30;
	int secondaryTextFontSize = 20;
	int textPosY[textAmount] = { 150, 100, 50, 0 };

	BeginDrawing();

	ClearBackground(BLACK);

	for (int i = 0; i < amountButtons; i++)
	{
		DrawRectangle(buttons[i].buttonRec.x, buttons[i].buttonRec.y, buttons[i].buttonRec.width, buttons[i].buttonRec.height, buttons[i].buttonColor);
		DrawText(buttonsText[i].c_str(), (windowWidth / 2) - MeasureText(buttonsText[i].c_str(), secondaryTextFontSize / 2), (windowHeight / 2) - textPosY[i], secondaryTextFontSize, WHITE);
	}

	DrawText("CREDITS", (windowWidth / 2) - MeasureText("CREDITS", principalTextFontSize / 2), (windowHeight / 2) - /*textPosY[0]*/200, principalTextFontSize, GREEN);

	EndDrawing();
}

void updateCredits(ACTUAL_SCREEN& actualScreen, int amountButtons, Buttons buttons[])
{
	if (IsKeyPressed(KEY_S))
		actualScreen = MAIN_MENU;

	for (int i = 0; i < amountButtons; i++)
	{
		if (CheckCollisionPointRec(GetMousePosition(), buttons[i].buttonRec))
			buttons[i].buttonColor = BLUE;
		else
			buttons[i].buttonColor = RED;
	}
}