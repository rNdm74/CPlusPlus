#pragma once

#include "Tile.h"
#include "Constants.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class TileList
	{
	private:
		array<Tile^>^ tiles;
		array<ETileType>^ tileType;

	public:
		TileList();
		
		Bitmap^ getTileBitmap(int index);

		bool isSolid(int index)					{ return tiles[index]->isSolid(); }
		bool isClimbable(int index)				{ return tiles[index]->isClimbable(); }
		bool isWalkable(int index)				{ return tiles[index]->isWalkable(); }
		bool isCoin(int index)					{ return tiles[index]->isCoin(); }
		bool isLadderCoin(int index)			{ return tiles[index]->isLadderCoin(); }
		bool isExit(int index)					{ return tiles[index]->isExit(); }

		ETileType getTileType(int index)		{ return tiles[index]->getTileType(); }

		void setTile(int index, Tile^ newTile)	{ tiles[index] = newTile;  }
	};
