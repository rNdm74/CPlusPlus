#pragma once
#include "TileList.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;



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

		ETileType getTileType(int row, int col)		{ return tiles->getTileType(tileMap[row, col]); }

		bool isSolid(int row, int col)				{ return tiles->isSolid(tileMap[row, col]); }
		bool isClimbable(int row, int col)			{ return tiles->isClimbable(tileMap[row, col]); }
		
		Bitmap^ getTileBitmap(int row, int col)		{ return tiles->getTileBitmap(tileMap[row, col]); }

		Rectangle getMapBounds()					{ return Rectangle(0, 0, T_SIZE * N_COLS, T_SIZE * N_ROWS); }
	};
