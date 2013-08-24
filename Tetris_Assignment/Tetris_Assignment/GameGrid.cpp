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
					SoundPlayer^ player = gcnew SoundPlayer();
					player->SoundLocation = "SFX_SpecialLineClearTriple.wav";
					player->Load();
					player->Play();

					deleteRow(row);
					combo++;
					playerLines++;

					playerScore += (40 * combo) * (playerLevel + 1);
					
					
					if(playerScore % 1000 == 0)
					{
						SoundPlayer^ player = gcnew SoundPlayer();
						player->SoundLocation = "SFX_LevelUp.wav";
						player->Load();
						player->Play();
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