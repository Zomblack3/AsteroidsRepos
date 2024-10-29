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

	DrawText(TextFormat("%i", MeasureText("CREDITS", 30)), 0, 20, 10, WHITE);

	DrawText("CREDITS", MeasureText("CREDITS", 0), (windowHeight / 2) - 200, 30, GREEN);

	//MeasureText("CREDITS", 30)

	//I
	DrawText("Game created by Santiago Britos", MeasureText("Game created by Santiago Britos", 0), (windowHeight / 2) - 150, 20, WHITE);

	//Librarys
	DrawText("Library: Raylib.h", MeasureText("Library: Raylib.h", 20), (windowHeight / 2) - 100, 20, WHITE);

	//Audio

	//Textures
	DrawText("Textures by Milagros Gubert", MeasureText("Textures by Milagros Gubert", 20), (windowHeight / 2) + 100, 20, WHITE);

	EndDrawing();
}

void inputCredits(ACTUAL_SCREEN& actualScreen)
{
	if (IsKeyPressed(KEY_S))
		actualScreen = MAIN_MENU;
}