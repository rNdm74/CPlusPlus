#include "StdAfx.h"
#include "Block.h"

Block::Block(Color color, Grid^ grid)
	{	
		squares = nullptr;
		blockColor = color;
		gameGrid = grid;
		orientation = EDirection::EAST;
	}

void Block::moveLeft()
	{
		lookAhead(Point(-1,0));
	}

void Block::moveRight()
	{
		lookAhead(Point(1,0));
	}

void Block::moveDown()
	{
		lookAhead(Point(0,1));
	}

void Block::moveRotate()
	{
		array<Point>^ temp = gcnew array<Point>(squares->Length);

		for(int square = 0; square < temp->Length; square++)
			temp[square] = squares[square];

		rotate(temp);
		
		if(canMoveDown(temp))
		{
			for(int square = 0; square < squares->Length; square++)
				squares[square] = temp[square];

			orientation++;
		}
	}

void Block::rotate(array<Point>^ temp)
{
}

void Block::move(array<Point>^ temp, Point direction)
	{
		for(int i = 0; i < temp->Length; i++)
		{	
			//temp[i].X+=direction.X;
			//temp[i].Y+=direction.Y;
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

void Block::clear()
	{
		
	}

void Block::lookAhead(Point direction)
	{
		array<Point>^ temp = gcnew array<Point>(squares->Length);

		for(int square = 0; square < temp->Length; square++)
			temp[square] = squares[square];

		for(int i = 0; i < temp->Length; i++)
		{	
			temp[i].X+=direction.X;
			temp[i].Y+=direction.Y;
		}
		
		if(canMoveDown(temp))
		{
			 
			for(int square = 0; square < squares->Length; square++)
			{				
				squares[square] = temp[square];
				//Point p = squares[square];
				//gameGrid->getCell(p.X, p.Y)->setFull(true);
			}				
		}
		else
		{
			//FLAG TO STOP BLOCK
			for(int square = 0; square < squares->Length; square++)
			{	
				Point p = squares[square];
				gameGrid->getCell(p.X, p.Y)->setWall(true);
				gameGrid->getCell(p.X, p.Y)->setColor(Color::Red);

			}
			 
			placed = true;
			//blockColor = Color::Red;
		}
	}

bool Block::canMoveDown(array<Point>^ temp)
	{		
		array<bool>^ flags = gcnew array<bool>(4);

		for(int square = 0; square < temp->Length; square++)
		{	
			Point newP = temp[square];
			
			if(gameGrid->getCell(newP.X, newP.Y)->isWall())
			{
				flags[square] = gameGrid->getCell(newP.X, newP.Y)->isWall();
			}			
		}	

		for(int item = 0; item < squares->Length; item++)
			if(flags[item])return false;

		return true;
	}

void Block::addToGrid(int cel, int row, Color color)
	{
		// add new block
	}
