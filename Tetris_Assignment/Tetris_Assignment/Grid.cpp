#include "StdAfx.h"
#include "Grid.h"

Grid::Grid(Point location, Graphics^ dbGraphics)
	{		
		gridLocation = location;
		graphics = dbGraphics;

		gridData = gcnew array<Cell^, 2>(N_COLS,N_ROWS);
		
		brush = gcnew SolidBrush(Color::White);
		font = gcnew Font("Microsoft Sans Serif", 8);
		fontBrush = gcnew SolidBrush(Color::Black);

		blocks = gcnew array<Point>(4);

		for(int col = 0; col < N_COLS; col++)
		{
			for(int row = 0; row < N_ROWS; row++)
			{
				gridData[col, row] = gcnew Cell(Color::White);
			}
		}

		
	}

void Grid::draw()
	{
		for(int col = 0; col < N_COLS; col++)
		{			
			Cell^ southWall = gridData[col, 20];
			southWall->setSolid(true);

			for(int row = 0; row < N_ROWS; row++)
			{
				Cell^ westWall = gridData[0, row];
				westWall->setSolid(true);

				Cell^ eastWall = gridData[11, row];
				eastWall->setSolid(true);


				Cell^ cell = gridData[col, row];
				
				graphics->FillRectangle
				(
				gcnew SolidBrush((cell->isSolid()) ? cell->getColor() : Color::Black), 
					gridLocation.X + col * CELL_SIZE,
					gridLocation.Y + row * CELL_SIZE,
					CELL_SIZE,
					CELL_SIZE
				);

				

				//graphics->DrawString
				//(
				//	//col + "," + row, 
				//	"" + cell->isSolid(),
				//	font, 
				//	fontBrush, 
				//	gridLocation.X + col * CELL_SIZE, 
				//	gridLocation.Y + row * CELL_SIZE
				//);
			}
		}		
	}

void Grid::update()
	{
		
	}

void Grid::drawOneSquare(int col, int row,  Color color)
	{
		graphics->FillRectangle
		(
		gcnew SolidBrush(Color::Aquamarine), 
			gridLocation.X + col * CELL_SIZE,
			gridLocation.Y + row * CELL_SIZE,
			CELL_SIZE,
			CELL_SIZE
		);		
	}

void Grid::isRowFull()
	{
	}

void Grid::deleteRow()
	{
		
	}