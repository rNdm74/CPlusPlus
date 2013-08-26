#pragma once

#include "Cell.h"
#include "Sound.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Drawing::Text;

#define CELL_SIZE 30
//#define N_COLS 14
//#define N_ROWS 26


ref class Grid
	{
	protected:
		array<Cell^, 2>^ gridData;
		
		Point gridLocation;

		Image^ wall;

		float posY;
		float vel;

		int N_COLS;
		int N_ROWS;

		Graphics^ graphics;
		Sound^ gSound;
		
	public:
		Grid(Point location, Graphics^ dbGraphics, int cols, int rows);
		Grid(Point location, Graphics^ dbGraphics, Sound^ sound, int cols, int rows);

		virtual void update();

		virtual void draw();		
		virtual void drawOneSquare(int col, int row, Color color, Image^ image); //- ifFull(x,y)	

		virtual bool isRowFull(int rowNumber); //- all cells in row are full 
		virtual void deleteRow(int rowNumber); //- cell up above is now my color cycle up from bottom

		Sound^ getSound()				{ return gSound; }
		Cell^ getCell(int col, int row)	{ return gridData[col, row]; }
		Cell^ getCell(Point p)			{ return gridData[p.X, p.Y]; }
	};
