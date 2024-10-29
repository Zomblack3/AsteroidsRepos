#pragma once

#include "game.h"

#include <raylib.h>

struct Virus
{
    float maxSpeed = 10.0;
    float minSpeed = -10.0;
    int maxSize = 10;
    int minSize = 5;
    Vector2 pos = { };
    Vector2 speed = { };
    float generalSpeed = 200.0;
    float radius = 0;
    Texture2D texture;
};

Virus createVirus();
void virusMovement(Virus& virus);
