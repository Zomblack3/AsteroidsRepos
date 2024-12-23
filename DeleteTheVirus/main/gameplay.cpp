#include "gameplay.h"

#include <vector>

int maxEnemysAmount = 5;

std::vector<Virus> virus;

Image shipGif;
Texture2D shipTexture;
Texture2D background;
Texture2D enemyLVL1;
Texture2D enemyLVL2;
Texture2D enemyLVL3;
Sound shootSound;
Sound moveSound;
Sound backgroundSound;

void gameplay(ACTUAL_SCREEN& actualScreen, Player& player)
{
	const int amountButtons = 1;

	static int startTimer = 200;
	static bool areExtArchivesLoad = false;
	static int actualAmountOfEnemys;

	int animFrames = 0;

	////static Player player;
	//static Image shipGif;
	//static Texture2D shipTexture;
	//static Texture2D background;
	//static Texture2D enemyLVL1;
	//static Texture2D enemyLVL2;
	//static Texture2D enemyLVL3;
	//static Sound shootSound;
	//static Sound moveSound;
	//static Sound backgroundSound;

	if (!areExtArchivesLoad)
	{
		loadTextures(shipTexture, shipGif, background, enemyLVL1, enemyLVL2, enemyLVL3);

		loadAudio(shootSound, moveSound, backgroundSound);

		areExtArchivesLoad = true;
	}

	for (actualAmountOfEnemys; actualAmountOfEnemys < maxEnemysAmount; ++actualAmountOfEnemys)
		virus.push_back(createVirus(enemyLVL1, enemyLVL2, enemyLVL3));

	if (startTimer == 0)
	{
		gameplayUpdates(player, shipTexture, shipGif, shootSound, moveSound, backgroundSound, actualAmountOfEnemys, actualScreen);
	}
	else
		--startTimer;

	gameplayDrawing(player, shipTexture, background);

	if (WindowShouldClose())
	{
		UnloadSound(moveSound);
		UnloadSound(shootSound);
		UnloadSound(backgroundSound);

		UnloadImage(shipGif);

		UnloadTexture(shipTexture);
		
		for (Virus& virus : virus)
			UnloadTexture(virus.texture);
	}
}

void gameplayDrawing(Player player, Texture2D& shipTexture, Texture2D background)
{
	BeginDrawing();

	ClearBackground(BLACK);

	DrawTexture(background, -15, 0, WHITE);

#ifdef _DEBUG
	DrawFPS(0, 0);

	DrawText(TextFormat("%f", player.generalSpeed), 0, 20, 10, WHITE);
	
	DrawText(TextFormat("%f", player.mousePos), 0, 30, 10, WHITE);

	DrawLineV(player.bullet.pos, player.mousePos, WHITE);
	
	DrawCircle(player.pos.x, player.pos.y, player.radius, WHITE);

	for (Virus& virus : virus)
		DrawCircleV(virus.pos, virus.radius, WHITE);

#endif // _DEBUG

	DrawText(TextFormat("Score: %i", player.score), 10, 30, 20, WHITE);

	DrawTexture(shipTexture, player.pos.x - static_cast <float> (shipTexture.width) / 2, player.pos.y - static_cast <float> (shipTexture.height) / 2, WHITE);

	if (player.isShooting)
		DrawCircle(player.bullet.pos.x, player.bullet.pos.y, player.bullet.radius, RED);

	for (Virus& virus : virus)
		DrawTexture(virus.texture, virus.pos.x - (virus.radius * 2), virus.pos.y - (virus.radius * 2), virus.color);

	DrawText(TextFormat("Lives: %0i", player.lives), 10, 0, 20, WHITE);

	DrawRectangle(windowWidth - 30, 5, 20, 20, WHITE);

	EndDrawing();
}

