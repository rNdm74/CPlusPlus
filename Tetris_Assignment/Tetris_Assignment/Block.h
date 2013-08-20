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

enum EMoveType
	{
		ROTATE,
		MOVE
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
		void moveRotate();
		virtual void rotate(array<Point>^ temp);
		void move(array<Point>^ temp, Point direction);
		void draw();
		void lookAhead(Point direction);
		bool canMove(array<Point>^ temp);
		void addToGrid(int cel, int row, Color color);
	};
