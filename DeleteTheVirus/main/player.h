#pragma once

#include "game.h"

struct Bullet
{
	int width = 10;
	int height = 10;
	Vector2 pos = { };
	Vector2 direction = GetMousePosition();
	float speed = 500 * GetFrameTime();
};

struct Player
{
	int width = 50;
	int height = 50;
	Vector2 pos = { windowWidth / 2, windowHeight / 2 };
	float speed = 20 * GetFrameTime();
	int lives = 3;
	int ammo = 10;
	bool isShooting = false;
	Bullet bullet;
};

void playerMovement(Player& player);
void playerShooting(Player& player);
void shoot(Player& player);