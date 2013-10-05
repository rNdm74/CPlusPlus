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
/// Summary for ObjectMap
///
///	   Note: The Object Map takes the maps loaded by the CSV Reader and then gets 
///			 the item spawn position from the maps.
///
/// </summary>

ref class SpawnMap
{
private:
	array<int, 2>^ spawnMap;
	array<int, 2>^ coinsMap;

public:
	SpawnMap(array<int, 2>^ startSpawnMap, array<int, 2>^ startCoinMap);

	void addCoinsToGame(TileMap^ tileMap);
	
	Point getSpawnPosition(int spriteType, int spriteHeight);	

	//array<int, 2>^ getCoinMap() { return coinsMap; }
};
