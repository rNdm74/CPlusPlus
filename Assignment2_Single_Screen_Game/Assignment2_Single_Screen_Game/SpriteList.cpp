#include "StdAfx.h"
#include "SpriteList.h"

SpriteList::SpriteList(Viewport^ startViewport)
	{
		viewport = startViewport;
		score = 000000;
		coins = 000000;
		flag = 0;
		flagCount = 0;
		lives = N_LIVES;

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

Sprite^ SpriteList::get(int index)
{
	Sprite^ spriteWalker = head;

	int count = 0;

	while(spriteWalker != nullptr)
	{
		if(index == count) 
			return spriteWalker;

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
		spriteWalker->updateFrame();

		spriteWalker->move(viewport->getViewportWorldX(), viewport->getViewportWorldY());		

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

void SpriteList::pickupItem(Sprite^ otherSprite)
{
	Sprite^ spriteWalker = head;		

	while(spriteWalker != nullptr)
	{
		if(spriteWalker->collided(otherSprite))
		{
			remove(spriteWalker);

			String^ name = spriteWalker->getFilename()->Substring(11,2);

			flag = int::Parse(name);

			flagCount++;

			score += 100;
		}

		// Move to next node
		spriteWalker = spriteWalker->Next;
	}
}

void SpriteList::collectCoin()
{
	Sprite^ spriteWalker = head;		

	while(spriteWalker != nullptr)
	{
		if(spriteWalker->collectCoin())
		{
			spriteWalker->setAction(COLLECT_COIN);
			spriteWalker->executeBoundsAction();	
		}

		// Move to next node
		spriteWalker = spriteWalker->Next;
	}
}

void SpriteList::checkCollisions(Sprite^ otherSprite)
{
	Sprite^ spriteWalker = head;		

	while(spriteWalker != nullptr)
	{
		if(spriteWalker->collided(otherSprite))	
		{
			otherSprite->setAction(DIE);
			otherSprite->executeBoundsAction();
		}				

		// Move to next node
		spriteWalker = spriteWalker->Next;
	}
}

void SpriteList::setSpritePositions(ObjectMap^ objectMap)
{
	Sprite^ spriteWalker = head;		

	while(spriteWalker != nullptr)
	{
		Point startPos = objectMap->getSpawnPosition(spriteWalker->getObjectNumber(), spriteWalker->getHeight());

		spriteWalker->setStartPosition(startPos);
		spriteWalker->setXPos(startPos.X);
		spriteWalker->setYPos(startPos.Y);

		// Move to next node
		spriteWalker = spriteWalker->Next;
	}
}

void SpriteList::spriteAI()
{		
	Sprite^ spriteWalker = head;		

	while(spriteWalker != nullptr)
	{
		// Draw pellets
		spriteWalker->wander();

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
