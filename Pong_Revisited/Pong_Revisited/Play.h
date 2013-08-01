#pragma once

#include "GameObject.h"
#include "Physics.h"
#include "Ball.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

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
	
	void input(KeyEventArgs^  e, int mod);	
	virtual void update() override;
	void move();
};
