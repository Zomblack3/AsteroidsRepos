#include "player.h"

#include <math.h>

void playerMovement(Player& player, Sound moveSound)
{
	player.generalSpeed = player.baseSpeed;
	float delta = GetFrameTime();
	player.mousePos = GetMousePosition();
	float angleToMouse = atan2(player.mousePos.y - player.pos.y, player.mousePos.x - player.pos.x);
	player.angle = angleToMouse;
	player.directionX = cos(player.angle);
	player.directionY = sin(player.angle);
	static float constDirectionX = 0;
	static float constDirectionY = 0;

	if (!player.isShooting)
		player.bullet.pos = player.pos;

	if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
	{
		if (!IsSoundPlaying(moveSound))
			PlaySound(moveSound);

		if (player.baseSpeed == 0)
			player.baseSpeed = player.minSpeed;

		if (cos(player.angle) < 0.1 && sin(player.angle) < 0.1)
		{
			constDirectionX = player.directionX;
			constDirectionY = player.directionY;

			player.directionSection = III;
		}
		else if (cos(player.angle) > 0.1 && sin(player.angle) > 0.1)
		{
			constDirectionX = player.directionX;
			constDirectionY = player.directionY;

			player.directionSection = I;
		}
		else if (cos(player.angle) < 0.1 && sin(player.angle) > 0.1)
		{
			constDirectionX = player.directionX;
			constDirectionY = player.directionY;

			player.directionSection = II;
		}
		else if (cos(player.angle) > 0.1 && sin(player.angle) < 0.1 )
		{
			constDirectionX = player.directionX;
			constDirectionY = player.directionY;

			player.directionSection = IV;
		}

		if (player.baseSpeed < player.maxSpeed)
			player.baseSpeed += 0.01;
	}
	else
	{
		if (player.baseSpeed > player.minSpeed)
			player.baseSpeed -= 0.01f;

		StopSound(moveSound);
	}

	switch (player.directionSection)
	{
	case CENTER:
		break;
	case I:

		player.pos.x += constDirectionX * (player.generalSpeed * delta);
		player.pos.y += constDirectionY * (player.generalSpeed * delta);

		break;
	case II:

		player.pos.x -= (constDirectionX * -1.0) * (player.generalSpeed * delta);
		player.pos.y += constDirectionY * (player.generalSpeed * delta);

		break;
	case III:

		player.pos.x -= (constDirectionX * -1.0) * (player.generalSpeed * delta);
		player.pos.y -= (constDirectionY * -1.0) * (player.generalSpeed * delta);

		break;
	case IV:

		player.pos.x -= (constDirectionX * -1.0) * (player.generalSpeed * delta);
		player.pos.y += constDirectionY * (player.generalSpeed * delta);

		break;
	default:
		break;
	}

	if (player.pos.x < 0)
		player.pos.x = windowWidth;
	else if (player.pos.x > windowWidth) 
		player.pos.x = 0;

	if (player.pos.y < 0)
		player.pos.y = windowHeight;
	else if (player.pos.y > windowHeight)
		player.pos.y = 0;

}

void playerShooting(Player& player, Sound shootSound, Bullet& bullet)
{
	bullet.direction = player.mousePos;
	float angleToMouse = atan2(bullet.direction.y - bullet.pos.y, bullet.direction.x - bullet.pos.x);
	bullet.angle = angleToMouse;
	static float speedX = 0;
	static float speedY = 0;
	static bool soundPlayed = false;

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
	{
		shoot(bullet, speedX, speedY);

		if (!soundPlayed)
		{
			PlaySound(shootSound);

			soundPlayed = true;
		}
	}
	else
		bullet.pos = player.pos;

	if (bullet.reloadingTimer > 0)
		bullet.reloadingTimer -= 0.1;
	else
	{
		player.isShooting = false;

		soundPlayed = false;
	}
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

void restartPlayer(Player& player)
{
	player.directionSection = CENTER;
	player.mousePos = { };
	player.pos = { windowWidth / 2, windowHeight / 2 };
	player.angle = 0;
	player.directionX = 0;
	player.directionY = 0;
	player.lives = 3;
	player.ammo = 1;
	player.isShooting = false;
	player.bullet;
	player.score = 0;
}