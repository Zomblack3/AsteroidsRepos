#include "raylib.h"

#include <math.h>

#include "player.h"

void playerMovement(Player& player)
{
	player.mousePos = GetMousePosition();
	float angleToMouse = atan2(player.mousePos.y - player.pos.y, player.mousePos.x - player.pos.x);
	player.angle = angleToMouse;
	//player.generalSpeed = 150.0f * GetFrameTime();
	player.speedX = (player.angle * cos(player.angle)) * player.generalSpeed;
	player.speedY = (player.angle * sin(player.angle)) * player.generalSpeed;

	if (!player.isShooting)
		player.bullet.pos = player.pos;

	if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
	{
		if (cos(player.angle) < 0.1 && sin(player.angle) < 0.1)
		{
			player.pos.x -= player.speedX;
			player.pos.y -= player.speedY;
		}
		else if (cos(player.angle) > 0.1 && sin(player.angle) > 0.1)
		{
			player.pos.x += player.speedX * 4;
			player.pos.y += player.speedY * 4;
		}
		else if (cos(player.angle) < 0.1 && sin(player.angle) > 0.1)
		{
			player.pos.x -= (player.speedX * -1.0);
			player.pos.y += player.speedY;
		}
		else if (cos(player.angle) > 0.1 && sin(player.angle) < 0.1 )
		{
			player.pos.x -= player.speedX * 4;
			player.pos.y += (player.speedY * -1.0) * 4;
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

void playerShooting(Player& player, Bullet& bullet)
{
	/*player.bullet.speedX = (player.angle * cos(player.angle)) * player.bullet.generalSpeed;
	player.bullet.speedY = (player.angle * sin(player.angle)) * player.bullet.generalSpeed;*/

	if (bullet.reloadingTimer <= 0.0f)
	{
		if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
		{
			bullet.direction = player.angle;
			bullet.speedX = player.speedX;
			bullet.speedY = player.speedY;

			if (player.ammo != 0)
			{
				player.isShooting = true;
				bullet.reloadingTimer = 1000.0f;
			}
		}
	}

	if (player.isShooting)
		shoot(bullet);
	else
		bullet.pos = player.pos;

	if (bullet.reloadingTimer > 0)
		bullet.reloadingTimer -= 0.1;
	else
		player.isShooting = false;
}

void shoot(Bullet& bullet)
{
	float angleToMouse = atan2(bullet.direction - bullet.pos.y, bullet.direction - bullet.pos.x);
	bullet.angle = angleToMouse;
	//player.bullet.speedX = (player.angle * cos(player.angle)) * player.bullet.generalSpeed;
	//player.bullet.speedY = (player.angle * sin(player.angle)) * player.bullet.generalSpeed;

	if (cos(bullet.angle) < 0.1 && sin(bullet.angle) < 0.1)
	{
		/*player.bullet.direction.x *= -1.0;
		player.bullet.direction.y *= -1.0;

		player.bullet.pos.x -= player.bullet.direction.x;
		player.bullet.pos.y -= player.bullet.direction.y;*/

		bullet.pos.x -= bullet.speedX;
		bullet.pos.y -= bullet.speedY;
	}
	else if (cos(bullet.angle) > 0.1 && sin(bullet.angle) > 0.1)
	{
		/*player.bullet.pos.x += player.bullet.direction.x;
		player.bullet.pos.y += player.bullet.direction.y;*/

		bullet.pos.x += bullet.speedX;
		bullet.pos.y += bullet.speedY;
	}
	else if (cos(bullet.angle) > 0.1 && sin(bullet.angle) < 0.1)
	{
		/*player.bullet.direction.y *= -1.0;

		player.bullet.pos.x += player.bullet.direction.x;
		player.bullet.pos.y -= player.bullet.direction.y;*/

		bullet.pos.x -= (bullet.speedX * -1.0);
		bullet.pos.y += bullet.speedY;
	}
	else if (cos(bullet.angle) < 0.1 && sin(bullet.angle) > 0.1)
	{
		/*player.bullet.direction.x *= -1.0;

		player.bullet.pos.x -= player.bullet.direction.x;
		player.bullet.pos.y += player.bullet.direction.y;*/

		bullet.pos.x -= bullet.speedX;
		bullet.pos.y += (bullet.speedY * -1.0);
	}
}