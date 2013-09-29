#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

/// <summary>
/// Summary for Sprite
///
///	   Note: If you change the name of this class, you will need to change the
///          'Resource File Name' property for the managed resource compiler tool
///          associated with all .resx files this class depends on.  Otherwise,
///          the designers will not be able to interact properly with localized
///          resources associated with this form.
/// </summary>

ref class ObjectMap
{
private:
	array<int, 2>^ objectMap;
	array<int, 2>^ coinsMap;

public:
	ObjectMap(array<int, 2>^ startObjectMap, array<int, 2>^ startCoinMap);
	
	Point getSpawnPosition(int spriteType, int spriteHeight);

	array<int, 2>^ getCoinMap() { return coinsMap; }
};
