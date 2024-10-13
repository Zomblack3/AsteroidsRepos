#pragma once

#include "game.h"

struct Bullet
{
	int width = 10;
	int height = 10;
	Vector2 pos = { };
	float direction = 0 /*GetMousePosition()*/;
	float angle = 0;
	float generalSpeed = 300.0f * GetFrameTime();
	float speedX = 0;
	float speedY = 0;
	float radius = 5;
	float reloadingTimer = 0.0f;
};

struct Player
{
	Vector2 mousePos = GetMousePosition();
	Vector2 pos = { windowWidth / 2, windowHeight / 2 };
	float angle = 0;
	float radius = 15;
	float generalSpeed = 15.0f * GetFrameTime();
	float speedX = 0;
	float speedY = 0;
	int lives = 3;
	int ammo = 10;
	bool isShooting = false;
	Bullet bullet;
};

void playerMovement(Player& player);
void playerShooting(Player& player, Bullet& bullet);
void shoot(Bullet& bullet);