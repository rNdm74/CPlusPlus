#include "StdAfx.h"
#include "GameObject.h"

GameObject::GameObject(Point startLocation, Size startSize, Rectangle screenBounds, Graphics^ canvas, Color color)
	{
		direction = 0;
		
		yVel = SPEED;
		xVel = SPEED;

		location = startLocation;
		size = startSize;
		screen = screenBounds;
		graphics = canvas;
		brush = gcnew SolidBrush(color);
		pen = gcnew Pen(color);
	}

void GameObject::update()
	{
		// Update Code
		if(count > 200)
		{
			location.Y += yVel;
			count = 0;
		}

		//location.X += xVel * direction;
					
		count++;
	}

void GameObject::render()
	{
		graphics->FillRectangle(brush, RectangleF(location, size));
	}
