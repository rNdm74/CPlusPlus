#include "StdAfx.h"
#include "Player.h"

Player::Player(RectangleF startRect, PointF startVel, Graphics^ startGraphics, GameObjectList^ gameBullets)
	   : GameObject(startRect, startVel, startGraphics)
{
	bullets = gameBullets;
}

void Player::keyDown(KeyEventArgs^  e)
{
	if(e->KeyCode == Keys::Up)
			direction.Y = -1;
	if(e->KeyCode == Keys::Down)
			direction.Y = 1;	
	if(e->KeyCode == Keys::Left)
			direction.X = -1;
	if(e->KeyCode == Keys::Right)
		direction.X = 1;

	if(e->KeyCode == Keys::Space)
		bullets->add(gcnew Bullet(RectangleF(rect.X + 4, rect.Y + 4, 2, 2), PointF(0.1,0.1), canvas, -1));
}

void Player::keyUp(KeyEventArgs^  e)
{
	if(e->KeyCode == Keys::Up ||
	   e->KeyCode == Keys::Down)
		direction.Y = 0;

	if(e->KeyCode == Keys::Left ||
	   e->KeyCode == Keys::Right)
		direction.X = 0;	
}

void Player::update()
{
	rect.X += vel.X * SPEED * direction.X;
	rect.Y += vel.Y * SPEED * direction.Y;
}

void Player::render()
{
	if(!hit)
	{
		canvas->FillRectangle(brush, rect);
	}
}
