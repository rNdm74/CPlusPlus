#include "StdAfx.h"
#include "Alien.h"

Alien::Alien(RectangleF startRect, PointF startVel, Graphics^ startGraphics)
	   : GameObject(startRect, startVel, startGraphics)
{
	font = gcnew Font("Microsoft Sans Serif", 12);
	direction = 1;
	movement = 1;
}

void Alien::update()
{
	if(time > 100)
	{
		//if moves complete move down
		if(movement >= 4) 
		{
			//finish move
			rect.X += 20 * direction;

			//move down
			rect.Y += 20;
			
			//change direction
			direction = -direction;
			
			//reset movement
			movement = 0;
		}

		//move alien
		rect.X += 20 * direction;

		//increment move
		movement++;
		
		//reset time
		time = 0;
	}

	time++;
}

void Alien::render()
{
	canvas->FillRectangle(brush, rect);
	canvas->DrawString(time.ToString(), font, Brushes::AliceBlue, 50, 50);
}