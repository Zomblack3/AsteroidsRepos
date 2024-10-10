#include "raylib.h"

#include <math.h>

#include "player.h"

void playerMovement(Player& player)
{
	player.mousePos = GetMousePosition();
	player.bullet.pos = player.pos;
	float angleToMouse = atan2(player.mousePos.y - player.pos.y, player.mousePos.x - player.pos.x);
	player.angle = angleToMouse;
	player.generalSpeed = 50.0f * GetFrameTime();
	player.speedX = (player.angle * cos(player.angle)) * player.generalSpeed;
	player.speedY = (player.angle * sin(player.angle)) * player.generalSpeed;

	if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
	{
		if (player.speedX > 0 && player.speedY > 1)
		{
			//player.pos.x -= (player.angle * cos(player.angle)) * player.speed;
			//player.pos.y -= (player.angle * sin(player.angle)) * player.speed;
			player.pos.x -= player.speedX;
			player.pos.y -= player.speedY;
		}
		else if (player.speedX < 0 && player.speedY < 1)
		{
			player.pos.x += player.speedX;
			player.pos.y += player.speedY;
		}
		else if (player.speedX > 0 && player.speedY < 1)
		{
			player.pos.x -= player.speedX;
			player.pos.y += player.speedY;
		}
		else if (player.speedX < 0 && player.speedY > 1)
		{
			player.pos.x += player.speedX;
			player.pos.y -= player.speedY;
		}
		else
		{
			if (player.speedX == 0 && player.speedY < 0)
				player.pos.y += player.speedY;
			else if (player.speedX == 0 && player.speedY > 0)
				player.pos.y -= player.speedY;
			else if (player.speedX < 0 && player.speedY == 0)
				player.pos.x += player.speedX;
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

	//static Vector2 mousePosSaved[mousePosSavedAmount] = {};
	//static int actualMousePosSaved = 0;
	//static int mousePosSavedTimer = 0;

	/*if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		mousePos = GetMousePosition();*/

	/*if (mousePosSavedTimer == 0)
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