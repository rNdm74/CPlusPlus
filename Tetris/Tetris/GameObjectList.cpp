#include "StdAfx.h"
#include "GameObjectList.h"

GameObjectList::GameObjectList()
	{
		head = nullptr;
		tail = nullptr;
	}

void GameObjectList::addGameObject(GameObject^ newGameObject)
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

void GameObjectList::deleteGameObject(GameObject^ gameObjectToDelete)
	{
		// Assume Node^ nodeToDelete is passed in
		GameObject^ gameObjectWalker;

		// Start at the beginning of the list
		gameObjectWalker = head;

		// Check first node
		if(gameObjectWalker == gameObjectToDelete)
		{
			// If only node in the list
			if(gameObjectWalker->Next == nullptr)
			{
				//Clear node
				head = nullptr;
				tail = nullptr;
			}
			else
			{
				// Move to next node
				head = gameObjectWalker->Next;
			}			
		}		
		else
		{
			// Find the node BEFORE nodeToDelete
			while(gameObjectWalker->Next != gameObjectToDelete)
				gameObjectWalker = gameObjectWalker->Next;

			// Update tail
			if(tail == gameObjectToDelete)
				tail = gameObjectWalker;

			// Found it. Swoop around
			gameObjectWalker->Next = gameObjectToDelete->Next;			
		}
	}

int GameObjectList::countGameObjects()
	{
		GameObject^ gameObjectWalker = head;

		int count = 0;

		while(gameObjectWalker != nullptr)
		{
			count++;

			// Move to next node
			gameObjectWalker = gameObjectWalker->Next;
		}

		return count;
	}

void GameObjectList::inputGameObjects(KeyEventArgs^  e)
	{
		GameObject^ gameObjectWalker = head;		

		while(gameObjectWalker != nullptr)
		{
			// Move
			gameObjectWalker->input(e);			

			// Move to next node
			gameObjectWalker = gameObjectWalker->Next;
		}
	}

void GameObjectList::updateGameObjects()
	{
		GameObject^ gameObjectWalker = head;		

		while(gameObjectWalker != nullptr)
		{
			// Check to delete pellet
			//if(gameObjectWalker->getYPos() < 0 || gameObjectWalker->getYPos() > 480)			
			//	deletePellet(gameObjectWalker);			

			// Move pellet
			gameObjectWalker->update();			

			// Move to next node
			gameObjectWalker = gameObjectWalker->Next;
		}
	}

void GameObjectList::renderGameObjects()
	{
		GameObject^ gameObjectWalker = head;		

		while(gameObjectWalker != nullptr)
		{
			// Draw pellets
			gameObjectWalker->render();

			// Move to next node
			gameObjectWalker = gameObjectWalker->Next;
		}
	}
