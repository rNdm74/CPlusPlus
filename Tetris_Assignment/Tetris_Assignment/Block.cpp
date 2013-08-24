#include "StdAfx.h"
#include "Block.h"

Block::Block(Color color, Grid^ grid, Grid^ preview)
	{	
		squares = nullptr;
		blockColor = color;
		gameGrid = grid;
		blockPreview = preview;
		orientation = EAST;
		
		

		

		
	}

void Block::moveLeft()
	{
		newPosition = lookAhead(Point(-1,0));

		if(canMove(newPosition)) move(newPosition);	

		SoundPlayer^ moveSound = gcnew SoundPlayer();
		moveSound->SoundLocation = "SFX_PieceMoveLR.wav";
		moveSound->Load();
		moveSound->Play();
	}

void Block::moveRight()
	{
		newPosition = lookAhead(Point(1,0));

		if(canMove(newPosition)) move(newPosition);

		SoundPlayer^ moveSound = gcnew SoundPlayer();
		moveSound->SoundLocation = "SFX_PieceMoveLR.wav";
		moveSound->Load();
		moveSound->Play();
	}

void Block::moveDown()
	{
		newPosition = lookAhead(Point(0,1));

		canMove(newPosition) ? move(newPosition) : addToGrid(blockColor);

		/*SoundPlayer^ moveSound; = gcnew SoundPlayer();
		fallSound->SoundLocation = "SFX_PieceMoveLR.wav";
		fallSound->Load();
		fallSound->Play();*/
	}

void Block::moveRotate()
	{
		array<Point>^ newPosition = gcnew array<Point>(squares->Length);

		for(int square = 0; square < newPosition->Length; square++)
			newPosition[square] = squares[square];

		rotate(newPosition);
		
		if(canMove(newPosition))
		{
			move(newPosition);
			SoundPlayer^ rotateSound = gcnew SoundPlayer();
			rotateSound->SoundLocation = "SFX_PieceRotateLR.wav";
			rotateSound->Load();
			rotateSound->Play();
			orientation++;
		}		
	}

void Block::rotate(array<Point>^ temp)
	{
		// NOT NEEDED
	}

void Block::move(array<Point>^ temp)
	{
		for(int square = 0; square < squares->Length; square++)
				squares[square] = temp[square];	

		
		
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

void Block::drawPreview()
	{
		for(int square = 0; square < squares->Length; square++)
			blockPreview->drawOneSquare
			(
				squares[square].X-4,
				squares[square].Y+3,
				blockColor
			);		
	}

array<Point>^ Block::lookAhead(Point direction)
	{
		array<Point>^ newPosition = gcnew array<Point>(squares->Length);

		for(int square = 0; square < newPosition->Length; square++)
			newPosition[square] = squares[square];

		for(int i = 0; i < newPosition->Length; i++)
		{	
			newPosition[i].X += direction.X;
			newPosition[i].Y += direction.Y;
		}

		return newPosition;
	}

bool Block::canMove(array<Point>^ newPosition)
	{		
		array<bool>^ flags = gcnew array<bool>(newPosition->Length);

		for(int square = 0; square < newPosition->Length; square++)
			if(gameGrid->getCell(newPosition[square])->isSolid())
				flags[square] = gameGrid->getCell(newPosition[square])->isSolid();	

		for(int flag = 0; flag < flags->Length; flag++)
			if(flags[flag])return false;

		return true;
	}

void Block::addToGrid(Color color)
	{
		for(int square = 0; square < squares->Length; square++)
		{
			Cell^ cell = gameGrid->getCell(squares[square]);

			cell->setSolid(true);
			cell->setBlock(true);
			cell->setColor(color);
		}	

		placed = true;

		SoundPlayer^ touchDownSound = gcnew SoundPlayer();
		touchDownSound->SoundLocation = "SFX_PieceLockDown.wav";
		touchDownSound->Load();
		touchDownSound->Play();
	}
