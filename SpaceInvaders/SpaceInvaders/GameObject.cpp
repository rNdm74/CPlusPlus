#include "StdAfx.h"
#include "GameObject.h"

GameObject::GameObject(RectangleF startRect, PointF startVel, Graphics^ startCanvas)
{
	rect = startRect;
	vel = startVel;
	
	pen = gcnew Pen(Color::White, 2);
	brush = gcnew SolidBrush(Color::White);
	canvas = startCanvas;

	visible = true;
}

void GameObject::update()
{
	
}

void GameObject::render()
{
	canvas->FillRectangle(brush, rect);
}

void GameObject::shoot()
{
}

bool GameObject::collision(GameObject^ go)
	{
		RectangleF r1 = getBounds();
		RectangleF r2 = go->getBounds();

		return r1.IntersectsWith(r2);
	}
