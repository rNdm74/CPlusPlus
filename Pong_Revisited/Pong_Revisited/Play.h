#pragma once

#include "GameObject.h"
#include "Physics.h"
#include "Ball.h"

ref class Play :
public GameObject
{
private:
	static const float SIZEX = 16;
	static const float SIZEY = SIZEX * 7;    
    static const float SPEED = 4;

	Ball^ ball;
	Physics^ physics;

	float mag;

	float velX;
    float velY;

    float startX;
    float startY;

	

public:
	void setMag(float m){mag = m;}

	Play(float x, float y, Ball^ ball);
	
	void update();
	void move();
};
