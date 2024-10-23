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

	DrawText("CREDITS", (windowWidth / 2) - 50, (windowHeight / 2) - 200, 30, GREEN);

	//I
	DrawText("Game created by Santiago Britos", (windowWidth / 2) - 150, (windowHeight / 2) - 150, 20, WHITE);

	//Librarys
	DrawText("Library: Raylib.h", (windowWidth / 2) - 50, (windowHeight / 2) - 100, 20, WHITE);

	//Audio

	//Textures
	DrawText("Textures by Milagros Gubert, Santiago Britos", (windowWidth / 2) - 215, (windowHeight / 2) + 100, 20, WHITE);

	EndDrawing();
}

void inputCredits(ACTUAL_SCREEN& actualScreen)
{
	if (IsKeyPressed(KEY_S))
		actualScreen = MAIN_MENU;
}