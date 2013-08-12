#include "StdAfx.h"
#include "Ball.h"

Ball::Ball(float x, float y)
{
	xPos = x;
    xPos = y;

    startX = x;
    startY = y;

    width = SIZE;
    height = SIZE;

    velX = -MAX_SPEEDX;
    velY = 0;
}

void Ball::resetPosition(){
    xPos = startX;
    yPos = startY;

    velY = 0;
    velX *= -1;
}

void Ball::reverseX(float center){
    velX *= -1; //reverse direction


    velY += (getCenterY() - center) * DAMPING;

	// capping speeds
    if (velY > MAX_SPEEDY)velY = MAX_SPEEDY;
    if (velY < -MAX_SPEEDY)velY = -MAX_SPEEDY;
}

void Ball::reverseY(){
    velY *= -1;
}

void Ball::update(){
	xPos += velX;
    yPos += velY;	
}
