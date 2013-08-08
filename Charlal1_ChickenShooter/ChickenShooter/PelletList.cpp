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

		// Check first node
		if(pelletWalker == pelletToDelete)
		{
			// If only node in the list
			if(pelletWalker->Next == nullptr)
			{
				//Clear node
				head = nullptr;
				tail = nullptr;
			}
			else
			{
				// Move to next node
				head = pelletWalker->Next;
			}			
		}
		else if(tail == pelletToDelete)
		{
			pelletWalker = head;

			while(pelletWalker->Next != nullptr)				
				pelletWalker = pelletWalker->Next;

			tail = pelletWalker;
		}
		else
		{
			// Find the node BEFORE nodeToDelete
			while(pelletWalker->Next != pelletToDelete)
				pelletWalker = pelletWalker->Next;
			
			// Found it. Swoop around
			pelletWalker->Next = pelletToDelete->Next;			
		}		
	}

void PelletList::renderPellets()
	{		
		Pellet^ pelletWalker = head;		

		while(pelletWalker != nullptr)
		{
			// Draw pellets
			pelletWalker->draw();

			// Move to next node
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

			// Move to next node
			pelletWalker = pelletWalker->Next;
		}

		return count;
	}

void PelletList::updatePellets()
	{
		Pellet^ pelletWalker = head;		

		while(pelletWalker != nullptr)
		{
			// Check to delete pellet
			if(pelletWalker->getYPos() < 0 || pelletWalker->getYPos() > 600)			
				deletePellet(pelletWalker);			

			// Move pellet
			pelletWalker->update();			

			// Move to next node
			pelletWalker = pelletWalker->Next;
		}
	}
