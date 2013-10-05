#include "StdAfx.h"
#include "MapManager.h"

MapManager::MapManager(array<int, 2>^ startSpawnMap, array<int, 2>^ startCoinMap)
{
	spawnMap = startSpawnMap;	
	coinsMap = startCoinMap;
}

Point MapManager::getSpawnPosition(int spriteType, int spriteHeight)
{
	for(int col = 0; col < N_COLS; col++)
	{
		for(int row = 0; row < N_ROWS; row++)
		{
			if(spawnMap[row, col] == spriteType)
			{
				int xPos = (col * T_SIZE);
				int yPos = ((row + 1) * T_SIZE) - spriteHeight; // +1 so the the correct row is picked

				return Point(xPos, yPos);
			}
		}
	}

	return Point(0,0);	
}

void MapManager::addCoinsToGame(TileMap^ tileMap)
{
	for(int col = 0; col < N_COLS; col++)
	{
		for(int row = 0; row < N_ROWS; row++)
		{
			int coin = coinsMap[row, col];

			if(coin != 0)
				tileMap->setMapValue(col, row, coin);
		}
	}
}
