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
		case LADDER:
			climb = true;
			break;
		case LADDER_COIN:
			climb = true;
			break;
	}
}
