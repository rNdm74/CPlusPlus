#include "StdAfx.h"
#include "Tetrimino.h"

Tetrimino::Tetrimino(Color color, Grid^ grid, Grid^ preview)
	{	
		curPosition = nullptr;
		tetriminoColor = color;
		gameGrid = grid;
		tetriminoPreview = preview;
		orientation = EAST;
	}

void Tetrimino::moveLeft()
	{
		newPosition = lookAhead(Point(-1,0));

		if(canMove(newPosition)) move(newPosition);	

		
	}

void Tetrimino::moveRight()
	{
		newPosition = lookAhead(Point(1,0));

		if(canMove(newPosition)) move(newPosition);

		//gcnew PlaySound("SFX_PieceMoveLR.wav");
	}

void Tetrimino::moveDown()
	{
		newPosition = lookAhead(Point(0,1));

		canMove(newPosition) ? move(newPosition) : addToGrid(tetriminoColor);

		
	}

void Tetrimino::moveRotate()
	{
		array<Point>^ newPosition = gcnew array<Point>(curPosition->Length);

		for(int pos = 0; pos < newPosition->Length; pos++)
			newPosition[pos] = curPosition[pos];

		rotate(newPosition);
		
		if(canMove(newPosition))
		{
			move(newPosition);

			gcnew PlaySound("SFX_PieceRotateLR.wav");
			
			orientation++;
		}		
	}

void Tetrimino::rotate(array<Point>^ newPosition)
	{
		// NOT NEEDED
	}

void Tetrimino::move(array<Point>^ newPosition)
	{
		for(int pos = 0; pos < newPosition->Length; pos++)
				curPosition[pos] = newPosition[pos];	

		
		
	}

void Tetrimino::draw()
	{
		for(int pos = 0; pos < curPosition->Length; pos++)
			gameGrid->drawOneSquare
			(
				curPosition[pos].X,
				curPosition[pos].Y,
				tetriminoColor
			);
	}

void Tetrimino::drawPreview()
	{
		for(int pos = 0; pos < curPosition->Length; pos++)
			tetriminoPreview->drawOneSquare
			(
				curPosition[pos].X-4,
				curPosition[pos].Y+3,
				tetriminoColor
			);		
	}

array<Point>^ Tetrimino::lookAhead(Point direction)
	{
		array<Point>^ newPosition = gcnew array<Point>(curPosition->Length);

		for(int pos = 0; pos < newPosition->Length; pos++)
			newPosition[pos] = curPosition[pos];

		for(int i = 0; i < newPosition->Length; i++)
		{	
			newPosition[i].X += direction.X;
			newPosition[i].Y += direction.Y;
		}

		return newPosition;
	}

bool Tetrimino::canMove(array<Point>^ newPosition)
	{		
		array<bool>^ flags = gcnew array<bool>(newPosition->Length);

		for(int pos = 0; pos < newPosition->Length; pos++)
			if(gameGrid->getCell(newPosition[pos])->isSolid())
				flags[pos] = gameGrid->getCell(newPosition[pos])->isSolid();	

		for(int b = 0; b < flags->Length; b++)
			if(flags[b])return false;

		return true;
	}

void Tetrimino::addToGrid(Color color)
	{
		for(int pos = 0; pos < curPosition->Length; pos++)
		{
			Cell^ cell = gameGrid->getCell(curPosition[pos]);

			cell->setSolid(true);
			cell->setTetrimino(true);
			cell->setColor(color);
		}	

		placed = true;		

		gcnew PlaySound("SFX_PieceLockDown.wav");		
	}
