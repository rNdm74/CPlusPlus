#include "StdAfx.h"
#include "GameObject.h"

GameObject::GameObject()
{
}
void GameObject::render(Graphics^ g)
{
	Drawing::RectangleF rect = Drawing::Rectangle(xPos, yPos, width, height);
	g->FillRectangle(Brushes::White, rect);	
}
