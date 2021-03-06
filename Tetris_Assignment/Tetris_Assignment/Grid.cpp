#include "StdAfx.h"
#include "Grid.h"


Grid::Grid(ResourceManager^ rm, Point location, Graphics^ dbGraphics, int cols, int rows)
	{		
		gridLocation = location;
		graphics = dbGraphics;
		N_COLS = cols;
		N_ROWS = rows;

		vel = 0;
		posY = 0;

		gridData = gcnew array<Cell^, 2>(N_COLS, N_ROWS);
		
		wall = (Image^)rm->GetObject("W");//Image::FromFile("W.png");

		for(int col = 0; col < N_COLS; col++)
		{
			for(int row = 0; row < N_ROWS; row++)
			{
				gridData[col, row] = gcnew Cell(Color::FromArgb(199, Color::Gray));
			}
		}
	}

Grid::Grid(ResourceManager^ rm, Point location, Graphics^ dbGraphics, Sound^ sound, int cols, int rows)
	{		
		gridLocation = location;
		graphics = dbGraphics;	
		gSound = sound;

		N_COLS = cols;
		N_ROWS = rows;

		vel = 0;
		posY = 0;

		gridData = gcnew array<Cell^, 2>(N_COLS, N_ROWS);
		
		wall = (Image^)rm->GetObject("W");//Image::FromFile("W.png");

		for(int col = 0; col < N_COLS; col++)
		{
			for(int row = 0; row < N_ROWS; row++)
			{
				gridData[col, row] = gcnew Cell(Color::FromArgb(199, Color::Gray));
			}
		}
	}

void Grid::update()
	{	
		// Overridden
	}

void Grid::draw()
	{
		for(int col = 1; col < N_COLS-1; col++)
		{			
			Cell^ southWall = gridData[col, N_ROWS-2];
			southWall->setSolid(true);
			southWall = gridData[col, N_ROWS-1];
			southWall->setSolid(true);

			for(int row = 3; row < N_ROWS-1; row++)
			{
				Cell^ westWall = gridData[0, row];
				westWall->setSolid(true);
				westWall = gridData[1, row];
				westWall->setSolid(true);	

				Cell^ eastWall = gridData[N_COLS - 2, row];
				eastWall->setSolid(true);
				eastWall = gridData[N_COLS - 1, row];
				eastWall->setSolid(true);

				Cell^ cell = gridData[col, row];
				
				if(cell->isSolid())
				{
					graphics->DrawImage
					(
						wall, 
						gridLocation.X + col * CELL_SIZE,
						gridLocation.Y + row * CELL_SIZE,
						CELL_SIZE,
						CELL_SIZE
					);

					graphics->FillRectangle
					(
						gcnew SolidBrush(Color::FromArgb(199, Color::Black)), 
						gridLocation.X + col * CELL_SIZE,
						gridLocation.Y + row * CELL_SIZE,
						CELL_SIZE,
						CELL_SIZE
					);
				}
					
				if(cell->isTetrimino())
				{
					graphics->FillRectangle
					(
						gcnew SolidBrush(cell->getColor()), 
						gridLocation.X + col * CELL_SIZE,
						gridLocation.Y + row * CELL_SIZE,
						CELL_SIZE,
						CELL_SIZE
					);
				}
			}
		}		
	}

void Grid::drawOneSquare(int col, int row,  Color color, Image^ image)
	{
		if(row > 2)
		{
			graphics->DrawImage
			(
				image, 
				gridLocation.X + col * CELL_SIZE,
				gridLocation.Y + row * CELL_SIZE,
				CELL_SIZE,
				CELL_SIZE

			);

			graphics->FillRectangle
			(
				gcnew SolidBrush(color), 
				gridLocation.X + col * CELL_SIZE,
				gridLocation.Y + row * CELL_SIZE,
				CELL_SIZE,
				CELL_SIZE
			);
		}		
	}

bool Grid::isRowFull(int rowNumber)
	{
		return false;							
	}

void Grid::deleteRow(int rowNumber)
	{	
		// Overridden
	}