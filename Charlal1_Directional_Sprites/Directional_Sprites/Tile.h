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
		GRASS = 1,
		COBBLESTONE = 2
	};

ref class Tile
{
private:
	Bitmap^ tileBitmap;
	ETileType tileType;
public:
	Tile(Bitmap^ startTileBitmap, ETileType startTileType);

	ETileType getTileType() { return tileType; }
	Bitmap^ getTileBitmap() { return tileBitmap; }
};
