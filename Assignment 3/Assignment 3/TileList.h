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

	public:
		TileList();
		
		Bitmap^ getTileBitmap(int index);

		bool isWalkable(int index)				{ return tiles[index]->isWalkable(); }

		void setTile(int index, Tile^ newTile)	{ tiles[index] = newTile;  }
	};
