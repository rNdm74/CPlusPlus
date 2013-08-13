#include "StdAfx.h"
#include "RectangleShape.h"

RectangleShape::RectangleShape(int startX, int startY, int startWidth, int startHeight, Graphics^ g)
	{
		xPos = startX;
		yPos = startY;
		width = startWidth;
		height = startHeight;

		canvas = g;

		color = Color::WhiteSmoke;
		brush = gcnew SolidBrush(color);
		pen = gcnew Pen(Color::Black, 2);
	}

void RectangleShape::update()
	{
		brush = gcnew SolidBrush(color);
	}
		
void RectangleShape::render()
	{
		canvas->FillRectangle(brush, Rectangle(xPos, yPos, width, height));
		canvas->DrawRectangle(pen, Rectangle(xPos, yPos, width, height));
	}
