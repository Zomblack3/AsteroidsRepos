#include "gameplay.h"

void gameplay(ACTUAL_SCREEN& actualScreen)
{
	static Player player;
	Asteroids asteroids[asteroidsAmount];

	/*for (int i = 0; i < asteroidsAmount; i++)
	{
		asteroids[i].radius = rand() % (maxAsteroidRadius - minAsteroidRadius) + (minAsteroidRadius + 1);
	}*/

	gameplayUpdates(player);

	gameplayDrawing(player);
}

void gameplayDrawing(Player player)
{
	BeginDrawing();

	ClearBackground(BLACK);

#ifdef _DEBUG
	DrawFPS(0, 0);

	DrawText(TextFormat("%f", player.generalSpeed), 0, 20, 10, WHITE);

	DrawCircle(player.pos.x, player.pos.y, player.radius, WHITE);
#endif // _DEBUG

	if (player.isShooting)
		DrawCircle(player.bullet.pos.x, player.bullet.pos.y, player.bullet.radius, RED);

	//DrawLineV(player.bullet.pos, player.mousePos, WHITE);

	//DrawText(TextFormat("%f", player.mousePos), 0, 0, 10, WHITE);

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