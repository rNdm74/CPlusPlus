#include "StdAfx.h"
#include "RectangleShape.h"

RectangleShape::RectangleShape(float startXPos, float startYPos, float startWidth, float startHeight, 
			Graphics^ startCanvas, float startXVel, float startYVel, 
			Color startColor) : Shape(startXPos, startYPos, startWidth, startHeight, 
			startCanvas, startXVel, startYVel, startColor)
	{
	}

void RectangleShape::draw()
	{
		canvas->FillRectangle(brush, xPos, yPos, width, height);
		canvas->DrawRectangle(pen, xPos, yPos, width, height);
	}
