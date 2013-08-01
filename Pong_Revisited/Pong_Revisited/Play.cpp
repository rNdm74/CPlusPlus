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

void Play::input(KeyEventArgs^  e, int mod)
{
	if(e->KeyCode == Keys::Up || e->KeyCode == Keys::W)
	{
		setMag(-mod);
	}
	
	if(e->KeyCode == Keys::Down || e->KeyCode == Keys::S)
	{
		setMag(mod);
	}	
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

