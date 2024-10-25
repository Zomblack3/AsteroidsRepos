#include "gameplay.h"

void gameplay(ACTUAL_SCREEN& actualScreen)
{
	static int startTimer = 200;
	int animFrames = 0;
	static bool areExtArchivesLoad = false;

	static Player player;
	Asteroids asteroids[asteroidsAmount];
	static Image shipGif;
	static Texture2D shipTexture;
	static Texture2D screenBoarder;
	static Sound shootSound;

	/*for (int i = 0; i < asteroidsAmount; i++)
	{
		asteroids[i].radius = rand() % (maxAsteroidRadius - minAsteroidRadius) + (minAsteroidRadius + 1);
	}*/

	if (!areExtArchivesLoad)
	{
		loadTextures(shipTexture, shipGif, screenBoarder);

		loadAudio(shootSound);

		areExtArchivesLoad = true;
	}

	if (startTimer == 0)
		gameplayUpdates(player, shipTexture, shipGif, shootSound);
	else
		--startTimer;

	gameplayDrawing(player, shipTexture, screenBoarder);

	if (WindowShouldClose())
	{
		UnloadTexture(shipTexture);
		UnloadImage(shipGif);
	}
}

void gameplayDrawing(Player player, Texture2D& shipTexture, Texture2D screenBorder)
{
	BeginDrawing();

	ClearBackground(BLACK);

	DrawTexture(screenBorder, 0, 0, WHITE);

#ifdef _DEBUG
	DrawFPS(0, 0);

	DrawText(TextFormat("%f", player.generalSpeed), 0, 20, 10, WHITE);
	
	DrawText(TextFormat("%f", player.mousePos), 0, 30, 10, WHITE);

	//DrawLineV(player.bullet.pos, player.mousePos, WHITE);
	
	DrawCircle(player.pos.x, player.pos.y, player.radius, WHITE);
#endif // _DEBUG

	DrawTexture(shipTexture, player.pos.x - shipTexture.width / 2, player.pos.y - shipTexture.height / 2, WHITE);

	if (player.isShooting)
		DrawCircle(player.bullet.pos.x, player.bullet.pos.y, player.bullet.radius, RED);

	//DrawTexture(screenBorder, 0, 0, WHITE);

	EndDrawing();
}

void gameplayUpdates(Player& player, Texture2D shipTexture, Image shipGif, Sound shootSound)
{
	playerUpdate(player, shootSound);

	textureUpdate(shipTexture, shipGif);
}

void playerUpdate(Player& player, Sound shootSoud)
{
	playerMovement(player);

	playerShooting(player, shootSoud, player.bullet);
}

void loadTextures(Texture2D& shipTexture, Image& shipGif, Texture2D& screenBorder)
{
	int animFrames = 0;

	shipGif = LoadImageAnim("../res/consept_ship.gif", &animFrames);
	shipTexture = LoadTextureFromImage(shipGif);

	screenBorder = LoadTexture("../res/gameplay_screen_border.png");

	//screenBorder = LoadTexture("../res/png-clipart-aesthetics-white-crt-computer-monitor-thumbnail.png");
}

void loadAudio(Sound& shootSound)
{
	shootSound = LoadSound("../res/shoot_sound.wav");
}

void textureUpdate(Texture2D shipTexture, Image shipGif)
{
	int animFrames = 3;
	unsigned int nextFrameDataOffset = 0;
	static int currentAnimFrame = 0;       // Current animation frame to load and draw
	int frameDelay = 1;             // Frame delay to switch between animation frames
	static int frameCounter = 0;

	++frameCounter;

	if (frameCounter >= frameDelay)
	{
		// Move to next frame
		// NOTE: If final frame is reached we return to first frame
		currentAnimFrame++;

		if (currentAnimFrame >= animFrames) 
			currentAnimFrame = 0;

		// Get memory offset position for next frame data in image.data
		nextFrameDataOffset = shipGif.width * shipGif.height * 4 * currentAnimFrame;

		// Update GPU texture data with next frame image data
		// WARNING: Data size (frame size) and pixel format must match already created texture
		UpdateTexture(shipTexture, ((unsigned char*)shipGif.data) + nextFrameDataOffset);

		frameCounter = 0;
	}
}

//void loadPlayerTexture(Texture2D& shipTexture, int& currentAnimFrame, int& frameDelay, int& frameCounter)
//{
//	unsigned int nextFrameDataOffset = 0;
//
//	++currentAnimFrame;
//}