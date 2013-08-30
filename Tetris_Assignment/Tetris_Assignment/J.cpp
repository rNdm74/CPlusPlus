#include "StdAfx.h"
#include "J.h"

J::J(ResourceManager^ rm, Color color, GameGrid^ grid, Grid^ preview)
  : Tetrimino(rm, color, grid, preview)
	{
		// Applys block type
		tetriminoType = J_TETRIMINO;
		tetrimino = (Image^)rm->GetObject("J");//Image::FromFile("J.png");

		// Initializes the block pattern
		curPosition = gcnew array<Point> 
		{ 
			Point(2 + J_X, 1), 			 
			Point(1 + J_X, 1),
			Point(0 + J_X, 1),
			Point(0 + J_X, 0)
		};
	}

void J::rotate(array<Point>^ temp)
	{
		// Resets the enumeration variable
		orientation %= 4;

		// Shifts the point to a new point based on the block shape
		switch(static_cast<EDirection>(orientation))
		{	
			case EAST:
				temp[0].X-=2;
				temp[0].Y+=2;
				temp[1].X--;
				temp[1].Y++;
				//temp[2].X++; // Rotation point
				//temp[2].Y++;
				temp[3].X++;
				temp[3].Y++;				 
				break;
			case SOUTH:
				temp[0].X-=2;
				temp[0].Y-=2;
				temp[1].X--;
				temp[1].Y--;
				//temp[2].X++; // Rotation point
				//temp[2].Y++;
				temp[3].X--;
				temp[3].Y++;
				break;
			case WEST:
				temp[0].X+=2;
				temp[0].Y-=2;
				temp[1].X++;
				temp[1].Y--;
				//temp[2].X++; // Rotation point
				//temp[2].Y++;
				temp[3].X--;
				temp[3].Y--;  
				break;
			case NORTH:
				temp[0].X+=2;
				temp[0].Y+=2;
				temp[1].X++;
				temp[1].Y++;
				//temp[2].X++; // Rotation point
				//temp[2].Y++;
				temp[3].X++;
				temp[3].Y--;				
				break;
		}
	}