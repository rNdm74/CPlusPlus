#include "StdAfx.h"
#include "SpriteList.h"

SpriteList::SpriteList()
	{
		head = nullptr;
		tail = nullptr;
	}

int SpriteList::length()
{
	Sprite^ spriteWalker = head;

	int count = 0;

	while(spriteWalker != nullptr)
	{
		count++;

		// Move to next node
		spriteWalker = spriteWalker->Next;
	}

	return count;
}

Sprite^ SpriteList::get(int item)
{
	Sprite^ spriteWalker = head;

	int count = 0;

	while(spriteWalker != nullptr)
	{
		if(item == count) return spriteWalker;

		count++;
		
		// Move to next node
		spriteWalker = spriteWalker->Next;		
	}

	return nullptr;
}

void SpriteList::add(Sprite^ newSprite)
{
	if(tail == nullptr)			// Empty list
	{
		head = newSprite;
		tail = newSprite;

	}
	else						// Adding to end
	{
		tail->Next = newSprite;
		tail = newSprite;
	}
}

void SpriteList::remove(Sprite^ SpriteToDelete)
{
	// Assume Node^ nodeToDelete is passed in
	Sprite^ spriteWalker;

	// Start at the beginning of the list
	spriteWalker = head;

	// Check first node
	if(spriteWalker == SpriteToDelete)
	{
		// If only node in the list
		if(spriteWalker->Next == nullptr)
		{
			//Clear node
			head = nullptr;
			tail = nullptr;
		}
		else
		{
			// Move to next node
			head = spriteWalker->Next;
		}			
	}		
	else
	{
		// Find the node BEFORE nodeToDelete
		while(spriteWalker->Next != SpriteToDelete)
			spriteWalker = spriteWalker->Next;

		// Update tail
		if(tail == SpriteToDelete)
			tail = spriteWalker;

		// Found it. Swoop around
		spriteWalker->Next = SpriteToDelete->Next;			
	}		
}

void SpriteList::checkSpriteCollision(int vX, int vY)
{
	Sprite^ spriteWalker = head;		

	while(spriteWalker != nullptr)
	{
		Sprite^ s1 = spriteWalker;
		Sprite^ s2 = spriteWalker->Next;		

		while(s2 != nullptr)
		{
			//Point s1Bounds = Point((s1->getXPos() - vX) + s1->getWidth() / 2, s1->getYPos() - vY) + s1->getHeight() / 2);
			Rectangle s1BoundsRect = Rectangle(s1->getXPos() - vX, s1->getYPos() - vY, s1->getWidth(), s1->getHeight());
			Rectangle s2BoundsRect = Rectangle(s2->getXPos() - vX, s2->getYPos() - vY, s2->getWidth(), s2->getHeight());

			if(s1BoundsRect.IntersectsWith(s2BoundsRect))
			{
				remove(s2);
			}	

			s2 = s2->Next;
		}

		// Move to next node
		spriteWalker = spriteWalker->Next;
	}
}

void SpriteList::update()
{
	Sprite^ spriteWalker = head;		

	while(spriteWalker != nullptr)
	{
		spriteWalker->update();

		// Move to next node
		spriteWalker = spriteWalker->Next;
	}
}

void SpriteList::approach_avoid(Sprite^ target)
{
	Sprite^ spriteWalker = head;		

	while(spriteWalker != nullptr)
	{
		Point spriteLocation = Point(spriteWalker->getXPos(), spriteWalker->getYPos());
		Point targetLocation = Point(target->getXPos(), target->getYPos());

		int xDelta = targetLocation.X - spriteLocation.X;
		int yDelta = targetLocation.Y - spriteLocation.Y;

		if(xDelta < RANGE && xDelta > -RANGE && yDelta < RANGE && yDelta > -RANGE)
			spriteWalker->approach_avoid(target);

		// Move to next node
		spriteWalker = spriteWalker->Next;
	}
}

void SpriteList::renderSprites(int vX, int vY)
{		
	Sprite^ spriteWalker = head;		

	while(spriteWalker != nullptr)
	{
		// calculate sprite pos in the viewport
		int vPosX = spriteWalker->getXPos() - vX;
		int vPosY = spriteWalker->getYPos() - vY;

		// if sprite is in viewport bounds draw
				
		spriteWalker->draw(vPosX, vPosY);		

		// Move to next node
		spriteWalker = spriteWalker->Next;
	}
}

void SpriteList::draw()
{		
	Sprite^ spriteWalker = head;		

	while(spriteWalker != nullptr)
	{
		// Draw pellets
		spriteWalker->draw();

		// Move to next node
		spriteWalker = spriteWalker->Next;
	}
}
