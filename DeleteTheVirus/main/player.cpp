#include "raylib.h"

#include "player.h"

void playerMovement(Player& player)
{
	static Vector2 mousePos = {};
	//static Vector2 mousePosSaved[mousePosSavedAmount] = {};
	static int actualMousePosSaved = 0;
	static int mousePosSavedTimer = 0;

	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		mousePos = GetMousePosition();

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

void playerShooting(Player& player)
{
	if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
		if (player.ammo != 0)
			player.isShooting = true;

	if (player.isShooting)
		shoot(player);
	else
	{
		player.bullet.pos.x == player.pos.x;
		player.bullet.pos.y == player.pos.y;
	}

}

void shoot(Player& player)
{
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
}