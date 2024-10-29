#include "enemys.h"

Virus createVirus(Texture2D type1, Texture2D type2, Texture2D type3)
{
    float speedRegulator = 10.0f;
    int textureNum = GetRandomValue(1, 3);

	Virus virus;
    virus.pos = { static_cast <float> (GetRandomValue(0, GetScreenWidth())), static_cast <float> (GetRandomValue(0, GetScreenHeight())) };
	virus.speed = { static_cast <float> (GetRandomValue(virus.minSpeed, virus.maxSpeed) / speedRegulator), static_cast <float> (GetRandomValue(virus.minSpeed, virus.maxSpeed) / speedRegulator) };
    virus.radius = static_cast <float> (10);

    switch (textureNum)
    {
    case 1:
        
        virus.texture = type1;

        break;
    case 2:

        virus.texture = type2;

        break;
    case 3:

        virus.texture = type3;

        break;
    default:
        break;
    }

	return virus;
}

void virusMovement(Virus& virus)
{
    virus.pos.x += virus.speed.x * (virus.generalSpeed * GetFrameTime());
    virus.pos.y += virus.speed.y * (virus.generalSpeed * GetFrameTime());

    // Colisiones con bordes
    if (virus.pos.x < 0) 
        virus.pos.x = GetScreenWidth();
    else if (virus.pos.x > GetScreenWidth())
        virus.pos.x = 0;
    if (virus.pos.y < 0)
        virus.pos.y = GetScreenHeight();
    else if (virus.pos.y > GetScreenHeight()) 
        virus.pos.y = 0;
}