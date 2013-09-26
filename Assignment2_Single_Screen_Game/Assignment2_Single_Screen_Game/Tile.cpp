#include "StdAfx.h"
#include "Tile.h"

Tile::Tile(Bitmap^ startTileBitmap, ETileType startTileType)
{
	tileBitmap = startTileBitmap;
	tileType = startTileType;

	switch(tileType)
	{
		case SOLID:
			solid = true;
			break;
		case GRASS:
			grass = true;
			break;
		case COBBLESTONE:
			cobblestone = true;
			break;
	}
}
