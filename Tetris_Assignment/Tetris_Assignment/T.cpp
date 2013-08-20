#include "StdAfx.h"
#include "T.h"

T::T(array<Point>^ square, Color color, Grid^ grid)
  : Block(square, color, grid)
	{
	}

void T::rotate(array<Point>^ temp)
	{
		orientation %= 4;

		switch(static_cast<EDirection>(orientation))
		{	
			case EAST: //done
				squares[0].X++;
				squares[0].Y++;
				squares[1].X++;
				squares[1].Y--;
				//squares[2].X++;
				//squares[2].Y++;
				squares[3].X--;
				squares[3].Y++; 
				break;
			case SOUTH: //done
				squares[0].X--;
				squares[0].Y++;
				squares[1].X++;
				squares[1].Y++;
				//squares[2].X++;
				//squares[2].Y++;
				squares[3].X--;
				squares[3].Y--; 
				break;
			case WEST:
				squares[0].X--;
				squares[0].Y--;
				squares[1].X--;
				squares[1].Y++;
				//squares[2].X++;
				//squares[2].Y++;
				squares[3].X++;
				squares[3].Y--; 
				break;
			case NORTH:
				squares[0].X++;
				squares[0].Y--;
				squares[1].X--;
				squares[1].Y--;
				//squares[2].X++;
				//squares[2].Y++;
				squares[3].X++;
				squares[3].Y++;
				break;
		}

		orientation++;
	}
