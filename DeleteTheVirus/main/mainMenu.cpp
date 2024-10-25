#include "mainMenu.h"

void mainMenu(ACTUAL_SCREEN& actualScreen, Rectangle buttons[], Color buttonState[])
{
	static bool areButtonsCreated = false;

	if (!areButtonsCreated)
		buttonsCreator(buttons);

	mainMenuInputs(actualScreen, buttons, buttonState);

	if (!WindowShouldClose())
		mainMenuDrawing(buttons, buttonState);
}

void buttonsCreator(Rectangle buttons[])
{
	int buttonDistance = 40;
	float posY = windowHeight / 2;

	for (int i = 0; i < amountButtons; i++)
	{
		buttons[i].x = (windowWidth / 2) - 20;
		buttons[i].y = posY + (buttonDistance * i);
		buttons[i].width = 75;
		buttons[i].height = 25;
	}
}

void mainMenuDrawing(Rectangle buttons[], Color buttonState[])
{
	std::string buttonsText[amountButtons] = { "START", "CREDITS", "EXIT" };

	BeginDrawing();

	ClearBackground(BLACK);

	DrawText("DELETE THE VIRUS", (windowWidth / 2) - 250, (windowHeight / 2) - (windowHeight / 4), 50, WHITE);

	for (int i = 0; i < amountButtons; i++)
	{
		DrawRectangle(buttons[i].x, buttons[i].y, buttons[i].width, buttons[i].height, buttonState[i]);
		DrawText(buttonsText[i].c_str(), buttons[i].x + 5, buttons[i].y + 5, buttons[i].height - 10, WHITE);
	}

	EndDrawing();
}

void mainMenuInputs(ACTUAL_SCREEN& actualScreen, Rectangle buttons[], Color buttonState[])
{
	for (int i = 0; i < amountButtons; i++)
	{
		if (CheckCollisionPointRec(GetMousePosition(), buttons[i]))
			buttonState[i] = BLUE;
		else
			buttonState[i] = RED;
	}

	if (CheckCollisionPointRec(GetMousePosition(), buttons[0]))
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			actualScreen = GAMEPLAY;

	if (CheckCollisionPointRec(GetMousePosition(), buttons[1]))
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			actualScreen = CREDITS;

	if (CheckCollisionPointRec(GetMousePosition(), buttons[2]))
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			CloseWindow();

	/*if (IsKeyPressed(KEY_S))
		CloseWindow();*/
}