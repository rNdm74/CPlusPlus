#include "StdAfx.h"
#include "GameObjectList.h"

GameObjectList::GameObjectList(void)
{
	head = nullptr;
	tail = nullptr;
}

int GameObjectList::countGameObjects()
{
	GameObject^ objectWalker = head;

	int count = 0;

	while(objectWalker != nullptr)
	{
		count++;

		// Move to next node
		objectWalker = objectWalker->Next;
	}

	return count;
}

void GameObjectList::add(GameObject^ newGameObject)
{
	if(tail == nullptr)			// Empty list
	{
		head = newGameObject;
		tail = newGameObject;

	}
	else						// Adding to end
	{
		tail->Next = newGameObject;
		tail = newGameObject;
	}
}

void GameObjectList::remove(GameObject^ gameObjectToDelete)
{
	// Assume Node^ nodeToDelete is passed in
	GameObject^ objectWalker;

	// Start at the beginning of the list
	objectWalker = head;

	// Check first node
	if(objectWalker == gameObjectToDelete)
	{
		// If only node in the list
		if(objectWalker->Next == nullptr)
		{
			//Clear node
			head = nullptr;
			tail = nullptr;
		}
		else
		{
			// Move to next node
			head = objectWalker->Next;
		}			
	}		
	else
	{
		// Find the node BEFORE nodeToDelete
		while(objectWalker->Next != gameObjectToDelete)
			objectWalker = objectWalker->Next;

		// Update tail
		if(tail == gameObjectToDelete)
			tail = objectWalker;

		// Found it. Swoop around
		objectWalker->Next = gameObjectToDelete->Next;			
	}		
}

void GameObjectList::update()
{
	GameObject^ objectWalker = head;		

	while(objectWalker != nullptr)
	{
		// Check to delete pellet
		if(objectWalker->getYPos() < 0)			
			remove(objectWalker);			

		// Move pellet
		objectWalker->update();			

		// Move to next node
		objectWalker = objectWalker->Next;
	}
}

void GameObjectList::render()
{		
	GameObject^ objectWalker = head;		

	while(objectWalker != nullptr)
	{
		// Draw pellets
		objectWalker->render();

		// Move to next node
		objectWalker = objectWalker->Next;
	}
}



