#include "StdAfx.h"
#include "GameObject.h"

GameObject::GameObject(RectangleF startRect, PointF startVel, Graphics^ startCanvas)
{
	rect = startRect;
	vel = startVel;
	
	pen = gcnew Pen(Color::White, 2);
	brush = gcnew SolidBrush(Color::White);
	canvas = startCanvas;
}

void GameObject::update()
{
	
}

void GameObject::render()
{
	canvas->FillRectangle(brush, rect);
}
