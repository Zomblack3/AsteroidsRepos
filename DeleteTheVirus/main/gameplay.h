#pragma once

#include "game.h"
#include "player.h"
#include "enemys.h"

#include <iostream>

void gameplay(ACTUAL_SCREEN& actualScreen);
void gameplayDrawing(Player player, Texture2D& shipTexture, Texture2D screenBorder);
void gameplayUpdates(Player& player, Texture2D shipTexture, Image shipGif, Sound shootSound, Sound moveSound, Sound& backgroundSound, int& actualAmountOfEnemys, ACTUAL_SCREEN& actualScreen);
void playerUpdate(Player& player, Sound shootSound, Sound moveSound);
bool checkCollisionBulletEnemy(Bullet bullet, Virus virus);
bool checkCollisionPlayerEnemy(Player player, Virus virus);
void loadTextures(Texture2D& shipTexture, Image& shipGif, Texture2D& screenBorder, Texture2D& enemyLV1, Texture2D& enemyLV2, Texture2D& enemyLV3);
void loadAudio(Sound& shootSound, Sound& moveSound, Sound& backgroundSound);
void textureUpdate(Texture2D shipTexture, Image shipGif);

const int maxAsteroidRadius = 20;
const int minAsteroidRadius = 5;
const int asteroidsAmount = 10;
const int mousePosSavedAmount = 5;