#pragma once

#include "Grid.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

enum EDirection 
	{
		EAST = 0,
		SOUTH = 1,
		WEST = 2,
		NORTH = 3
	};

ref class Block
	{
	protected:
		array<Point>^ squares;
		Color blockColor;
		Grid^ gameGrid;
		int orientation;
		
	public:
		Block(array<Point>^ square, Color color, Grid^ grid);
		void moveLeft();
		void moveRight();
		void moveDown();
		virtual void rotate();
		void draw();
		bool canMove();
		void addToGrid(int cel, int row, Color color);
	};
