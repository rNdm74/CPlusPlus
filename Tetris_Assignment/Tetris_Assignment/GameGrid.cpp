#include "StdAfx.h"
#include "GameGrid.h"

GameGrid::GameGrid(Point location, Graphics^ dbGraphics, int cols, int rows)
		 : Grid(location, dbGraphics, cols, rows)
{
}

void GameGrid::update()
	{
		int combo = 0;

		for(int col = 0; col < N_COLS; col++)
		{
			for(int row = 0; row < N_ROWS; row++)
			{	
				

				if(isRowFull(row))
				{
					gcnew PlaySound("SFX_SpecialLineClearTriple.wav");
					
					deleteRow(row);

					combo++;
					playerLines++;

					playerScore += 100;//(40 * combo) * (playerLevel + 1);
					
					
					if(playerScore % 100 == 0)
					{
						gcnew PlaySound("SFX_LevelUp.wav");

						playerLevel++;
					}
				}	


			}
		}		
	}

bool GameGrid::isRowFull(int rowNumber)
	{
		bool fullRow = true;
		
		for (int col = 2; col < 12; col++)
			if (!gridData[col, rowNumber]->isTetrimino())
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
				gridData[col, row]->setTetrimino(gridData[col, row - 1]->isTetrimino());
				gridData[col, row]->setColor(gridData[col, row - 1]->getColor());
			}
		}		
	}