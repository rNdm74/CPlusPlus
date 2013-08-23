#include "StdAfx.h"
#include "T.h"

T::T(Color color, Grid^ grid)
  : Block(color, grid)
	{
		blockType = EBlockType::T_BLOCK;

		squares = gcnew array<Point> 
		{ 
			Point(1,0), 
			Point(0,1), 
			Point(1,1),
			Point(2,1)
		};
	}

void T::rotate(array<Point>^ temp)
	{
		orientation %= 4;

		switch(static_cast<EDirection>(orientation))
		{	
			case EAST: //done
				temp[0].X++;
				temp[0].Y++;
				temp[1].X++;
				temp[1].Y--;
				//temp[2].X++;
				//temp[2].Y++;
				temp[3].X--;
				temp[3].Y++; 
				break;
			case SOUTH: //done
				temp[0].X--;
				temp[0].Y++;
				temp[1].X++;
				temp[1].Y++;
				//temp[2].X++;
				//temp[2].Y++;
				temp[3].X--;
				temp[3].Y--; 
				break;
			case WEST:
				temp[0].X--;
				temp[0].Y--;
				temp[1].X--;
				temp[1].Y++;
				//temp[2].X++;
				//temp[2].Y++;
				temp[3].X++;
				temp[3].Y--; 
				break;
			case NORTH:
				temp[0].X++;
				temp[0].Y--;
				temp[1].X--;
				temp[1].Y--;
				//temp[2].X++;
				//temp[2].Y++;
				temp[3].X++;
				temp[3].Y++;
				break;
		}
	}
