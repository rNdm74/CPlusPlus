#include "StdAfx.h"
#include "L.h"

L::L(Color color, Grid^ grid)
  : Block(color, grid)
	{
		blockType = EBlockType::L_BLOCK;

		squares = gcnew array<Point> 
		{ 
			Point(0,0), 
			Point(0,1), 
			Point(0,2),
			Point(1,2)
		};
	}

void L::rotate(array<Point>^ temp)
	{
		orientation %= 4;

		switch(static_cast<EDirection>(orientation))
		{	
			case EAST: //done
				temp[0].X+=2;
				temp[0].Y+=2;
				temp[1].X++;
				temp[1].Y++;
				//squares[2].X++;
				//squares[2].Y++;
				temp[3].X--;
				temp[3].Y++; 
				break;
			case SOUTH: //done
				temp[0].X-=2;
				temp[0].Y+=2;
				temp[1].X--;
				temp[1].Y++;
				//squares[2].X++;
				//squares[2].Y++;
				temp[3].X--;
				temp[3].Y--; 
				break;
			case WEST:
				temp[0].X-=2;
				temp[0].Y-=2;
				temp[1].X--;
				temp[1].Y--;
				//squares[2].X++;
				//squares[2].Y++;
				temp[3].X++;
				temp[3].Y--; 
				break;
			case NORTH:
				temp[0].X+=2;
				temp[0].Y-=2;
				temp[1].X++;
				temp[1].Y--;
				//squares[2].X++;
				//squares[2].Y++;
				temp[3].X++;
				temp[3].Y++;
				break;
		}
	}
