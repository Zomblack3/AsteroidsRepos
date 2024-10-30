#include "buttons.h"

#include "game.h"

void buttonsCreator(Buttons buttons[], int amountButtons, float startingPosY, float staringPosX, int width, int height)
{
	int buttonDistance = height * 2;
	float posY = static_cast <float> (windowHeight) / 2;

	for (int i = 0; i < amountButtons; i++)
	{
		buttons[i].buttonRec.x = staringPosX;
		buttons[i].buttonRec.y = startingPosY + (buttonDistance * i);
		buttons[i].buttonRec.width = width;
		buttons[i].buttonRec.height = height;
		buttons[i].buttonColor = RED;
	}
}