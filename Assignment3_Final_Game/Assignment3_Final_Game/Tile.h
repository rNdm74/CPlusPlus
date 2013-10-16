#pragma once

#include "Constants.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

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
	Tile(Bitmap^ startTileBitmap);

	bool isSolid()			{ return solid; }
	bool isClimbable()		{ return climb; }
	bool isWalkable()		{ return walkable; }
	bool isCoin()			{ return coin; }
	bool isLadderCoin()		{ return ladderCoin; }
	bool isExit()			{ return exit; }

	ETileType getTileType() { return tileType; }
	Bitmap^ getTileBitmap() { return tileBitmap; }
};
