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

	bool walkable;

public:
	Tile(Bitmap^ startTileBitmap, bool startWalkable);

	bool isWalkable()		{ return walkable; }

	Bitmap^ getTileBitmap() { return tileBitmap; }
};
