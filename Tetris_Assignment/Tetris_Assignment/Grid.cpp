#include "StdAfx.h"
#include "Grid.h"

Grid::Grid(Point location, Graphics^ dbGraphics, Font^ font)
	{		
		gridLocation = location;
		graphics = dbGraphics;		

		gridData = gcnew array<Cell^, 2>(N_COLS, N_ROWS);
		
		blocks = gcnew array<Point>(4);

		for(int col = 0; col < N_COLS; col++)
		{
			for(int row = 0; row < N_ROWS; row++)
			{
				gridData[col, row] = gcnew Cell(Color::FromArgb(100, Color::Black));
			}
		}
	}

void Grid::draw()
	{
		for(int col = 0; col < N_COLS; col++)
		{			
			Cell^ southWall = gridData[col, 24];
			southWall->setSolid(true);
			southWall = gridData[col, 25];
			southWall->setSolid(true);

			for(int row = 0; row < N_ROWS; row++)
			{
				Cell^ westWall = gridData[0, row];
				westWall->setSolid(true);
				westWall = gridData[1, row];
				westWall->setSolid(true);	

				Cell^ eastWall = gridData[12, row];
				eastWall->setSolid(true);
				eastWall = gridData[13, row];
				eastWall->setSolid(true);

				Cell^ cell = gridData[col, row];
				
				graphics->FillRectangle
				(
					gcnew SolidBrush((cell->isSolid()) ? cell->getColor() : Color::FromArgb(75,Color::WhiteSmoke)), 
					gridLocation.X + col * CELL_SIZE,
					gridLocation.Y + row * CELL_SIZE,
					CELL_SIZE,
					CELL_SIZE
				);

				graphics->DrawRectangle
				(
					gcnew Pen(cell->getColor(), 1), 
					gridLocation.X + col * CELL_SIZE,
					gridLocation.Y + row * CELL_SIZE,
					CELL_SIZE,
					CELL_SIZE

				);
			}
		}		
	}

void Grid::update()
	{
		for(int col = 0; col < N_COLS; col++)
		{
			for(int row = 0; row < N_ROWS; row++)
			{
				if(isRowFull(row))
				{
					deleteRow(row);
					playerScore += 100;
					playerLines++;
					if(playerScore % 100 == 0) playerLevel++;
				}					
			}
		}		
	}

void Grid::drawOneSquare(int col, int row,  Color color)
	{
		graphics->FillRectangle
		(
			gcnew SolidBrush(color), 
			gridLocation.X + col * CELL_SIZE,
			gridLocation.Y + row * CELL_SIZE,
			CELL_SIZE,
			CELL_SIZE
		);	
		
		graphics->DrawRectangle
		(
			gcnew Pen(color, 2), 
			gridLocation.X + col * CELL_SIZE,
			gridLocation.Y + row * CELL_SIZE,
			CELL_SIZE,
			CELL_SIZE

		);
	}

bool Grid::isRowFull(int rowNumber)
	{
		bool fullRow = true;
		
		for (int col = 2; col < 12; col++)
			if (!gridData[col, rowNumber]->isBlock())
				fullRow = false;

		return fullRow;						
	}

void Grid::deleteRow(int rowNumber)
	{
		int col;
		int row;

		//to delete row r, work up from that row, moving each row down one
		for (row = rowNumber; row >= 1; row--)
		{
			for (col=2; col < 12; col++)
			{
				gridData[col, row]->setSolid(gridData[col, row - 1]->isSolid());
				gridData[col, row]->setBlock(gridData[col, row - 1]->isBlock());
				gridData[col, row]->setColor(gridData[col, row - 1]->getColor());
			}
		}		
	}