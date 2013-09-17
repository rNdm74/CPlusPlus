#include "StdAfx.h"
#include "SpriteList.h"

SpriteList::SpriteList(Viewport^ startViewport)
	{
		viewport = startViewport;

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

void SpriteList::update()
{
	Sprite^ spriteWalker = head;		

	while(spriteWalker != nullptr)
	{
		// Check to delete pellet
		/*if(spriteWalker->getYPos() < 0)			
			remove(spriteWalker);*/
		Rectangle bounds = spriteWalker->getBoundsRectangle();

	    spriteWalker->update();

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
		Rectangle vBounds = viewport->getViewportBounds();

		if(vBounds.Contains(vPosX, vPosY))
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
