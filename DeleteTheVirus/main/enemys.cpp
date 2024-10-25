#include "enemys.h"

Virus createVirus()
{
	Virus virus;
    virus.pos = { static_cast <float> (GetRandomValue(0, GetScreenWidth())), static_cast <float> (GetRandomValue(0, GetScreenHeight())) };
	virus.speed = { static_cast <float> (GetRandomValue(virus.minSpeed, virus.maxSpeed) / 10.0), static_cast <float> (GetRandomValue(virus.minSpeed, virus.maxSpeed) / 10.0) };
    virus.radius = static_cast <float> (GetRandomValue(virus.minSize, virus.maxSize));

	return virus;
}

void virusMovement(Virus& virus)
{
    virus.pos.x += virus.speed.x;
    virus.pos.y += virus.speed.y;

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