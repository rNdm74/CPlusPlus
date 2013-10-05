#include "StdAfx.h"
#include "Tile.h"

Tile::Tile(Bitmap^ startTileBitmap, ETileType startTileType)
{
	tileBitmap = startTileBitmap;
	tileType = startTileType;

	// Sets flags for different tiles
	switch(tileType)
	{
		case LADDER:
			climb = true;
			break;

		case WALKABLE:
			walkable = true;
			break;

		case EXIT:
			exit = true;
			break;

		case LADDER_COIN:
			climb = true;
			break;

		case COIN:
			coin = true;
			break;

		case SOLID:
			solid = true;
			break;
	}
}
