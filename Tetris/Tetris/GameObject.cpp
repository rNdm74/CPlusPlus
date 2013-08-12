#include "StdAfx.h"
#include "GameObject.h"

GameObject::GameObject(Point startLocation, Size startSize, Rectangle screenBounds, Graphics^ canvas, Color color)
	{
		direction = 0;
		
		yVel = SPEED;
		xVel = SPEED;

		location = startLocation;
		size = startSize;
		screen = screenBounds;
		graphics = canvas;
		brush = gcnew SolidBrush(color);
		pen = gcnew Pen(Color::DarkGray, 2);
	}

void GameObject::input(KeyEventArgs^  e)
	{
		if(!placed)
		{
			if(e->KeyCode == Keys::Left)
			{
				location.X += -20;
			}
			else if(e->KeyCode == Keys::Right)
			{
				location.X += 20;
			}
			else if(e->KeyCode == Keys::Up)
			{
				location.Y += -20;
			}
			else if(e->KeyCode == Keys::Down)
			{
				location.Y += 20;
			}
		}
	}

void GameObject::update()
	{
		placed = (location.Y + 20 > screen.Height - 20);
		
		// Update Code
		if(count > 200)
		{
			if(!placed)location.Y += yVel;
			count = 0;
		}
					
		count++;
	}

void GameObject::render()
	{
		graphics->FillRectangle(brush, Rectangle(location, size));
		graphics->DrawRectangle(pen, Rectangle(location, size));
		//
	}
