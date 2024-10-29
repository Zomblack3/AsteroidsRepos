#pragma once

#include "game.h"
#include "player.h"
#include "enemys.h"

#include <iostream>

void gameplay(ACTUAL_SCREEN& actualScreen);
void gameplayDrawing(Player player, Texture2D& shipTexture, Texture2D screenBorder, Texture2D& enemyLV1);
void gameplayUpdates(Player& player, Texture2D shipTexture, Image shipGif, Sound shootSound, Sound moveSound, Sound& backgroundSound, int& actualAmountOfEnemys);
void playerUpdate(Player& player, Sound shootSound, Sound moveSound);
void loadTextures(Texture2D& shipTexture, Image& shipGif, Texture2D& screenBorder, Texture2D& enemyLV1);
void textureUpdate(Texture2D shipTexture, Image shipGif);
void loadAudio(Sound& shootSound, Sound& moveSound, Sound& backgroundSound);
bool checkCollision(Player player, Virus virus);

const int maxAsteroidRadius = 20;
const int minAsteroidRadius = 5;
const int asteroidsAmount = 10;
const int mousePosSavedAmount = 5;