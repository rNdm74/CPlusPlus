#pragma once

#include "GameObject.h"
#include "Physics.h"
#include "Ball.h"


ref class Enemy :
public GameObject
{
private:
	static const int SIZEX = 16;
    static const int SIZEY = SIZEX * 7;
    static const float MAX_SPEEDY = 4;
    static const float DAMPING = 0.05;

	Ball^ ball;

	Physics^ physics;

public:
	Enemy(float x, float y, Ball^ b);

	void update();
};
