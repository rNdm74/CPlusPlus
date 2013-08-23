#include "StdAfx.h"
#include "I.h"

I::I(int startX, Color color, Grid^ grid)
  : Block(color, grid)
	{
		blockType = EBlockType::I_BLOCK;

		squares = gcnew array<Point> 
		{ 
			Point(startX, 0), 
			Point(startX, 1), 
			Point(startX, 2),
			Point(startX, 3)
		};
	}

void I::rotate(array<Point>^ temp)
	{
		orientation %= 2;

		switch(static_cast<EDirection>(orientation))
		{	
			case EAST: //done
				temp[0].X+=2;
				temp[0].Y+=2;
				temp[1].X++;
				temp[1].Y++;
				//temp[2].X++;
				//temp[2].Y++;
				temp[3].X--;
				temp[3].Y--; 
				break;
			case SOUTH: //done
				temp[0].X-=2;
				temp[0].Y-=2;
				temp[1].X--;
				temp[1].Y--;
				//temp[2].X++;
				//temp[2].Y++;
				temp[3].X++;
				temp[3].Y++; 
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