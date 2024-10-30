#pragma once

#include <raylib.h>

namespace run
{
	void game();
	//void loadTextures(Texture2D& backgroundMainMenu, Texture2D& backgroundGameplay, Texture2D backgroundCredits, Texture2D& backgroundExtraGameOver, Texture2D& shipTexture, Image& shipGif, Texture2D& enemyLV1, Texture2D& enemyLV2, Texture2D& enemyLV3, Image backgroundMM, Image backgroundC, Image backgroundG);	
	//void loadSounds(Sound& shootSound, Sound& moveSound, Sound& backgroundSound);
}

enum ACTUAL_SCREEN
{
	MAIN_MENU,
	CREDITS,
	GAMEPLAY, 
	GAME_OVER
};

const int windowWidth = 750;
const int windowHeight = 600;