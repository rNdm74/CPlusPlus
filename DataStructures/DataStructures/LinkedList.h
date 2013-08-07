#pragma once

#include "Node.h"

ref class LinkedList
	{
	private:
		Node^ head;
		Node^ tail;
	public:
		LinkedList(void);

		int length();

		void add(Node^ newNode);
		void remove(Node^ nodeToDelete);
	};
