#pragma once

#include "game.h"

struct Player
{
	int width = 50;
	int height = 50;
	Vector2 pos = { windowWidth / 2, windowHeight / 2 };
	float speed = 50 * GetFrameTime();
	int lives = 3;
	int ammo = 10;
};

struct Asteroids
{
	float posX = rand() % (windowWidth - 50);
	float posY = rand() % windowHeight;
	int radius = 0;
	float speed = 250 * GetFrameTime();
};

void gameplay(ACTUAL_SCREEN& actualScreen);
void gameplayDrawing(Player player);
void gameplayUpdates(Player player);
void playerUpdate(Player& player);

const int maxAsteroidRadius = 20;
const int minAsteroidRadius = 5;
const int asteroidsAmount = 10;
const int mousePosSavedAmount = 5;