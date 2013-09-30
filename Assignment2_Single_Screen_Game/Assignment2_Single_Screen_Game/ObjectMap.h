#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

/// <summary>
/// Summary for ObjectMap
///
///	   Note: The Object Map takes the maps loaded by the CSV Reader and then gets 
///			 the item spawn position from the maps.
///
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
