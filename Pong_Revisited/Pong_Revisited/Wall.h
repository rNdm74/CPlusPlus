#pragma once

#include "GameObject.h"
#include "Physics.h"
#include "Ball.h";


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
