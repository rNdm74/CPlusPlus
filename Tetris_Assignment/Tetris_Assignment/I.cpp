#include "StdAfx.h"
#include "I.h"

I::I(Color color, GameGrid^ grid, Grid^ preview)
  : Tetrimino(color, grid, preview)
	{
		tetriminoType = I_TETRIMINO;
		tetrimino = Image::FromFile("I.png");

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
		orientation %= 2;

		switch(static_cast<EDirection>(orientation))
		{	
			case EAST: //done
				temp[0].X-=2;
				temp[0].Y-=2;
				temp[1].X--;
				temp[1].Y--;
				//temp[2].X++;
				//temp[2].Y++;
				temp[3].X++;
				temp[3].Y++;				 
				break;
			case SOUTH: //done
				temp[0].X+=2;
				temp[0].Y+=2;
				temp[1].X++;
				temp[1].Y++;
				//temp[2].X++;
				//temp[2].Y++;
				temp[3].X--;
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