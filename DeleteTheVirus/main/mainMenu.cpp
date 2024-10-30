#include "mainMenu.h"

void mainMenu(ACTUAL_SCREEN& actualScreen, Buttons buttons[])
{
	const int amountButtons = 3;

	static bool isTextureLoaded = false;
	static Texture2D backgroundTexture;

	std::string buttonsText[amountButtons] = { "START", "CREDITS", "EXIT" };

	if (!isTextureLoaded)
	{
		loadTextures(backgroundTexture);

		isTextureLoaded = true;
	}

	if (!WindowShouldClose())
		mainMenuDrawing(buttons, buttonsText, amountButtons, backgroundTexture);

	mainMenuInputs(actualScreen, buttons, amountButtons);
}

void mainMenuDrawing(Buttons buttons[], std::string buttonsText[], int amountButtons, Texture2D backgroundTexture)
{
	BeginDrawing();

	ClearBackground(BLACK);

	DrawTexture(backgroundTexture, 0, 0, WHITE);

	DrawText("DELETE THE VIRUS", MeasureText("DELETE THE VIRUS", 0), (windowHeight / 4), 25, WHITE);

	for (int i = 0; i < amountButtons; i++)
	{
		DrawRectangle(buttons[i].buttonRec.x, buttons[i].buttonRec.y, buttons[i].buttonRec.width, buttons[i].buttonRec.height, buttons[i].buttonColor);
		DrawText(buttonsText[i].c_str(), buttons[i].buttonRec.x + 5, buttons[i].buttonRec.y + 5, buttons[i].buttonRec.height - 10, WHITE);
	}

	EndDrawing();
}

void mainMenuInputs(ACTUAL_SCREEN& actualScreen, Buttons buttons[], int amountButtons)
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
			actualScreen = GAMEPLAY;

	if (CheckCollisionPointRec(GetMousePosition(), buttons[1].buttonRec))
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			actualScreen = CREDITS;

	if (CheckCollisionPointRec(GetMousePosition(), buttons[2].buttonRec))
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			CloseWindow();
			unloadAll();
		}
}

void loadTextures(Texture2D& background)
{
	Image backgroundImg = LoadImage("../res/viruspixelados2.png");

	ImageResize(&backgroundImg, 750, 600);

	background = LoadTextureFromImage(backgroundImg);
}