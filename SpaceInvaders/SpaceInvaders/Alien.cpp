#include "StdAfx.h"
#include "Alien.h"

Alien::Alien(RectangleF startRect, PointF startVel, Graphics^ startGraphics, int newTag, Random^ startRGen, GameObjectList^ gameBullets)
	   : GameObject(startRect, startVel, startGraphics)
{
	bullets = gameBullets;

	tag = newTag;
	rGen = startRGen;

	font = gcnew Font("Microsoft Sans Serif", 12);
	tagColor = gcnew SolidBrush(Color::Black);

	moveTime = 100;
	direction = 1;
	movement = 1;
}

void Alien::update()
{
	//bullets->update();

	if(time > 1000)
	{
		//if moves complete move down
		if(movement >= 29) 
		{
			//finish move
			rect.X += SPEED * direction;

			//move down
			rect.Y += SPEED;
			
			//change direction
			direction = -direction;
			
			//reset movement
			movement = 0;

			//moveTime
			//moveTime -=10;
			//shoot();
		}

		//move alien
		rect.X += SPEED * direction;

		//increment move
		movement++;
		
		//reset time
		time = 0;
	}

	time++;
}

void Alien::render()
{
	if(visible)
	{
		//bullets->render();
		canvas->FillRectangle(brush, rect);
		canvas->DrawString(tag.ToString(), font, tagColor, rect.X, rect.Y);
		canvas->DrawString(time.ToString(), font, Brushes::AliceBlue, 10, 10);
	}	
}

void Alien::shoot()
{
	bullets->add(gcnew Bullet(RectangleF(rect.X + 4, rect.Y + 4, 2, 2), PointF(0.1,0.1), canvas, 1));
}