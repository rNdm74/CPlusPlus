#pragma once

#include "Cell.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

#define CELL_SIZE 30
#define N_COLS 10
#define N_ROWS 20


ref class Grid
	{
	private:
		array<Cell^, 2>^ gridData;
		Point gridLocation;
		Graphics^ graphics;
		Brush^ brush;
	public:
		Grid(Point location, Graphics^ dbGraphics);

		void draw();
		void update();
		void drawOneSquare(int col, int row, Color color); //- ifFull(x,y)
		void isRowFull(); //- all cells in row are full 
		void deleteRow(); //- cell up above is now my color cycle up from bottom

		int getGridLeft()	{ return 0; }
		int getGridRight()	{ return N_COLS-1; }
		int getGridBottom() { return N_ROWS-1; }
	};
