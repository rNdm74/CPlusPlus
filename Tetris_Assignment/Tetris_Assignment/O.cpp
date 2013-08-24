#include "StdAfx.h"
#include "O.h"

O::O(int startX, Color color, Grid^ grid, Grid^ preview)
  : Block(color, grid, preview)
	{
		blockType = O_BLOCK;

		squares = gcnew array<Point> 
		{ 
			Point(1 + startX, 0), 
			Point(1 + startX, 1), 
			Point(2 + startX, 0),
			Point(2 + startX, 1)
		};
	}

void O::rotate(array<Point>^ temp)
	{
		//orientation %= 4;

		//switch(static_cast<EDirection>(orientation))
		//{	
		//	case EAST: //done
		//		squares[0].X+=2;
		//		squares[0].Y+=2;
		//		squares[1].X++;
		//		squares[1].Y++;
		//		//squares[2].X++;
		//		//squares[2].Y++;
		//		squares[3].X--;
		//		squares[3].Y++; 
		//		break;
		//	case SOUTH: //done
		//		squares[0].X-=2;
		//		squares[0].Y+=2;
		//		squares[1].X--;
		//		squares[1].Y++;
		//		//squares[2].X++;
		//		//squares[2].Y++;
		//		squares[3].X--;
		//		squares[3].Y--; 
		//		break;
		//	case WEST:
		//		squares[0].X-=2;
		//		squares[0].Y-=2;
		//		squares[1].X--;
		//		squares[1].Y--;
		//		//squares[2].X++;
		//		//squares[2].Y++;
		//		squares[3].X++;
		//		squares[3].Y--; 
		//		break;
		//	case NORTH:
		//		squares[0].X+=2;
		//		squares[0].Y-=2;
		//		squares[1].X++;
		//		squares[1].Y--;
		//		//squares[2].X++;
		//		//squares[2].Y++;
		//		squares[3].X++;
		//		squares[3].Y++;
		//		break;
		//}

		//orientation++;
	}
