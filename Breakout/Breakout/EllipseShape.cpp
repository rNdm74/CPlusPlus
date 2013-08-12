#include "StdAfx.h"
#include "EllipseShape.h"

EllipseShape::EllipseShape(float startXPos, float startYPos, float startWidth, float startHeight, 
			Graphics^ startCanvas, float startXVel, float startYVel, 
			Color startColor) : Shape(startXPos, startYPos, startWidth, startHeight, 
			startCanvas, startXVel, startYVel, startColor)
	{
	}

void EllipseShape::draw()
	{
		canvas->FillEllipse(brush, xPos, yPos, width, height);
		canvas->DrawEllipse(pen, xPos, yPos, width, height);
	}
