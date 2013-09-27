#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

public enum ETileType
	{
		SOLID = 0,
		LADDER = 1,
		WALKABLE = 2
	};

ref class Tile
{
private:
	Bitmap^ tileBitmap;
	ETileType tileType;

	bool solid;
	bool climb;
	

public:
	Tile(Bitmap^ startTileBitmap, ETileType startTileType);

	ETileType getTileType() { return tileType; }

	bool isSolid()			{ return solid; }
	bool isClimbable()		{ return climb; }

	Bitmap^ getTileBitmap() { return tileBitmap; }
};
