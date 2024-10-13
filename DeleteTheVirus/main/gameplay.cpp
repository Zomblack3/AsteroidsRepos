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

	DrawCircle(player.pos.x, player.pos.y, player.radius, WHITE);

	if (player.isShooting)
		DrawCircle(player.bullet.pos.x, player.bullet.pos.y, player.bullet.radius, RED);

	//DrawLineV(player.bullet.pos, player.mousePos, WHITE);

	EndDrawing();
}

void gameplayUpdates(Player& player)
{
	playerUpdate(player);


}

void playerUpdate(Player& player)
{
	playerMovement(player);

	playerShooting(player, player.bullet);
}