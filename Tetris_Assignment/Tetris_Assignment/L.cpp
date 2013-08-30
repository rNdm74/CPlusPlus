#include "StdAfx.h"
#include "L.h"

L::L(ResourceManager^ rm, Color color, GameGrid^ grid, Grid^ preview)
  : Tetrimino(rm, color, grid, preview)
	{
		// Applys block type
		tetriminoType = L_TETRIMINO;
		tetrimino = (Image^)rm->GetObject("L");//Image::FromFile("L.png");
				
		// Initializes the block pattern
		curPosition = gcnew array<Point> 
		{ 
			Point(0 + L_X, 1), 
			Point(1 + L_X, 1), 
			Point(2 + L_X, 1),
			Point(2 + L_X, 0)
		};
	}

void L::rotate(array<Point>^ temp)
	{
		// Resets the enumeration variable
		orientation %= 4;

		// Shifts the point to a new point based on the block shape
		switch(static_cast<EDirection>(orientation))
		{	
			case EAST: //done
				temp[0].X+=2;
				temp[0].Y-=2;
				temp[1].X++;
				temp[1].Y--;
				//squares[2].X++; // Rotation point
				//squares[2].Y++;
				temp[3].X++;
				temp[3].Y++;

				 
				break;
			case SOUTH:
				temp[0].X+=2;
				temp[0].Y+=2;
				temp[1].X++;
				temp[1].Y++;
				//squares[2].X++; // Rotation point
				//squares[2].Y++;
				temp[3].X--;
				temp[3].Y++; 
				break;
			case WEST:
				temp[0].X-=2;
				temp[0].Y+=2;
				temp[1].X--;
				temp[1].Y++;
				//squares[2].X++; // Rotation point
				//squares[2].Y++;
				temp[3].X--;
				temp[3].Y--; 
				break;
			case NORTH:
				temp[0].X-=2;
				temp[0].Y-=2;
				temp[1].X--;
				temp[1].Y--;
				//squares[2].X++; // Rotation point
				//squares[2].Y++;
				temp[3].X++;
				temp[3].Y--;
				break;
		}
	}
