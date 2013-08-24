#include "StdAfx.h"
#include "GameGrid.h"

GameGrid::GameGrid(Point location, Graphics^ dbGraphics, int cols, int rows)
		 : Grid(location, dbGraphics, cols, rows)
{
}

void GameGrid::update()
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

bool GameGrid::isRowFull(int rowNumber)
	{
		bool fullRow = true;
		
		for (int col = 2; col < 12; col++)
			if (!gridData[col, rowNumber]->isBlock())
				fullRow = false;

		return fullRow;						
	}

void GameGrid::deleteRow(int rowNumber)
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