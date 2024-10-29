#include "credits.h"

#include "raylib.h"

void credits(ACTUAL_SCREEN& actualScreen)
{
	drawCredits();

	inputCredits(actualScreen);
}

void drawCredits()
{
	const int textAmount = 5;

	int principalTextFontSize = 30;
	int secondaryTextFontSize = 20;
	int textPosY[textAmount] = { 200, 150, 100, 50, 0 };

	BeginDrawing();

	ClearBackground(BLACK);

	//Principal text
	DrawText("CREDITS", (windowWidth / 2) - MeasureText("CREDITS", principalTextFontSize / 2), (windowHeight / 2) - textPosY[0], principalTextFontSize, GREEN);

	//I
	DrawText("Game created by Santiago Britos", (windowWidth / 2) - MeasureText("Game created by Santiago Britos", secondaryTextFontSize / 2), (windowHeight / 2) - textPosY[1], secondaryTextFontSize, WHITE);

	//Librarys
	DrawText("Library: Raylib.h", (windowWidth / 2) - MeasureText("Library: Raylib.h", secondaryTextFontSize / 2), (windowHeight / 2) - textPosY[2], secondaryTextFontSize, WHITE);

	//Audio
	DrawText("Audio Tool: Chiptone", (windowWidth / 2) - MeasureText("Audio Tool: Chiptone", secondaryTextFontSize / 2), (windowHeight / 2) - textPosY[3], secondaryTextFontSize, WHITE);

	//Textures
	DrawText("Textures by Milagros Gubert", (windowWidth / 2) - MeasureText("Textures by Milagros Gubert", secondaryTextFontSize / 2), windowHeight / 2, secondaryTextFontSize, WHITE);

	EndDrawing();
}

void inputCredits(ACTUAL_SCREEN& actualScreen)
{
	if (IsKeyPressed(KEY_S))
		actualScreen = MAIN_MENU;
}