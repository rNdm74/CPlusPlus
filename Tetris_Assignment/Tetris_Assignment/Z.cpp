#include "StdAfx.h"
#include "Z.h"

Z::Z(ResourceManager^ rm, Color color, GameGrid^ grid, Grid^ preview)
  : Tetrimino(rm, color, grid, preview)
	{
		// Applys block type
		tetriminoType = Z_TETRIMINO;
		tetrimino = (Image^)rm->GetObject("Z");//Image::FromFile("Z.png");

		// Initializes the block pattern
		curPosition = gcnew array<Point> 
		{ 
			Point(0 + Z_X, 0), 
			Point(1 + Z_X, 0), 
			Point(1 + Z_X, 1),
			Point(2 + Z_X, 1)
		};
	}

void Z::rotate(array<Point>^ temp)
	{
		// Resets the enumeration variable
		orientation %= 2;

		// Shifts the point to a new point based on the block shape
		switch(static_cast<EDirection>(orientation))
		{	
			case EAST:
				temp[0].X+=2;
				//temp[0].Y+=2;
				temp[1].X++;
				temp[1].Y++;
				//temp[2].X++; // Rotation point
				//temp[2].Y++;
				temp[3].X--;
				temp[3].Y++; 
				break;
			case SOUTH:
				temp[0].X-=2;
				//temp[0].Y+=2;
				temp[1].X--;
				temp[1].Y--;
				//temp[2].X++; // Rotation point
				//temp[2].Y++;
				temp[3].X++;
				temp[3].Y--; 
				break;			
		}
	}