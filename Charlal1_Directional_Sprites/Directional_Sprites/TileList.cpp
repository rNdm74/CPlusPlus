#include "StdAfx.h"
#include "TileList.h"

TileList::TileList()
	{		
		Bitmap^ flowerTile = gcnew Bitmap("Flower Tile 32.bmp");
		Bitmap^ grassTile =  gcnew Bitmap("Dry Grass Tile 32.bmp");
		Bitmap^ cobblestoneTile = gcnew Bitmap("Cobblestones Tile 32.bmp");		

		//===================================================================
		// Populate array with tiles
		//===================================================================
		tiles = gcnew array<Tile^>
		{			
			gcnew Tile(flowerTile, SOLID),
			gcnew Tile(grassTile, GRASS),
			gcnew Tile(cobblestoneTile, COBBLESTONE)
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
