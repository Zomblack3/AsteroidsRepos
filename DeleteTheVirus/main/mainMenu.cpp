#include "mainMenu.h"

#include "raylib.h"

void mainMenu(ACTUAL_SCREEN& actualScreen)
{
	mainMenuDrawing();

	mainMenuInputs(actualScreen);
}

void mainMenuDrawing()
{
	BeginDrawing();

	ClearBackground(BLACK);

	DrawText("Presione ENTER para iniciar", (windowWidth / 2) - 160, windowHeight / 2, 25, WHITE);

	EndDrawing();
}

void mainMenuInputs(ACTUAL_SCREEN& actualScreen)
{
	if (IsKeyPressed(KEY_ENTER))
		actualScreen = GAMEPLAY;

	if (IsKeyPressed(KEY_S))
		CloseWindow();
}