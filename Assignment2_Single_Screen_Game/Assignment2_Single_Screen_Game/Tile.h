#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

/// <summary>
/// Summary for Tile
///
///	   Note: If you change the name of this class, you will need to change the
///          'Resource File Name' property for the managed resource compiler tool
///          associated with all .resx files this class depends on.  Otherwise,
///          the designers will not be able to interact properly with localized
///          resources associated with this form.
/// </summary>

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
