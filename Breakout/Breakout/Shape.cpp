#include "StdAfx.h"
#include "Shape.h"

Shape::Shape(float startXPos, float startYPos, float startWidth, float startHeight, 
			Graphics^ startCanvas, float startXVel, float startYVel, Color startColor)
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

void Shape::keyDown(KeyEventArgs^  e)
	{
		if(e->KeyCode == Keys::Left)
				xVel = -2;
		if(e->KeyCode == Keys::Right)
				xVel = 2;
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

bool Shape::collision(Shape^ s)
	{
		RectangleF r1 = getBounds();
		RectangleF r2 = s->getBounds();

		return r1.IntersectsWith(r2);
	}

void Shape::verticalBounce(float center)
	{
		// Sets direction
		yVel *= -1;

		// Sets bounce angle
		xVel += (float)(getCenterX() - center) * DAMPING;

		// Sets max velocity
		if (xVel > MAX_SPEEDY) xVel = MAX_SPEEDX;
		if (xVel < -MAX_SPEEDY) xVel = -MAX_SPEEDX;
	}

void Shape::verticalBounce()
	{
		// Sets direction
		yVel *= -1;
	}

void Shape::horizontalBounce()
	{
		// Sets direction
		xVel *= -1;
	}
