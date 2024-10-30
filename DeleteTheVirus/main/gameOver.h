#pragma once

#include "game.h"
#include "buttons.h"
#include "player.h"

#include <iostream>

void gameOver(ACTUAL_SCREEN& actualScreen, Buttons buttons[], Player& player);
void drawGameOver(Buttons buttons[], Texture2D background, int amountButtons, std::string buttonsText[], Player player);
void updateGameOver(ACTUAL_SCREEN& actualScreen, Buttons buttons[], int amountButtons, Player& player);