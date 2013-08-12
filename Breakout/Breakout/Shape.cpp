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

void Shape::keyDown(KeyEventArgs^  e)
	{
		if(e->KeyCode == Keys::Left)
				xVel = -1;
		if(e->KeyCode == Keys::Right)
				xVel = 1;
	}

void Shape::keyUp(KeyEventArgs^  e)
	{
		if(e->KeyCode == Keys::Left ||
		   e->KeyCode == Keys::Right)
				xVel = 0;		
	}

void Shape::move()
	{
		xPos += xVel * SPEED;
		yPos += yVel * 1;
	}

void Shape::draw()
	{
		// Impliemented by child
	}

void Shape::collision(Shape^ s)
	{
		Rectangle r1 = getBounds();
		Rectangle r2 = s->getBounds();

		if(r1.IntersectsWith(r2))
		{
			//s = nullptr;
			visible = false;
			yVel = -yVel;
		}
	}
