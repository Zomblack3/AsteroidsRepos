#pragma once

#include "game.h"

#include "buttons.h"

#include <iostream>
#include <raylib.h>

void mainMenu(ACTUAL_SCREEN& actualScreen, Buttons buttons[]);
void mainMenuDrawing(Buttons buttons[], std::string buttonsText[], int amountButtons);
void mainMenuInputs(ACTUAL_SCREEN& actualScreen, Buttons buttons[], int amountButtons);