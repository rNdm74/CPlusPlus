#include "StdAfx.h"
#include "Character.h"

Character::Character()
	{
		xPos = 0;
		yPos = 0;
	}
Character::Character(float x, float y)
	{
		xPos = x;
		yPos = y;
	}
Character::Character(float x, float y, float w, float h)
	{
		xPos = x;
		yPos = y;
		width = w;
		height = h;
	}

Character::~Character()
	{

	}

void Character::move()
	{
		yPos += speed * velocity;
	}
void Character::render()
	{

	}
void Character::update()
	{

	}
