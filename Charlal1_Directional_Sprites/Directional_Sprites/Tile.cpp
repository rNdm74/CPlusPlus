#include "StdAfx.h"
#include "Tile.h"

Tile::Tile(Bitmap^ startTileBitmap, ETileType startTileType)
{
	tileBitmap = startTileBitmap;
	tileType = startTileType;
}
