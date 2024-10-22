#pragma once

#include "game.h"

#include "raylib.h"

enum DIRECTION_SECTION
{
	CENTER,
	I,
	II,
	III,
	IV
};

struct Bullet
{
	DIRECTION_SECTION directionSection = CENTER;
	Vector2 pos = { };
	Vector2 direction = { };
	float angle = 0;
	float generalSpeed = 300.0f;
	float speedX = 0;
	float speedY = 0;
	float radius = 5;
	float reloadingTimer = 0.0f;
};

struct Player
{
	DIRECTION_SECTION directionSection = CENTER;
	Vector2 mousePos = { };
	Vector2 pos = { windowWidth / 2, windowHeight / 2 };
	Vector2 speed = { }; // Change later
	float angle = 0;
	float radius = 15;
	float minSpeed = 250.0f;
	float maxSpeed = 1000.0f;
	float baseSpeed = 0;
	float generalSpeed = 0;
	float directionX = 0;
	float directionY = 0;
	int lives = 3;
	int ammo = 10;
	bool isShooting = false;
	Bullet bullet;
};

void playerMovement(Player& player);
void playerShooting(Player& player, Bullet& bullet);
void shoot(Bullet& bullet, float speedX, float speedY);