#pragma once

#include "game.h"

#include <iostream>
#include "raylib.h"

const int amountButtons = 3;

void mainMenu(ACTUAL_SCREEN& actualScreen, Rectangle buttons[], Color buttonState[]);
void buttonsCreator(Rectangle buttons[]);
void mainMenuDrawing(Rectangle buttons[], Color buttonState[]);
void mainMenuInputs(ACTUAL_SCREEN& actualScreen, Rectangle buttons[], Color buttonState[]);