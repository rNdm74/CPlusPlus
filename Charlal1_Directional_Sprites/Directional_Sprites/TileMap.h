#pragma once
#include "TileList.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

#define N_COLS 60	// X Tiles
#define N_ROWS 30 	// Y tiles
#define N_TILES 3	// Tiles array size
#define T_SIZE 32	// Tile bitmap size

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
		TileMap(Graphics^ panelCanvas);

		void generateTileMap();

		void updateTilePosition();

		void drawTileMap();

		void setMapValue(int col, int row, int tileValue);

		int getMapValue(int col, int row);

		void moveMapLeft()		{ xDirection = -1; }
		void moveMapRight()		{ xDirection = 1; }
		void moveMapUp()		{ yDirection = -1; }
		void moveMapDown()		{ yDirection = 1; }
		void mapStop()			{ xDirection = 0; yDirection = 0; }
	};
