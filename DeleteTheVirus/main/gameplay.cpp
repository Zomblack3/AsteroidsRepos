#include "raylib.h"

#include <iostream>

#include "gameplay.h"

void gameplay(ACTUAL_SCREEN& actualScreen)
{
	static Player player;
	Asteroids asteroids[asteroidsAmount];

	/*for (int i = 0; i < asteroidsAmount; i++)
	{
		asteroids[i].radius = rand() % (maxAsteroidRadius - minAsteroidRadius) + (minAsteroidRadius + 1);
	}*/

	gameplayDrawing(player);

	gameplayUpdates(player);
}

void gameplayDrawing(Player player)
{
	BeginDrawing();

	ClearBackground(BLACK);

	DrawRectangle(player.pos.x, player.pos.y, player.width, player.height, WHITE);

	EndDrawing();
}

void gameplayUpdates(Player player)
{
	playerUpdate(player);

	//Vector2 mousePos = GetMousePosition();
	/*static Vector2 mousePos = {};
	static Vector2 mousePosSaved[mousePosSavedAmount] = {};
	static int actualMousePosSaved = 0;
	static int mousePosSavedTimer = 0;

	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		mousePos = GetMousePosition();

	if (mousePosSavedTimer == 0)
	{
		if (actualMousePosSaved != mousePosSavedAmount - 1)
		{
			mousePosSaved[actualMousePosSaved] = mousePos;
			mousePosSavedTimer = 100;
			++actualMousePosSaved;
		}
		else
		{
			actualMousePosSaved = 0;
			mousePosSaved[actualMousePosSaved] = mousePos;
			mousePosSavedTimer = 100;
			++actualMousePosSaved;
		}
	}

	if (mousePosSavedTimer != 0)
		--mousePosSavedTimer;*/

	/*if (player.pos.x != mousePosSaved[actualMousePosSaved].x || player.pos.y != mousePosSaved[actualMousePosSaved].y)
		if (player.pos.x + (player.width / 2.0f) > mousePosSaved[actualMousePosSaved].x && player.pos.y + (player.height / 2.0f) > mousePosSaved[actualMousePosSaved].y)
		{
			if (player.pos.x > 0 && player.pos.y > 0)
			{
				player.pos.x -= player.speed;
				player.pos.y -= player.speed;
			}
		}
		else if (player.pos.x + (player.width / 2.0f) < mousePosSaved[actualMousePosSaved].x && player.pos.y + (player.height / 2.0f) < mousePosSaved[actualMousePosSaved].y)
		{
			if (player.pos.x + player.width < windowWidth && player.pos.y + player.height < windowHeight)
			{
				player.pos.x += player.speed;
				player.pos.y += player.speed;
			}
		}
		else if (player.pos.x + (player.width / 2.0f) < mousePosSaved[actualMousePosSaved].x && player.pos.y + (player.height / 2.0f) > mousePosSaved[actualMousePosSaved].y)
		{
			if (player.pos.x + player.width < windowWidth && player.pos.y > 0)
			{
				player.pos.x += player.speed;
				player.pos.y -= player.speed;
			}
		}
		else if (player.pos.x + (player.width / 2.0f) > mousePosSaved[actualMousePosSaved].x && player.pos.y + (player.height / 2.0f) < mousePosSaved[actualMousePosSaved].y)
		{
			if (player.pos.x > 0 && player.pos.y + player.height < windowHeight)
			{
				player.pos.x -= player.speed;
				player.pos.y += player.speed;
			}
		}
		else if (player.pos.x + (player.width / 2.0f) > mousePosSaved[actualMousePosSaved].x && player.pos.y + (player.height / 2.0f) == mousePosSaved[actualMousePosSaved].y)
		{
			if (player.pos.x > 0)
			{
				player.pos.x -= player.speed;
			}
		}
		else if (player.pos.x + (player.width / 2.0f) < mousePosSaved[actualMousePosSaved].x && player.pos.y + (player.height / 2.0f) == mousePosSaved[actualMousePosSaved].y)
		{
			if (player.pos.x + player.width < windowWidth)
			{
				player.pos.x += player.speed;
			}
		}
		else if (player.pos.x + (player.width / 2.0f) == mousePosSaved[actualMousePosSaved].x && player.pos.y + (player.height / 2.0f) > mousePosSaved[actualMousePosSaved].y)
		{
			if (player.pos.y > 0)
			{
				player.pos.y -= player.speed;
			}
		}
		else if (player.pos.x + (player.width / 2.0f) == mousePosSaved[actualMousePosSaved].x && player.pos.y + (player.height / 2) < mousePosSaved[actualMousePosSaved].y)
		{
			if (player.pos.y + player.height < windowHeight)
			{
				player.pos.y += player.speed;
			}
		}*/

	/*if (mousePos.x != 0 && mousePos.y != 0)
	{
		if (player.pos.x != mousePos.x || player.pos.y != mousePos.y)
			if (player.pos.x + (player.width / 2.0f) > mousePos.x && player.pos.y + (player.height / 2.0f) > mousePos.y)
			{
				if (player.pos.x > 0 && player.pos.y > 0)
				{
					player.pos.x -= player.speed;
					player.pos.y -= player.speed;
				}
			}
			else if (player.pos.x + (player.width / 2.0f) < mousePos.x && player.pos.y + (player.height / 2.0f) < mousePos.y)
			{
				if (player.pos.x + player.width < windowWidth && player.pos.y + player.height < windowHeight)
				{
					player.pos.x += player.speed;
					player.pos.y += player.speed;
				}
			}
			else if (player.pos.x + (player.width / 2.0f) < mousePos.x && player.pos.y + (player.height / 2.0f) > mousePos.y)
			{
				if (player.pos.x + player.width < windowWidth && player.pos.y > 0)
				{
					player.pos.x += player.speed;
					player.pos.y -= player.speed;
				}
			}
			else if (player.pos.x + (player.width / 2.0f) > mousePos.x && player.pos.y + (player.height / 2.0f) < mousePos.y)
			{
				if (player.pos.x > 0 && player.pos.y + player.height < windowHeight)
				{
					player.pos.x -= player.speed;
					player.pos.y += player.speed;
				}
			}
			else if (player.pos.x + (player.width / 2.0f) > mousePos.x && player.pos.y + (player.height / 2.0f) == mousePos.y)
			{
				if (player.pos.x > 0)
				{
					player.pos.x -= player.speed;
				}
			}
			else if (player.pos.x + (player.width / 2.0f) < mousePos.x && player.pos.y + (player.height / 2.0f) == mousePos.y)
			{
				if (player.pos.x + player.width < windowWidth)
				{
					player.pos.x += player.speed;
				}
			}
			else if (player.pos.x + (player.width / 2.0f) == mousePos.x && player.pos.y + (player.height / 2.0f) > mousePos.y)
			{
				if (player.pos.y > 0)
				{
					player.pos.y -= player.speed;
				}
			}
			else if (player.pos.x + (player.width / 2.0f) == mousePos.x && player.pos.y + (player.height / 2.0f) < mousePos.y)
			{
				if (player.pos.y + player.height < windowHeight)
				{
					player.pos.y += player.speed;
				}
			}
	}*/
}

