#include "StdAfx.h"
#include "Enemy.h"

Enemy::Enemy(float x, float y, Ball^ b)
{
	physics = gcnew Physics();

	xPos = x;
	yPos = y;
    width = SIZEX;
    height = SIZEY;

    ball = b;
}

void Enemy::update()
{
	if (physics->checkCollision(this, ball)) ball->reverseX(getCenterY());

    float speed = (ball->getCenterY() - getCenterY()) * DAMPING;

    if (speed > MAX_SPEEDY) speed = MAX_SPEEDY;
    if (speed < -MAX_SPEEDY) speed = -MAX_SPEEDY;

    yPos += speed;
}