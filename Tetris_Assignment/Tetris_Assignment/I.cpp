#include "StdAfx.h"
#include "I.h"

I::I(ResourceManager^ rm, Color color, GameGrid^ grid, Grid^ preview)
  : Tetrimino(rm, color, grid, preview)
	{
		// Applys block type
		tetriminoType = I_TETRIMINO;
		tetrimino = (Image^)rm->GetObject("I");//Image::FromFile("I.png");

		// Initializes the block pattern
		curPosition = gcnew array<Point> 
		{ 
			Point(3 + I_X, 0), 
			Point(2 + I_X, 0), 
			Point(1 + I_X, 0),
			Point(0 + I_X, 0)
		};

	}

void I::rotate(array<Point>^ temp)
	{
		// Resets the enumeration variable
		orientation %= 2;

		// Shifts the point to a new point based on the block shape
		switch(static_cast<EDirection>(orientation))
		{	
			case EAST: 
				temp[0].X-=2;
				temp[0].Y-=2;
				temp[1].X--;
				temp[1].Y--;
				//temp[2].X++; // Rotation point
				//temp[2].Y++;
				temp[3].X++;
				temp[3].Y++;				 
				break;
			case SOUTH:
				temp[0].X+=2;
				temp[0].Y+=2;
				temp[1].X++;
				temp[1].Y++;
				//temp[2].X++; // Rotation point
				//temp[2].Y++;
				temp[3].X--;
				temp[3].Y--; 
				break;			
		}
	}