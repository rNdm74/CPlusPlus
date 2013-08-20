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
		lookAhead(Point(-1,0), EMoveType::MOVE);
	}

void Block::moveRight()
	{
		lookAhead(Point(1,0), EMoveType::MOVE);
	}

void Block::moveDown()
	{
		lookAhead(Point(0,1), EMoveType::MOVE);
	}

void Block::moveRotate()
	{
		lookAhead(Point(0,0), EMoveType::ROTATE);
	}

void Block::rotate(array<Point>^ temp)
	{
	}

void Block::move(array<Point>^ temp, Point direction)
	{
		for(int i = 0; i < temp->Length; i++)
		{	
			temp[i].X+=direction.X;
			temp[i].Y+=direction.Y;
		}
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
	}

void Block::lookAhead(Point direction, EMoveType moveType)
	{
		array<Point>^ temp = gcnew array<Point>(squares->Length);

		for(int square = 0; square < squares->Length; square++)
			temp[square] = squares[square];

		switch(moveType)
		{
			case ROTATE:
				rotate(temp);
				break;
			case MOVE:
				move(temp, direction);
				break;
		}
		

		if(canMove(temp))
			for(int square = 0; square < squares->Length; square++)
				squares[square] = temp[square];
	}

bool Block::canMove(array<Point>^ temp)
	{
		for(int square = 0; square < squares->Length; square++)
		{
			return	(temp[square].X < 10 && temp[square].X > 1 && temp[square].Y < 19);
		}
		
		return false;
	}

void Block::addToGrid(int cel, int row, Color color)
	{
		// add new block
	}
