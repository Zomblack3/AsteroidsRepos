#include "mainMenu.h"

void mainMenu(ACTUAL_SCREEN& actualScreen)
{
	Button buttons[amountButtons];
	static bool areButtonsCreated = false;

	if (!areButtonsCreated)
		buttonsCreator(buttons);

	mainMenuDrawing(buttons);

	mainMenuInputs(actualScreen, buttons);
}

void buttonsCreator(Button buttons[])
{
	std::string buttonsNames[amountButtons] = { "start", "credits", "exit" };

	int buttonDistance = 40;

	for (int i = 0; i < amountButtons; i++)
	{
		Vector2 buttonsPos = { (windowWidth / 2) - buttons[i].width, windowHeight / 2 };
		buttons[i].name = buttonsNames[i];
		buttons[i].pos = buttonsPos;
		buttons[i].pos.y += buttonDistance * i;
	}
}

void mainMenuDrawing(Button buttons[])
{
	BeginDrawing();

	ClearBackground(BLACK);

	//DrawText("Presione ENTER para iniciar", (windowWidth / 2) - 160, windowHeight / 2, 25, WHITE);

	for (int i = 0; i < amountButtons; i++)
	{
		DrawRectangle(buttons[i].pos.x, buttons[i].pos.y, buttons[i].width, buttons[i].height, RED);
	}

	EndDrawing();
}

void mainMenuInputs(ACTUAL_SCREEN& actualScreen, Button buttons[])
{
	if (IsKeyPressed(KEY_ENTER))
		actualScreen = GAMEPLAY;

	if (IsKeyPressed(KEY_S))
		CloseWindow();
}