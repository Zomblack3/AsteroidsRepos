#pragma once

#include "game.h"
#include "player.h"

#include <iostream>

struct Asteroids
{
	float posX = rand() % (windowWidth - 50);
	float posY = rand() % windowHeight;
	int radius = 0;
	float speed = 250 * GetFrameTime();
};

void gameplay(ACTUAL_SCREEN& actualScreen);
void gameplayDrawing(Player player, Texture2D& shipTexture, Texture2D screenBorder);
void gameplayUpdates(Player& player, Texture2D shipTexture, Image shipGif, Sound shootSound);
void playerUpdate(Player& player, Sound shootSound);
void loadTextures(Texture2D& shipTexture, Image& shipGif, Texture2D& screenBorder);
void textureUpdate(Texture2D shipTexture, Image shipGif);
void loadAudio(Sound& shootSound);

const int maxAsteroidRadius = 20;
const int minAsteroidRadius = 5;
const int asteroidsAmount = 10;
const int mousePosSavedAmount = 5;