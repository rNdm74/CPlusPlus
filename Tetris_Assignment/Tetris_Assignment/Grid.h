#pragma once

#include "Cell.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Drawing::Text;

#define CELL_SIZE 30
#define N_COLS 14
#define N_ROWS 26


ref class Grid
	{
	private:
		array<Cell^, 2>^ gridData;
		array<Point>^ blocks;
		Point gridLocation;
		Graphics^ graphics;

		int playerScore;
		int playerLines;
		int playerLevel;	

	public:
		Grid(Point location, Graphics^ dbGraphics, Font^ font);

		void draw();
		void update();
		void drawOneSquare(int col, int row, Color color); //- ifFull(x,y)
		bool isRowFull(int rowNumber); //- all cells in row are full 
		void deleteRow(int rowNumber); //- cell up above is now my color cycle up from bottom

		int getPlayerScore()			{ return playerScore; }
		int getPlayerLines()			{ return playerLines; }
		int getPlayerLevel()			{ return playerLevel; }

		int getGridLeft()				{ return 0; }
		int getGridRight()				{ return N_COLS-1; }
		int getGridBottom()				{ return N_ROWS-1; }

		Cell^ getCell(int col, int row)	{ return gridData[col, row]; }
		Cell^ getCell(Point p)			{ return gridData[p.X, p.Y]; }
	};
