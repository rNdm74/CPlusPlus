#include "StdAfx.h"
#include "TileList.h"

TileList::TileList()
	{
		tileBitmaps = gcnew array<Bitmap^>(7);

		for(int i = 0; i < tileBitmaps->Length; i++)
		{
			String^ file = "Images/" + i + ".png";
			tileBitmaps[i] = gcnew Bitmap(file);
			tileBitmaps[i]->MakeTransparent(Color::White);
		}

		tiles = gcnew array<Tile^>(tileBitmaps->Length);

		for(int i = 0; i < tiles->Length; i++)
			tiles[i] = gcnew Tile(tileBitmaps[i], SOLID);		
	}

Bitmap^ TileList::getTileBitmap(int index)
	{
		//===================================================================
		// Return bitmap of a indexed tile
		//===================================================================
		Bitmap^ tileBitmap = tiles[index]->getTileBitmap();

		return tileBitmap;
	}
