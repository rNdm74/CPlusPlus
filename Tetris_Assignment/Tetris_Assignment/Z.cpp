#include "StdAfx.h"
#include "Z.h"

Z::Z(Color color, Grid^ grid, Grid^ preview)
  : Tetrimino(color, grid, preview)
	{
		tetriminoType = Z_TETRIMINO;
		tetrimino = Image::FromFile("Z.png");

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
		orientation %= 2;

		switch(static_cast<EDirection>(orientation))
		{	
			case EAST: //done
				temp[0].X+=2;
				//temp[0].Y+=2;
				temp[1].X++;
				temp[1].Y++;
				//temp[2].X++;
				//temp[2].Y++;
				temp[3].X--;
				temp[3].Y++; 
				break;
			case SOUTH: //done
				temp[0].X-=2;
				//temp[0].Y+=2;
				temp[1].X--;
				temp[1].Y--;
				//temp[2].X++;
				//temp[2].Y++;
				temp[3].X++;
				temp[3].Y--; 
				break;
			//case WEST:
			//	temp[0].X-=2;
			//	temp[0].Y-=2;
			//	temp[1].X--;
			//	temp[1].Y--;
			//	//temp[2].X++;
			//	//temp[2].Y++;
			//	temp[3].X++;
			//	temp[3].Y--; 
			//	break;
			//case NORTH:
			//	temp[0].X+=2;
			//	temp[0].Y-=2;
			//	temp[1].X++;
			//	temp[1].Y--;
			//	//temp[2].X++;
			//	//temp[2].Y++;
			//	temp[3].X++;
			//	temp[3].Y++;
			//	break;
		}
	}