void playerUpdate(Player& player)
{
	static Vector2 mousePos = {};
	static Vector2 mousePosSaved[mousePosSavedAmount] = {};
	static int actualMousePosSaved = 0;
	static int mousePosSavedTimer = 0;

	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		mousePos = GetMousePosition();

	if (mousePosSavedTimer == 0)
	{
		if (actualMousePosSaved != mousePosSavedAmount - 1)
		{
			mousePosSaved[actualMousePosSaved] = mousePos;
			mousePosSavedTimer = 100;
			++actualMousePosSaved;
		}
		else
		{
			actualMousePosSaved = 0;
			mousePosSaved[actualMousePosSaved] = mousePos;
			mousePosSavedTimer = 100;
			++actualMousePosSaved;
		}
	}

	if (mousePosSavedTimer != 0)
		--mousePosSavedTimer;

	if (mousePos.x != 0 && mousePos.y != 0)
	{
		if (player.pos.x != mousePos.x || player.pos.y != mousePos.y)
			if (player.pos.x + (player.width / 2.0f) > mousePos.x && player.pos.y + (player.height / 2.0f) > mousePos.y)
			{
				if (player.pos.x > 0 && player.pos.y > 0)
				{
					player.pos.x -= player.speed;
					player.pos.y -= player.speed;
				}
			}
			else if (player.pos.x + (player.width / 2.0f) < mousePos.x && player.pos.y + (player.height / 2.0f) < mousePos.y)
			{
				if (player.pos.x + player.width < windowWidth && player.pos.y + player.height < windowHeight)
				{
					player.pos.x += player.speed;
					player.pos.y += player.speed;
				}
			}
			else if (player.pos.x + (player.width / 2.0f) < mousePos.x && player.pos.y + (player.height / 2.0f) > mousePos.y)
			{
				if (player.pos.x + player.width < windowWidth && player.pos.y > 0)
				{
					player.pos.x += player.speed;
					player.pos.y -= player.speed;
				}
			}
			else if (player.pos.x + (player.width / 2.0f) > mousePos.x && player.pos.y + (player.height / 2.0f) < mousePos.y)
			{
				if (player.pos.x > 0 && player.pos.y + player.height < windowHeight)
				{
					player.pos.x -= player.speed;
					player.pos.y += player.speed;
				}
			}
			else if (player.pos.x + (player.width / 2.0f) > mousePos.x && player.pos.y + (player.height / 2.0f) == mousePos.y)
			{
				if (player.pos.x > 0)
				{
					player.pos.x -= player.speed;
				}
			}
			else if (player.pos.x + (player.width / 2.0f) < mousePos.x && player.pos.y + (player.height / 2.0f) == mousePos.y)
			{
				if (player.pos.x + player.width < windowWidth)
				{
					player.pos.x += player.speed;
				}
			}
			else if (player.pos.x + (player.width / 2.0f) == mousePos.x && player.pos.y + (player.height / 2.0f) > mousePos.y)
			{
				if (player.pos.y > 0)
				{
					player.pos.y -= player.speed;
				}
			}
			else if (player.pos.x + (player.width / 2.0f) == mousePos.x && player.pos.y + (player.height / 2.0f) < mousePos.y)
			{
				if (player.pos.y + player.height < windowHeight)
				{
					player.pos.y += player.speed;
				}
			}
	}
}