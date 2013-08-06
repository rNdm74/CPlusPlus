#include "StdAfx.h"
#include "LinkedList.h"

LinkedList::LinkedList(void)
	{
		head = nullptr;
		tail = nullptr;
	}

int LinkedList::length()
	{
		Node^ nodeWalker = head;

		int count = 0;

		while(nodeWalker != nullptr)
		{
			count++;
			nodeWalker = nodeWalker->Next;
		}

		return count;
	}

void LinkedList::add(Node^ newNode)
	{
		if(tail == nullptr)			// Empty list
		{
			head = newNode;
			tail = newNode;

		}
		else						// Adding to end
		{
			tail->Next = newNode;
			tail = newNode;
		}
	}

void LinkedList::remove(Node^ nodeToDelete)
	{
		// Assume Node^ nodeToDelete is passed in
		Node^ nodeWalker;

		// Start at the beginning of the list
		nodeWalker = head;

		// Find the node BEFORE nodeToDelete
		while(nodeWalker->Next != nodeToDelete)
			nodeWalker = nodeWalker->Next;
		
		// Found it. Swoop around
		nodeWalker->Next = nodeToDelete->Next;
	}