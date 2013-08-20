#include "StdAfx.h"
#include "Block.h"

Block::Block(array<Point>^ square, Color color, Grid^ grid)
	{
		squares = square;
		blockColor = color;
		gameGrid = grid;
		orientation = EDirection::EAST;
	}

void Block::moveLeft()
	{		
		for(int square = 0; square < squares->Length; square++)
		{	
			squares[square].X--;
		}
	}

void Block::moveRight()
	{
		for(int square = 0; square < squares->Length; square++)
		{	
			squares[square].X++;
		}
	}

void Block::moveDown()
	{
		for(int square = 0; square < squares->Length; square++)
		{	
			squares[square].Y++;
		}
	}

void Block::rotate()
	{
	}

void Block::draw()
	{
		for(int square = 0; square < squares->Length; square++)
			gameGrid->drawOneSquare
			(
				squares[square].X,
				squares[square].Y,
				blockColor
			);

		//for(int p = 0; p < blocklocation->Length; p++)
		//	graphics->FillRectangle(brush, blocklocation[p].X, blocklocation[p].Y, 20, 20);
	}

bool Block::canMove()
	{
		/*for(int square = 0; square < blocklocation->Length; square++)
		{
			return	(blocklocation[square].X > gameGrid->getGridLeft()) &&
					(blocklocation[square].X < 18);
		}*/
		return true;
	}

void Block::addToGrid(int cel, int row, Color color)
	{
		// add new block
	}
