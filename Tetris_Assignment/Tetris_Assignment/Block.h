#pragma once

#include "Grid.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Media;

enum EDirection 
	{
		EAST = 0,
		SOUTH = 1,
		WEST = 2,
		NORTH = 3
	};

enum EBlockType 
	{
		L_BLOCK = 0,
		J_BLOCK = 1,
		Z_BLOCK = 2,
		S_BLOCK = 3,
		T_BLOCK = 4,
		I_BLOCK = 5,
		O_BLOCK = 6
	};

ref class Block abstract 
	{
	protected:
		array<Point>^ squares;
		array<Point>^ newPosition;
		Color blockColor;
		Grid^ gameGrid;
		Grid^ blockPreview;
		int orientation;
		bool placed;
		EBlockType blockType;
		
		float gravity;
		
		
		
	public:
		Block(Color color, Grid^ grid, Grid^ preview);

		void moveLeft();
		void moveRight();
		void moveDown();
		void moveRotate();

		virtual void rotate(array<Point>^ temp);

		void move(array<Point>^ temp);

		void draw();
		void drawPreview();

		array<Point>^ lookAhead(Point direction);
		bool canMove(array<Point>^ temp);
		void addToGrid(Color color);

		array<Point>^ getSquares()	{ return squares; }
		EBlockType getBlockType()	{ return blockType; }
		bool isPlaced()				{ return placed; }
	};
