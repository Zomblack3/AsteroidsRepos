#pragma once

#include "game.h"
#include "gameplay.h"
#include "buttons.h"

#include <iostream>
#include <raylib.h>

void mainMenu(ACTUAL_SCREEN& actualScreen, Buttons buttons[]);
void mainMenuDrawing(Buttons buttons[], std::string buttonsText[], int amountButtons, Texture2D backgroundTexture);
void mainMenuInputs(ACTUAL_SCREEN& actualScreen, Buttons buttons[], int amountButtons);
void loadTextures(Texture2D& background);