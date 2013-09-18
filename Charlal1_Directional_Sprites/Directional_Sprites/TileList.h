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
		array<Tile^>^ tiles;

	public:
		TileList();
		
		Bitmap^ getTileBitmap(int index);

		ETileType getTileType(int index)		{ return tiles[index]->getTileType(); }

		void setTile(int index, Tile^ newTile)	{ tiles[index] = newTile;  }
	};
