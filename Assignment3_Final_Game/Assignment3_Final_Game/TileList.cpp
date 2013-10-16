#include "StdAfx.h"
#include "TileList.h"

TileList::TileList()
	{
		Bitmap^ air = gcnew Bitmap("0.png");
		Bitmap^ ground = gcnew Bitmap("1.png");		

		//===================================================================
		// Populate array with tiles
		//===================================================================
		tiles = gcnew array<Tile^>
		{
			gcnew Tile(air, true),
			gcnew Tile(ground, false)
		};
	}

Bitmap^ TileList::getTileBitmap(int index)
	{
		//===================================================================
		// Return bitmap of a indexed tile
		//===================================================================
		Bitmap^ tileBitmap = tiles[index]->getTileBitmap();

		return tileBitmap;
	}
