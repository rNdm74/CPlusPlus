#pragma once
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
///	   Note: If you change the name of this class, you will need to change the
///          'Resource File Name' property for the managed resource compiler tool
///          associated with all .resx files this class depends on.  Otherwise,
///          the designers will not be able to interact properly with localized
///          resources associated with this form.
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

		void setTile(int index, Tile^ newTile)	{ tiles[index] = newTile;  }
	};
