#pragma once

#include "gameobject.h"
#include "physics.h"
#include "ball.h";


ref class Wall :
public GameObject
{
private:
	static const int STDSIZE = 16;

    Ball^ ball;

	Physics^ physics;

public:
	Wall(float x, float y, float w, float h, Ball^ b);

	void update();
};
