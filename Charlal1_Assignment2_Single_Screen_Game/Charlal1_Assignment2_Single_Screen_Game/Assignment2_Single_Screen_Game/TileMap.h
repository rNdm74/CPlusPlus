#pragma once

#include "Constants.h"
#include "TileList.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

/// <summary>
/// Summary for TileMap
///
///	   Note: The Tile map manages all the tiles that are drawn to the screen
///			 It also is the start of a chain of flags that are used 
///			 to access the different tile types
/// </summary>

ref class TileMap
	{
	private:
		array<int, 2>^ tileMap;

		TileList^ tiles;

		Graphics^ canvas;

		Random^ rGen;

		int xPos;
		int yPos;

		int xDirection;
		int yDirection;

	public:
		TileMap(Graphics^ panelCanvas, array<int, 2>^ startTileMap);

		void generateTileMap();	// Redundant	

		void drawTileMap();

		void setMapValue(int col, int row, int tileValue);
		int getMapValue(int col, int row);		

		// Flags chain
		bool isSolid(int row, int col)				{ return tiles->isSolid(tileMap[row, col]); }
		bool isClimbable(int row, int col)			{ return tiles->isClimbable(tileMap[row, col]); }
		bool isWalkable(int row, int col)			{ return tiles->isWalkable(tileMap[row, col]); }
		bool isCoin(int row, int col)				{ return tiles->isCoin(tileMap[row, col]); }
		bool isLadderCoin(int row, int col)			{ return tiles->isLadderCoin(tileMap[row, col]); }
		bool isExit(int row, int col)				{ return tiles->isExit(tileMap[row, col]); }

		ETileType getTileType(int row, int col)		{ return tiles->getTileType(tileMap[row, col]); }		
		Bitmap^ getTileBitmap(int row, int col)		{ return tiles->getTileBitmap(tileMap[row, col]); }

		Rectangle getBounds()						{ return Rectangle(0, 0, T_SIZE * N_COLS, T_SIZE * N_ROWS); }
	};
