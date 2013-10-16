#pragma once

#include "Constants.h"
#include "TileMap.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

/// <summary>
/// Summary for MapManager
///
///	   Note: The MapManager takes the maps loaded by the CSV Reader and then gets 
///			 the item spawn position from the maps.
///
/// </summary>

ref class MapManager
{
private:
	array<int, 2>^ spawnMap;
	array<int, 2>^ coinsMap;

public:
	MapManager(array<int, 2>^ startSpawnMap, array<int, 2>^ startCoinMap);

	void addCoinsToGame(TileMap^ tileMap);
	
	Point getSpawnPosition(int spriteType, int spriteHeight);
};
