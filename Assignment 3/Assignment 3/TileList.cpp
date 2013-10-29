#include "StdAfx.h"
#include "TileList.h"

TileList::TileList()
	{				
		//===================================================================
		// Populate array with tiles
		//===================================================================
		tiles = gcnew array<Tile^>(5);

		for(int t = 0; t < tiles->Length; t++)
			tiles[t] = gcnew Tile(gcnew Bitmap("bg" + t + ".png"), true);		
	}

Bitmap^ TileList::getTileBitmap(int index)
	{
		//===================================================================
		// Return bitmap of a indexed tile
		//===================================================================
		Bitmap^ tileBitmap = tiles[index]->getTileBitmap();

		return tileBitmap;
	}
