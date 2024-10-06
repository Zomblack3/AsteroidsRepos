#include "raylib.h"

#include <iostream>

#include "gameplay.h"

void gameplay(ACTUAL_SCREEN& actualScreen)
{
	static Player player;
	Asteroids asteroids[asteroidsAmount];

	for (int i = 0; i < asteroidsAmount; i++)
	{
		asteroids[i].radius = rand() % (maxAsteroidRadius - minAsteroidRadius) + (minAsteroidRadius + 1);
	}

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

void gameplayUpdates(Player& player)
{
	Vector2 mousePos = GetMousePosition();
	Vector2 mousePosSaved[mousePosSavedAmount] = {};
	static int actualMousePosSaved = 0;
	static int mousePosSavedTimer = 0;

	if (mousePosSavedTimer == 0)
	{
		if (actualMousePosSaved != mousePosSavedAmount - 1)
		{
			mousePosSaved[actualMousePosSaved] = mousePos;
			mousePosSavedTimer = 50;
			++actualMousePosSaved;
		}
		else
		{
			actualMousePosSaved = 0;
			mousePosSaved[actualMousePosSaved] = mousePos;
			mousePosSavedTimer = 50;
			++actualMousePosSaved;
		}
	}

	if (mousePosSavedTimer != 0)
		--mousePosSavedTimer;

	if (player.pos.x != mousePosSaved[actualMousePosSaved].x)
		if (player.pos.x > mousePosSaved[actualMousePosSaved].x)
			player.pos.x -= player.speed;
		else
			player.pos.x += player.speed;

	if (player.pos.y != mousePosSaved[actualMousePosSaved].y)
		if (player.pos.y > mousePosSaved[actualMousePosSaved].y)
			player.pos.y -= player.speed;
		else
			player.pos.y += player.speed;

	/*if (IsKeyDown(KEY_LEFT))
		player.pos.x -= player.speed;

	if (IsKeyDown(KEY_RIGHT))
		player.pos.x += player.speed;

	if (IsKeyDown(KEY_UP))
		player.pos.y -= player.speed;

	if (IsKeyDown(KEY_DOWN))
		player.pos.y += player.speed;*/
}