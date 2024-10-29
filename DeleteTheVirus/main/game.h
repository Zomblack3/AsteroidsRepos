#pragma once

#include <raylib.h>

namespace run
{
	void game();
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