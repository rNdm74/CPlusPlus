#include "StdAfx.h"
#include "T.h"

T::T(ResourceManager^ rm, Color color, GameGrid^ grid, Grid^ preview)
  : Tetrimino(rm, color, grid, preview)
	{
		// Applys block type
		tetriminoType = T_TETRIMINO;
		tetrimino = (Image^)rm->GetObject("T");//Image::FromFile("T.png");

		// Initializes the block pattern
		curPosition = gcnew array<Point> 
		{ 
			Point(1 + T_X, 0), 
			Point(0 + T_X, 1), 
			Point(1 + T_X, 1),
			Point(2 + T_X, 1)
		};
	}

void T::rotate(array<Point>^ temp)
	{
		// Resets the enumeration variable
		orientation %= 4;

		// Shifts the point to a new point based on the block shape
		switch(static_cast<EDirection>(orientation))
		{	
			case EAST:
				temp[0].X++;
				temp[0].Y++;
				temp[1].X++;
				temp[1].Y--;
				//temp[2].X++; // Rotation point
				//temp[2].Y++;
				temp[3].X--;
				temp[3].Y++; 
				break;
			case SOUTH:
				temp[0].X--;
				temp[0].Y++;
				temp[1].X++;
				temp[1].Y++;
				//temp[2].X++; // Rotation point
				//temp[2].Y++;
				temp[3].X--;
				temp[3].Y--; 
				break;
			case WEST:
				temp[0].X--;
				temp[0].Y--;
				temp[1].X--;
				temp[1].Y++;
				//temp[2].X++; // Rotation point
				//temp[2].Y++;
				temp[3].X++;
				temp[3].Y--; 
				break;
			case NORTH:
				temp[0].X++;
				temp[0].Y--;
				temp[1].X--;
				temp[1].Y--;
				//temp[2].X++; // Rotation point
				//temp[2].Y++;
				temp[3].X++;
				temp[3].Y++;
				break;
		}
	}
