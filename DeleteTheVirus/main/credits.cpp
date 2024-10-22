#include "credits.h"

#include "raylib.h"

void credits(ACTUAL_SCREEN& actualScreen)
{
	drawCredits();

	inputCredits(actualScreen);
}

void drawCredits()
{
	BeginDrawing();

	ClearBackground(BLACK);

	DrawText("Game created by Santiago Britos", (windowWidth / 2) - 150, (windowHeight / 2) - 100, 20, WHITE);

	DrawText("Library: Raylib.h", (windowWidth / 2) - 50, (windowHeight / 2) - 50, 20, WHITE);

	//Audio

	//Textures

	EndDrawing();
}

void inputCredits(ACTUAL_SCREEN& actualScreen)
{
	if (IsKeyPressed(KEY_S))
		actualScreen = MAIN_MENU;
}