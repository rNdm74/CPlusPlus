#include "StdAfx.h"
#include "Play.h"

Play::Play(float x, float y, Ball^ b)
{
	physics = gcnew Physics();

	xPos = x;
	yPos = y;
    width = SIZEX;
    height = SIZEY;

    ball = b;
}

void Play::update()
{
	if (physics->checkCollision(this, ball)) ball->reverseX(getCenterY()); 		
	move();
}

void Play::move()
{
	yPos += SPEED * mag;
}

