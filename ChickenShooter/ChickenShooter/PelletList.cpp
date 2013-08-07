#include "StdAfx.h"
#include "PelletList.h"

PelletList::PelletList()
	{
		head = nullptr;
		tail = nullptr;
	}

void PelletList::addPellet(Pellet^ newPellet)
	{
		if(tail == nullptr)			// Empty list
		{
			head = newPellet;
			tail = newPellet;

		}
		else						// Adding to end
		{
			tail->Next = newPellet;
			tail = newPellet;
		}
	}

void PelletList::deletePellet(Pellet^ pelletToDelete)
	{
		// Assume Node^ nodeToDelete is passed in
		Pellet^ pelletWalker;

		// Start at the beginning of the list
		pelletWalker = head;

		// Find the node BEFORE nodeToDelete
		while(pelletWalker->Next != pelletToDelete)
			pelletWalker = pelletWalker->Next;
		
		// Found it. Swoop around
		pelletWalker->Next = pelletToDelete->Next;
	}

void PelletList::renderPellets()
	{
		Pellet^ pelletWalker;

		pelletWalker = head;

		while(pelletWalker != nullptr)
		{
			pelletWalker->draw();

			pelletWalker = pelletWalker->Next;
		}
	}

int PelletList::countPellets()
	{
		Pellet^ pelletWalker = head;

		int count = 0;

		while(pelletWalker != nullptr)
		{
			count++;
			pelletWalker = pelletWalker->Next;
		}

		return count;
	}

void PelletList::updatePellets()
	{
		Pellet^ pelletWalker;

		pelletWalker = head;

		while(pelletWalker != nullptr)
		{
			pelletWalker->update();

			pelletWalker = pelletWalker->Next;
		}
	}
