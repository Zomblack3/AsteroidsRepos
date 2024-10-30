#pragma once

#include <raylib.h>

struct Buttons
{
	Rectangle buttonRec;
	Color buttonColor;
};

void buttonsCreator(Buttons buttons[], int amountButtons, float startingPosY, float staringPosX, int width, int height);