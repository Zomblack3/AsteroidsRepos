#pragma once

#include "game.h"

#include <iostream>
#include "raylib.h"

//struct Button
//{
//	float width = 50;
//	float height = 25;
//	Rectangle border = { 50, 25 };
//	Vector2 pos;
//	Color state;
//	bool isPressed = false;
//};

const int amountButtons = 3;

void mainMenu(ACTUAL_SCREEN& actualScreen, Rectangle buttons[], Color buttonState[]);
void buttonsCreator(Rectangle buttons[]);
void mainMenuDrawing(Rectangle buttons[], Color buttonState[]);
void mainMenuInputs(ACTUAL_SCREEN& actualScreen, Rectangle buttons[], Color buttonState[]);