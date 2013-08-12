#include "StdAfx.h"
#include "EllipseShape.h"

EllipseShape::EllipseShape(int startXPos, int startYPos, int startWidth, int startHeight, 
			Graphics^ startCanvas, int startXVel, int startYVel, 
			Color startColor) : Shape(startXPos, startYPos, startWidth, startHeight, 
			startCanvas, startXVel, startYVel, startColor)
	{
	}

void EllipseShape::draw()
	{
		canvas->FillEllipse(brush, Rectangle(xPos, yPos, width, height));
		canvas->DrawEllipse(pen, Rectangle(xPos, yPos, width, height));
	}
