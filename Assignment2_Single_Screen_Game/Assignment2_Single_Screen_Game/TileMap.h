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
/// Summary for Sprite
///
///	   Note: If you change the name of this class, you will need to change the
///          'Resource File Name' property for the managed resource compiler tool
///          associated with all .resx files this class depends on.  Otherwise,
///          the designers will not be able to interact properly with localized
///          resources associated with this form.
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

		void generateTileMap();		

		void drawTileMap();

		void setMapValue(int col, int row, int tileValue);

		int getMapValue(int col, int row);

		ETileType getTileType(int row, int col)		{ return tiles->getTileType(tileMap[row, col]); }

		bool isSolid(int row, int col)				{ return tiles->isSolid(tileMap[row, col]); }
		bool isClimbable(int row, int col)			{ return tiles->isClimbable(tileMap[row, col]); }
		bool isWalkable(int row, int col)			{ return tiles->isWalkable(tileMap[row, col]); }
		bool isCoin(int row, int col)				{ return tiles->isCoin(tileMap[row, col]); }
		bool isExit(int row, int col)				{ return tiles->isExit(tileMap[row, col]); }
		
		Bitmap^ getTileBitmap(int row, int col)		{ return tiles->getTileBitmap(tileMap[row, col]); }

		Rectangle getBounds()					{ return Rectangle(0, 0, T_SIZE * N_COLS, T_SIZE * N_ROWS); }
	};
