#include "StdAfx.h"
#include "ObjectMap.h"

ObjectMap::ObjectMap(array<int, 2>^ startObjectMap, array<int, 2>^ startCoinMap)
{
	objectMap = startObjectMap;	
	coinsMap = startCoinMap;
}

Point ObjectMap::getSpawnPosition(int spriteType, int spriteHeight)
{
	for(int col = 0; col < N_COLS; col++)
	{
		for(int row = 0; row < N_ROWS; row++)
		{
			if(objectMap[row, col] == spriteType)
			{
				int xPos = (col * T_SIZE);
				int yPos = ((row + 1) * T_SIZE) - spriteHeight; // +1 so the the correct row is picked

				return Point(xPos, yPos);
			}
		}
	}

	return Point(0,0);	
}
