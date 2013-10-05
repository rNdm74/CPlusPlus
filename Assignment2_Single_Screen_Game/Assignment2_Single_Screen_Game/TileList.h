#pragma once

#include "Constants.h"
#include "Tile.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

/// <summary>
/// Summary for Sprite
///
///	   Note: Holds an array that is used by the tilemap
///
/// </summary>

ref class TileList
	{
	private:
		array<Bitmap^>^ tileBitmaps;
		array<Tile^>^ tiles;
		array<ETileType>^ tileType;

	public:
		TileList();
		
		Bitmap^ getTileBitmap(int index);

		ETileType getTileType(int index)		{ return tiles[index]->getTileType(); }

		bool isSolid(int index)					{ return tiles[index]->isSolid(); }
		bool isClimbable(int index)				{ return tiles[index]->isClimbable(); }
		bool isWalkable(int index)				{ return tiles[index]->isWalkable(); }
		bool isCoin(int index)					{ return tiles[index]->isCoin(); }
		bool isExit(int index)					{ return tiles[index]->isExit(); }

		void setTile(int index, Tile^ newTile)	{ tiles[index] = newTile;  }
	};
