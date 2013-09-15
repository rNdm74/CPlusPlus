#include "StdAfx.h"
#include "Tile.h"

Tile::Tile(Bitmap^ startTileBitmap)
{
	tileBitmap = startTileBitmap;
	walkable = true;
}
