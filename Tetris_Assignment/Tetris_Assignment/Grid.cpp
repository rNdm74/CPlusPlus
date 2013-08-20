#include "StdAfx.h"
#include "Grid.h"

Grid::Grid(Point location, Graphics^ dbGraphics)
	{		
		gridLocation = location;
		graphics = dbGraphics;

		gridData = gcnew array<Cell^, 2>(N_COLS,N_ROWS);
		
		brush = gcnew SolidBrush(Color::White);

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
			for(int row = 0; row < N_ROWS; row++)
			{
				Cell^ cell = gridData[col, row];

				graphics->FillRectangle
				(
					gcnew SolidBrush(cell->getColor()), 
					gridLocation.X + col * CELL_SIZE,
					gridLocation.Y + row * CELL_SIZE,
					CELL_SIZE,
					CELL_SIZE
				);

				cell->setColor(Color::White);
				cell->setFull(false);
			}
		}		
	}

void Grid::update()
	{
		
	}

void Grid::drawOneSquare(int col, int row,  Color color)
	{	
		Cell^ cell = gridData[col, row];
		
		cell->setColor(color);
		cell->setFull(true);
	}

void Grid::isRowFull()
	{
	}

void Grid::deleteRow()
	{
	}