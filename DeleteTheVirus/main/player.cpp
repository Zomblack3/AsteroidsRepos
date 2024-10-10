#include "raylib.h"

#include <math.h>

#include "player.h"

void playerMovement(Player& player)
{
	player.mousePos = GetMousePosition();
	player.bullet.pos = player.pos;
	float angleToMouse = atan2(player.mousePos.y - player.pos.y, player.mousePos.x - player.pos.x);
	player.angle = angleToMouse;
	player.generalSpeed = 150.0f * GetFrameTime();
	player.speedX = (player.angle * cos(player.angle)) * player.generalSpeed;
	player.speedY = (player.angle * sin(player.angle)) * player.generalSpeed;
	float check1 = cos(player.angle);
	float check2 = sin(player.angle);

	if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
	{
		if (cos(player.angle) < 0.1 && sin(player.angle) < 0.1)
		{
			player.pos.x -= player.speedX;
			player.pos.y -= player.speedY;
		}
		else if (cos(player.angle) > 0.1 && sin(player.angle) > 0.1)
		{
			player.pos.x += player.speedX * 2;
			player.pos.y += player.speedY * 2;
		}
		else if (cos(player.angle) < 0.1 && sin(player.angle) > 0.1)
		{
			player.pos.x -= (player.speedX * -1.0);
			player.pos.y += player.speedY;
		}
		else if (cos(player.angle) > 0.1 && sin(player.angle) < 0.1 )
		{
			player.pos.x -= player.speedX * 20;
			player.pos.y += (player.speedY * -1.0) * 20;
		}
		else
		{
			if (cos(player.angle) == 0.1 && sin(player.angle) < 0.1)
				player.pos.y += player.generalSpeed;
			else if (cos(player.angle) == 0.1 && sin(player.angle) > 0.1)
				player.pos.y -= player.generalSpeed;
			else if (cos(player.angle) < 0.1 && sin(player.angle) == 0.1)
				player.pos.x += player.generalSpeed;
			else
				player.pos.x -= player.speedX;
		}
	}
	else
	{
		if (player.speedX > 0)
			player.speedX -= 0.1f;

		if (player.speedY > 0)
			player.speedY -= 0.1f;
	}

	if (player.pos.x < 0)
		player.pos.x = GetScreenWidth();
	else if (player.pos.x > GetScreenWidth()) 
		player.pos.x = 0;
	if (player.pos.y < 0)
		player.pos.y = GetScreenHeight();
	else if (player.pos.y > GetScreenHeight())
		player.pos.y = 0;

}

void playerShooting(Player& player)
{
	if (player.bullet.reloadingTimer == 0.0f)
	{
		if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
			if (player.ammo != 0)
			{
				player.isShooting = true;
				player.bullet.reloadingTimer = 1000.0f;
			}
	}

	if (player.isShooting)
		shoot(player);

	if (player.bullet.reloadingTimer != 0)
		player.bullet.reloadingTimer -= 1;
	else
	{
		player.bullet.pos.x == player.pos.x;
		player.bullet.pos.y == player.pos.y;

		player.isShooting = false;
	}
}

void shoot(Player& player)
{
	if (player.bullet.direction.x < 0 && player.bullet.direction.y < 0)
	{
		/*player.bullet.direction.x *= -1.0;
		player.bullet.direction.y *= -1.0;

		player.bullet.pos.x -= player.bullet.direction.x;
		player.bullet.pos.y -= player.bullet.direction.y;*/

		player.bullet.pos.x += player.bullet.speed;
		player.bullet.pos.y += player.bullet.speed;
	}
	else if (player.bullet.direction.x > 0 && player.bullet.direction.y > 0)
	{
		/*player.bullet.pos.x += player.bullet.direction.x;
		player.bullet.pos.y += player.bullet.direction.y;*/

		player.bullet.pos.x -= player.bullet.speed;
		player.bullet.pos.y -= player.bullet.speed;
	}
	else if (player.bullet.direction.x > 0 && player.bullet.direction.y < 0)
	{
		/*player.bullet.direction.y *= -1.0;

		player.bullet.pos.x += player.bullet.direction.x;
		player.bullet.pos.y -= player.bullet.direction.y;*/

		player.bullet.pos.x -= player.bullet.speed;
		player.bullet.pos.y += player.bullet.speed;
	}
	else if (player.bullet.direction.x < 0 && player.bullet.direction.y > 0)
	{
		/*player.bullet.direction.x *= -1.0;

		player.bullet.pos.x -= player.bullet.direction.x;
		player.bullet.pos.y += player.bullet.direction.y;*/

		player.bullet.pos.x += player.bullet.speed;
		player.bullet.pos.y -= player.bullet.speed;
	}
}