#include "StdAfx.h"
#include "Tetrimino.h"

Tetrimino::Tetrimino(ResourceManager^ rm, Color color, GameGrid^ grid, Grid^ preview)
	{	
		curPosition = nullptr;
		tetriminoColor = color;
		gameGrid = grid;
		tetriminoPreview = preview;
		orientation = EAST;
	}

void Tetrimino::moveLeft()
	{
		// Moves a block left
		newPosition = lookAhead(Point(-1,0));

		if(canMove(newPosition)) move(newPosition);			
	}

void Tetrimino::moveRight()
	{
		// Moves a block right
		newPosition = lookAhead(Point(1,0));

		if(canMove(newPosition)) move(newPosition);
	}

void Tetrimino::moveDown()
	{
		// Moves a block down
		newPosition = lookAhead(Point(0,1));

		// Determine if the block can move or should be placed
		canMove(newPosition) ? move(newPosition) : addToGrid(tetriminoColor);		
	}

void Tetrimino::moveRotate()
	{
		// Rotates a block in the game


		array<Point>^ newPosition = gcnew array<Point>(curPosition->Length);

		// Copy curPosition points to the newPosition array
		for(int pos = 0; pos < newPosition->Length; pos++)
			newPosition[pos] = curPosition[pos];

		// Apply the rotation to the points
		rotate(newPosition);
		
		// Check if the rotation is valid
		if(canMove(newPosition))
		{
			// Apply newPositions to curPostions
			move(newPosition);

			gameGrid->getSound()->play("SFX_PieceRotateLR");
			
			// Update the orientation enumeration
			orientation++;
		}		
	}

void Tetrimino::rotate(array<Point>^ newPosition)
	{
		// NOT NEEDED
	}

void Tetrimino::move(array<Point>^ newPosition)
	{
		// Copies the newPosition points to the curPosition points

		for(int pos = 0; pos < newPosition->Length; pos++)
				curPosition[pos] = newPosition[pos];
	}

void Tetrimino::draw()
	{
		// Loops through the curPosition array and draws it to the gameGrid

		for(int pos = 0; pos < curPosition->Length; pos++)
			gameGrid->drawOneSquare
			(
				curPosition[pos].X,
				curPosition[pos].Y,
				tetriminoColor,
				tetrimino
			);
	}

void Tetrimino::drawPreview()
	{
		// Loops through the curPosition array and draws it to the preview grid

		for(int pos = 0; pos < curPosition->Length; pos++)
			tetriminoPreview->drawOneSquare
			(
				curPosition[pos].X-4,
				curPosition[pos].Y+3,
				tetriminoColor,
				tetrimino
			);		
	}

array<Point>^ Tetrimino::lookAhead(Point direction)
	{
		// Copys the current point positions moves them to the new position 
		// returns the new points

		array<Point>^ newPosition = gcnew array<Point>(curPosition->Length);

		// Copies the curPosition array to the newPosition array
		for(int pos = 0; pos < newPosition->Length; pos++)
			newPosition[pos] = curPosition[pos];

		// Moves the newPosition points by direction
		for(int i = 0; i < newPosition->Length; i++)
		{	
			newPosition[i].X += direction.X;
			newPosition[i].Y += direction.Y;
		}

		return newPosition;
	}

bool Tetrimino::canMove(array<Point>^ newPosition)
	{
		// Return true if the any point in the newPosition array
		// wants to move to a solid blocks position

		// Creates a boolean array for each point being checked
		array<bool>^ flags = gcnew array<bool>(newPosition->Length);

		// Adds to the boolean if a point has moved to a solid block
		for(int pos = 0; pos < newPosition->Length; pos++)
			if(gameGrid->getCell(newPosition[pos])->isSolid())
				flags[pos] = gameGrid->getCell(newPosition[pos])->isSolid();	

		// Returns false if any point in the array is true
		for(int b = 0; b < flags->Length; b++)
			if(flags[b])return false;

		return true;
	}

void Tetrimino::addToGrid(Color color)
	{
		// Loop through point array and add to gamegrid
		for(int pos = 0; pos < curPosition->Length; pos++)
		{
			Cell^ cell = gameGrid->getCell(curPosition[pos]);

			cell->setSolid(true);
			cell->setTetrimino(true);
			cell->setColor(color);
			cell->setImage(tetrimino);
		}	

		placed = true;	

		gameGrid->setPlayerScore(40);		
		gameGrid->getSound()->play("SFX_PieceLockdown");		
	}
