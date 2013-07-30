#include "StdAfx.h"
#include "Wall.h"

Wall::Wall(float x, float y, float w, float h, Ball^ b)
{
	physics = gcnew Physics();

    xPos = x;
    yPos = y;
    width = w;
    height = h;

    ball = b;
}

void Wall::update()
{
	if(physics->checkCollision(this, ball)) ball->reverseY();
}
