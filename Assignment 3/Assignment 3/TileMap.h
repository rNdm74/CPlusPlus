#pragma once
#include "TileList.h"
#include "Constants.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

//#define N_COLS 60	// X Tiles
//#define N_ROWS 30 	// Y tiles
//#define N_TILES 3	// Tiles array size
//#define T_SIZE 32	// Tile bitmap size

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

		void generateTileMap();		

		void drawTileMap();

		void setMapValue(int col, int row, int tileValue);

		int getMapValue(int col, int row);
		
		bool isWalkable(int row, int col)			{ return tiles->isWalkable(tileMap[row, col]); }

		Bitmap^ getTileBitmap(int row, int col)		{ return tiles->getTileBitmap(tileMap[row, col]); }

		Rectangle getMapBounds()					{ return Rectangle(0, 0, T_WIDTH * N_COLS, T_HEIGHT * N_ROWS); }
	};
