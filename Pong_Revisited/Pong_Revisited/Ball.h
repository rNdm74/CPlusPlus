#pragma once
#include "GameObject.h"

ref class Ball :
public GameObject
{
private:
	static const int SIZE = 16;
	static const float MAX_SPEEDX = 4;
    static const float MAX_SPEEDY = 8;
    static const float DAMPING = 0.05;

	float velX;
    float velY;

    float startX;
    float startY;

public:
	Ball(float x, float y);
	
	void resetPosition();
	void reverseX(float center);
	void reverseY();

	virtual void update() override;
};
