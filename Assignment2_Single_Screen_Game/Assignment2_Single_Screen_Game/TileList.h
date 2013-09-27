#pragma once
#include "Tile.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

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

		void setTile(int index, Tile^ newTile)	{ tiles[index] = newTile;  }
	};
