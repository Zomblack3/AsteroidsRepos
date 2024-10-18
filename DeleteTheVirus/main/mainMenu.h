#pragma once

#include "game.h"

#include <iostream>
#include "raylib.h"

struct Button
{
	std::string name = "Unnamed";
	float width = 50;
	float height = 25;
	bool isPressed = false;
	Vector2 pos;
};

const int amountButtons = 3;

void mainMenu(ACTUAL_SCREEN& actualScreen);
void buttonsCreator(Button buttons[]);
void mainMenuDrawing(Button buttons[]);
void mainMenuInputs(ACTUAL_SCREEN& actualScreen, Button buttons[]);