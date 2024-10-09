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

void gameplayUpdates(Player& player)
{
	playerUpdate(player);

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
}

void playerUpdate(Player& player)
{
	if (!player.isShooting)
		player.bullet.pos = player.pos;
	else
		if (player.bullet.direction.x < 0 && player.bullet.direction.y < 0)
		{
			player.bullet.direction.x *= -1.0;
			player.bullet.direction.y *= -1.0;

			player.bullet.pos.x -= player.bullet.direction.x;
			player.bullet.pos.y -= player.bullet.direction.y;
		}
		else if (player.bullet.direction.x > 0 && player.bullet.direction.y > 0)
		{
			player.bullet.pos.x += player.bullet.direction.x;
			player.bullet.pos.y += player.bullet.direction.y;
		}
		else if (player.bullet.direction.x > 0 && player.bullet.direction.y < 0)
		{
			player.bullet.direction.y *= -1.0;

			player.bullet.pos.x += player.bullet.direction.x;
			player.bullet.pos.y -= player.bullet.direction.y;
		}
		else if (player.bullet.direction.x < 0 && player.bullet.direction.y > 0)
		{
			player.bullet.direction.x *= -1.0;

			player.bullet.pos.x -= player.bullet.direction.x;
			player.bullet.pos.y += player.bullet.direction.y;
		}

	playerMovement(player);
}