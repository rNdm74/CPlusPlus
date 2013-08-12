#include "StdAfx.h"
#include "RectangleShape.h"

RectangleShape::RectangleShape(int startXPos, int startYPos, int startWidth, int startHeight, 
			Graphics^ startCanvas, int startXVel, int startYVel, 
			Color startColor) : Shape(startXPos, startYPos, startWidth, startHeight, 
			startCanvas, startXVel, startYVel, startColor)
	{
	}

void RectangleShape::draw()
	{
		canvas->FillRectangle(brush, Rectangle(xPos, yPos, width, height));
		canvas->DrawRectangle(pen, Rectangle(xPos, yPos, width, height));
	}
