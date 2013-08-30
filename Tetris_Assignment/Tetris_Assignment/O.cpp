#include "StdAfx.h"
#include "O.h"

O::O(ResourceManager^ rm, Color color, GameGrid^ grid, Grid^ preview)
  : Tetrimino(rm, color, grid, preview)
	{
		// Applys block type
		tetriminoType = O_TETRIMINO;
		tetrimino = (Image^)rm->GetObject("O");//Image::FromFile("O.png");

		// Initializes the block pattern
		curPosition = gcnew array<Point> 
		{ 
			Point(1 + O_X, 0), 
			Point(1 + O_X, 1), 
			Point(2 + O_X, 0),
			Point(2 + O_X, 1)
		};
	}

void O::rotate(array<Point>^ temp)
	{
		// Not needed
	}
