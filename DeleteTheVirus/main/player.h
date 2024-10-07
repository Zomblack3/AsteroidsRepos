#pragma once

#include "game.h"

struct Player
{
	int width = 50;
	int height = 50;
	Vector2 pos = { windowWidth / 2, windowHeight / 2 };
	float speed = 20 * GetFrameTime();
	int lives = 3;
	int ammo = 10;
	bool isShooting = false;
};

void playerMovement(Player& player);
void playerShooting(Player& player);
void shot();