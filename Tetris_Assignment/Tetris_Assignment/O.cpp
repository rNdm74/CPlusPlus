#include "StdAfx.h"
#include "O.h"

O::O(array<Point>^ square, Color color, Grid^ grid)
  : Block(square, color, grid)
	{
	}

void O::rotate()
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
