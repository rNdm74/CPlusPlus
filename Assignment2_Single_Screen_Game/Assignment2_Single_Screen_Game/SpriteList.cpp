#include "StdAfx.h"
#include "SpriteList.h"

SpriteList::SpriteList(Viewport^ startViewport)
	{
		viewport = startViewport;

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

void SpriteList::pickupItem(Sprite^ otherSprite, SoundManager^ sManager)
{
	Sprite^ spriteWalker = head;		

	while(spriteWalker != nullptr)
	{
		if(spriteWalker->collided(otherSprite))								// If collision between sprites
		{			
			sManager->collectFlag->Play();									// play collect flag sound here

			String^ name = spriteWalker->getFilename()->Substring(15,2);	// Gets the item number from filename

			flag = int::Parse(name);										// Sets flag that is picked up

			flagCount++;													// Adds to flag count

			score += FLAG_PICKUP;											// Increase score

			remove(spriteWalker);											// Remove flag from list

			delete name;
		}

		// Move to next node
		spriteWalker = spriteWalker->Next;
	}
}

void SpriteList::collectCoin(SoundManager^ sManager)
{
	Sprite^ spriteWalker = head;		

	while(spriteWalker != nullptr)
	{
		if(spriteWalker->collectCoin())
		{			
			sManager->collectCoin->Play();				// Collect coin sound here

			spriteWalker->setAction(COLLECT_COIN);		// Coin can be added to player
			spriteWalker->executeBoundsAction();		// Executes the action
		}

		// Move to next node
		spriteWalker = spriteWalker->Next;
	}
}

void SpriteList::checkCollisions(Sprite^ otherSprite, SoundManager^ sManager)
{
	Sprite^ spriteWalker = head;		

	while(spriteWalker != nullptr)
	{
		if(otherSprite->isAlive() == false)
		{			
			otherSprite->hurt(sManager);				// Runs the hurt effect
		}

		if(spriteWalker->collided(otherSprite))			// 
		{			
			otherSprite->setAction(DIE);
			otherSprite->executeBoundsAction();
		}				

		// Move to next node
		spriteWalker = spriteWalker->Next;
	}
}

void SpriteList::setSpritePositions(MapManager^ mManager)
{
	Sprite^ spriteWalker = head;		

	while(spriteWalker != nullptr)
	{
		Point startPos = mManager->getSpawnPosition(spriteWalker->getObjectNumber(), spriteWalker->getHeight());

		spriteWalker->setStartPosition(startPos);
		spriteWalker->setXPos(startPos.X);
		spriteWalker->setYPos(startPos.Y);

		// Move to next node
		spriteWalker = spriteWalker->Next;
	}
}

void SpriteList::setSpritesMagnitudes(int newXMag, int newYMag)
{
	Sprite^ spriteWalker = head;		

	while(spriteWalker != nullptr)
	{		
		spriteWalker->setXMag(newXMag);
		spriteWalker->setYMag(newYMag);

		// Move to next node
		spriteWalker = spriteWalker->Next;
	}
}

void SpriteList::spriteAI()
{		
	Sprite^ spriteWalker = head;		

	while(spriteWalker != nullptr)
	{
		// Make sprites wander
		if(!spriteWalker->isBoundsCollision())
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
