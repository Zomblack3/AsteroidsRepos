#pragma once

#include "game.h"

#include "buttons.h"

#include <iostream>
#include <raylib.h>

void credits(ACTUAL_SCREEN& actualScreen, Buttons buttons[]);
void drawCredits(int amountButtons, std::string buttonsText[], Buttons buttons[]);
void updateCredits(ACTUAL_SCREEN& actualScreen, int amountButtons, Buttons buttons[]);