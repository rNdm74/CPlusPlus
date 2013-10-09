#pragma once

#include "Constants.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

/// <summary>
/// Summary for Tile
///
///	   Note: The tile holds a bitmap and its type 
///			 it also holds boolean flags based on its type
///			
/// </summary>

ref class Tile
{
private:
	Bitmap^ tileBitmap;
	ETileType tileType;

	bool solid;
	bool climb;
	bool walkable;
	bool ladderCoin;
	bool coin;
	bool exit;
	

public:
	Tile(Bitmap^ startTileBitmap, ETileType startTileType);

	ETileType getTileType() { return tileType; }

	bool isSolid()			{ return solid; }
	bool isClimbable()		{ return climb; }
	bool isWalkable()		{ return walkable; }
	bool isCoin()			{ return coin; }
	bool isLadderCoin()		{ return ladderCoin; }
	bool isExit()			{ return exit; }

	Bitmap^ getTileBitmap() { return tileBitmap; }
};
