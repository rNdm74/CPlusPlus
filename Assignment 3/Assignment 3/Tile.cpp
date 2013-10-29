#include "StdAfx.h"
#include "Tile.h"

Tile::Tile(Bitmap^ startTileBitmap, bool startWalkable)
{
	tileBitmap = startTileBitmap;
	walkable = startWalkable;
}
