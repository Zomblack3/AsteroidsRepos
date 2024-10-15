#include "player.h"

#include <math.h>

void playerMovement(Player& player)
{
	player.mousePos = GetMousePosition();
	float angleToMouse = atan2(player.mousePos.y - player.pos.y, player.mousePos.x - player.pos.x);
	player.angle = angleToMouse;
	player.speedX = cos(player.angle) * player.generalSpeed;
	player.speedY = sin(player.angle) * player.generalSpeed;

	if (!player.isShooting)
		player.bullet.pos = player.pos;

	if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
	{
		if (cos(player.angle) < 0.1 && sin(player.angle) < 0.1)
		{
			player.pos.x -= (player.speedX * -1.0) * player.generalSpeed;
			player.pos.y -= (player.speedY * -1.0) * player.generalSpeed;
		}
		else if (cos(player.angle) > 0.1 && sin(player.angle) > 0.1)
		{
			player.pos.x += player.speedX * player.generalSpeed;
			player.pos.y += player.speedY * player.generalSpeed;
		}
		else if (cos(player.angle) < 0.1 && sin(player.angle) > 0.1)
		{
			player.pos.x -= (player.speedX * -1.0) * player.generalSpeed;
			player.pos.y += player.speedY * player.generalSpeed;
		}
		else if (cos(player.angle) > 0.1 && sin(player.angle) < 0.1 )
		{
			player.pos.x -= (player.speedX * -1.0) * player.generalSpeed;
			player.pos.y += player.speedY * player.generalSpeed;
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
	bullet.direction = player.mousePos;
	float angleToMouse = atan2(bullet.direction.y - bullet.pos.y, bullet.direction.x - bullet.pos.x);
	bullet.angle = angleToMouse;
	static float speedX = 0;
	static float speedY = 0;

	if (bullet.reloadingTimer <= 0.0f)
	{
		if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
		{
			speedX = cos(bullet.angle);
			speedY = sin(bullet.angle);

			if (speedX < 0.1 && speedY < 0.1)
				bullet.directionSection = III;
			else if (speedX > 0.1 && speedY > 0.1)
				bullet.directionSection = II;
			else if (speedX > 0.1 && speedY < 0.1)
				bullet.directionSection = I;
			else if (speedX < 0.1 && speedY > 0.1)
				bullet.directionSection = IV;

			if (player.ammo != 0)
			{
				player.isShooting = true;
				bullet.reloadingTimer = 100.0f;
			}
		}
	}

	if (player.isShooting)
		shoot(bullet, speedX, speedY);
	else
		bullet.pos = player.pos;

	if (bullet.reloadingTimer > 0)
		bullet.reloadingTimer -= 0.1;
	else
		player.isShooting = false;
}

void shoot(Bullet& bullet, float speedX, float speedY)
{
	switch (bullet.directionSection)
	{
	case CENTER:
		break;
	case I:

		bullet.pos.x += speedX;
		bullet.pos.y += speedY;

		break;
	case II:

		bullet.pos.x -= speedX * -1.0;
		bullet.pos.y += speedY;

		break;
	case III:

		bullet.pos.x -= speedX * -1.0;
		bullet.pos.y -= speedY * -1.0;

		break;
	case IV:

		bullet.pos.x -= speedX * -1.0;
		bullet.pos.y += speedY;

		break;
	default:
		break;
	}
}