#include "StdAfx.h"
#include "Tile.h"

Tile::Tile(Bitmap^ startTileBitmap, ETileType startTileType)
{
	tileBitmap = startTileBitmap;
	tileType = startTileType;

	switch(tileType)
	{
		case LADDER:
			climb = true;
		case WALKABLE:
			walkable = true;
		case EXIT:
			exit = true;
		case LADDER_COIN:
			climb = true;
		case COIN:
			coin = true;
		case SOLID:
			solid = true;
	}
}
