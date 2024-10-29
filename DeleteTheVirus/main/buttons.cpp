#include "buttons.h"

#include "game.h"

void buttonsCreator(Buttons buttons[], int amountButtons)
{
	int buttonDistance = 40;
	float posY = static_cast <float> (windowHeight) / 2;

	for (int i = 0; i < amountButtons; i++)
	{
		buttons[i].buttonRec.x = (windowWidth / 2) - 20;
		buttons[i].buttonRec.y = posY + (buttonDistance * i);
		buttons[i].buttonRec.width = 75;
		buttons[i].buttonRec.height = 25;
		buttons[i].buttonColor = RED;
	}
}