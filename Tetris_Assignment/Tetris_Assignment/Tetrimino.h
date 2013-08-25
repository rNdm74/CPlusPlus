#pragma once

#include "Grid.h"
#include "PlaySound.h"

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

enum ETetriminoType 
	{
		L_TETRIMINO = 0,
		J_TETRIMINO = 1,
		Z_TETRIMINO = 2,
		S_TETRIMINO = 3,
		T_TETRIMINO = 4,
		I_TETRIMINO = 5,
		O_TETRIMINO = 6
	};

ref class Tetrimino abstract 
	{
	protected:
		array<Point>^ curPosition;
		array<Point>^ newPosition;

		Grid^ gameGrid;
		Grid^ tetriminoPreview;

		Image^ tetrimino;

		Color tetriminoColor;
		ETetriminoType tetriminoType;		

		int orientation;
		bool placed;	
		bool drop;
		
	public:
		Tetrimino(Color color, Grid^ grid, Grid^ preview);

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

		Image^ getTetrimino()				{ return tetrimino; }
		array<Point>^ getCurPosition()		{ return curPosition; }
		ETetriminoType getTetriminoType()	{ return tetriminoType; }
		bool isPlaced()						{ return placed; }
	};
