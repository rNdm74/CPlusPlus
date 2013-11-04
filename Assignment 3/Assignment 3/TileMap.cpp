#include "StdAfx.h"
#include "TileMap.h"

TileMap::TileMap(Graphics^ panelCanvas,  array<int, 2>^ startTileMap)
	{
		canvas = panelCanvas;

		tiles = gcnew TileList();

		tileMap = startTileMap;	
	}

void TileMap::generateTileMap()
	{
		//===================================================================
		// Generate map of random tiles // REDUNDANT
		//===================================================================
	}

void TileMap::drawTileMap()
	{
		//===================================================================
		// Draw tile bitmap to canvas //(REDUNDANT HANDLED BY THE VIEWPORT)
		//===================================================================
		for(int col = 0; col < N_COLS; col++)
		{
			for(int row = 0; row < N_ROWS; row++)
			{
				Bitmap^ tileImage = tiles->getTileBitmap(tileMap[row, col]);

				int x = (row * T_WIDTH);
				int y = (col * T_HEIGHT);

				canvas->DrawImageUnscaledAndClipped(tileImage, Rectangle(x, y, T_WIDTH, T_HEIGHT)); 				 
			}
		}
	}

void TileMap::setMapValue(int col, int row, int tileValue)
	{
		//===================================================================
		// Return bitmap of a indexed tile
		//===================================================================
		tileMap[col, row] = tileValue;
	}

int TileMap::getMapValue(int col, int row)
	{
		//===================================================================
		// Return bitmap of a indexed tile
		// the row and col are reversed because of the way
		// the tile map is read into the game
		//===================================================================		
		return tileMap[row, col]; 
	}