void gameplayUpdates(Player& player, Texture2D shipTexture, Image shipGif, Sound shootSound, Sound moveSound, Sound& backgroundSound, int& actualAmountOfEnemys, ACTUAL_SCREEN& actualScreen)
{
	static int timerPlusEnemy = 50000;
	static int damageTimer = 0;
	static bool isAlive = true;
	static int invencibilityTimer = 0;

	if (!IsSoundPlaying(backgroundSound))
		PlaySound(backgroundSound);

	playerUpdate(player, shootSound, moveSound);

	textureUpdate(shipTexture, shipGif);
	
	for (Virus& virus : virus)
		virusMovement(virus);

	for (Virus& virus : virus)
		if (checkCollisionBulletEnemy(player.bullet, virus))
		{
			if (virus.lives <= 0)
			{
				isAlive = false;
				++player.score;
			}
			else
			{
				--virus.lives;
				virus.color = RED;
			}
		}
		else
			virus.color = WHITE;

	for (int i = 0; i < virus.size(); i++)
		if (checkCollisionBulletEnemy(player.bullet, virus[i]))
		{	
			if (!isAlive)
			{
				virus.erase(virus.begin() + i);
				--actualAmountOfEnemys;
				isAlive = true;
			}
		}
		else if (checkCollisionPlayerEnemy(player, virus[i]))
		{
			if (isAlive && invencibilityTimer <= 0)
			{
				virus.erase(virus.begin() + i);
				--actualAmountOfEnemys;
				--player.lives;
				invencibilityTimer = 1000;
			}
		}

	if (timerPlusEnemy > 0)
		timerPlusEnemy -= 0.1;
	else
	{
		timerPlusEnemy = 50000;
		++maxEnemysAmount;
	}

	if (invencibilityTimer > 0)
		invencibilityTimer -= 0.1;

	if (player.lives <= 0)
	{
		actualScreen = GAME_OVER;
		
		StopSound(backgroundSound);

		StopSound(moveSound);
	}
}

bool checkCollisionBulletEnemy(Bullet bullet, Virus virus) 
{
	float distance = sqrt(pow(bullet.pos.x - virus.pos.x, 2) + pow(bullet.pos.y - virus.pos.y, 2));

	return distance < bullet.radius + virus.radius;
}

bool checkCollisionPlayerEnemy(Player player, Virus virus)
{
	float distance = sqrt(pow(player.pos.x - virus.pos.x, 2) + pow(player.pos.y - virus.pos.y, 2));

	return distance < player.radius + virus.radius;
}

void playerUpdate(Player& player, Sound shootSoud, Sound moveSound)
{
	playerMovement(player, moveSound);

	playerShooting(player, shootSoud, player.bullet);
}

void loadTextures(Texture2D& shipTexture, Image& shipGif, Texture2D& background, Texture2D& enemyLV1, Texture2D& enemyLV2, Texture2D& enemyLV3)
{
	int animFrames = 0;

	Image backgroundIMG = LoadImage("../res/viruspixelados.png");

	shipGif = LoadImageAnim("../res/consept_ship.gif", &animFrames);

	shipTexture = LoadTextureFromImage(shipGif);

	ImageResize(&backgroundIMG, 800, 600);

	background = LoadTextureFromImage(backgroundIMG);

	enemyLV1 = LoadTexture("../res/viruspixelados6.png");

	enemyLV2 = LoadTexture("../res/viruspixelados5.png");

	enemyLV3 = LoadTexture("../res/viruspixelados4.png");
}

void loadAudio(Sound& shootSound, Sound& moveSound, Sound& backgroundSound)
{
	shootSound = LoadSound("../res/shoot_sound.wav");

	moveSound = LoadSound("../res/move_sound.wav");
	
	backgroundSound = LoadSound("../res/background_music.mp3");
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

void unloadAll()
{
	UnloadSound(moveSound);
	UnloadSound(shootSound);
	UnloadSound(backgroundSound);

	UnloadImage(shipGif);

	UnloadTexture(shipTexture);

	for (Virus& virus : virus)
		UnloadTexture(virus.texture);
}