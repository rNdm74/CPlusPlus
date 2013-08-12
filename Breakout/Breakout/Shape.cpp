#include "StdAfx.h"
#include "Shape.h"

Shape::Shape(int startXPos, int startYPos, int startWidth, int startHeight, 
			Graphics^ startCanvas, int startXVel, int startYVel, Color startColor)
	{
		xPos = startXPos;
		yPos = startYPos;
		width = startWidth;
		height = startHeight;
		canvas = startCanvas;
		xVel = startXVel;
		yVel = startYVel;
		color = startColor;
		brush = gcnew SolidBrush(startColor);
		pen = gcnew Pen(Color::Black, 2);
		visible = true;
	}

void Shape::erase()
	{
	}

void Shape::move()
	{
	}

void Shape::draw()
	{
		// Impliemented by child
	}

void Shape::collision(Shape^ object)
	{
	}
