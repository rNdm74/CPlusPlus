#include "StdAfx.h"
#include "NPC.h"

NPC::NPC(TileMap^ startTileMap, EBoundsAction startAction, 
			   Graphics^ startCanvas, String^ filename, 
			   int nFrames, Random^ startRGen, Point startPos, 
			   Viewport^ startViewPort, ESprite startSprite, int startEnemyType)
    : Sprite(startTileMap, startAction, startCanvas, filename, 
				 nFrames, startRGen, startPos, startViewPort, startSprite)
	{
		xMag = 6;
		yMag = 6;

		switch(startEnemyType)
		{
			case 1:
				setEnemyOne();
				break;
			case 2:
				setEnemyTwo();
				break;
		}

		frameWidth = sheetData[bearing, currentFrame, WIDTH];
		frameHeight = sheetData[bearing, currentFrame, HEIGHT];
	}

void NPC::setEnemyOne()
{
	sheetData = gcnew array<int, 3>
		{
			{ // North
				{438,92,67,97},
				{438,92,67,97},
				{438,92,67,97},
				{438,92,67,97},
				{438,92,67,97},
				{438,92,67,97},
				{438,92,67,97},
				{438,92,67,97},
				{438,92,67,97},
				{438,92,67,97},
				{438,92,67,97}
			},
			{ // East
				{0, 0, 72, 97},
				{73, 0, 72, 97},
				{146, 0, 72, 97},
				{0, 98, 72, 97},
				{73, 98, 72, 97},
				{146, 98, 72, 97},
				{219, 0, 72, 97},
				{292, 0, 72, 97},
				{219, 98, 72, 97},
				{365, 0, 72, 97},
				{292, 98, 72, 97}
			},
			{ // South
				{365,98,69,97},
				{365,98,69,97},
				{365,98,69,97},
				{365,98,69,97},
				{365,98,69,97},
				{365,98,69,97},
				{365,98,69,97},
				{365,98,69,97},
				{365,98,69,97},
				{365,98,69,97},
				{365,98,69,97}
			},
			{ // West
				{0, 0, 72, 97},
				{73, 0, 72, 97},
				{146, 0, 72, 97},
				{0, 98, 72, 97},
				{73, 98, 72, 97},
				{146, 98, 72, 97},
				{219, 0, 72, 97},
				{292, 0, 72, 97},
				{219, 98, 72, 97},
				{365, 0, 72, 97},
				{292, 98, 72, 97}
			},
			{ // Stand
				{67, 191, 66, 97 },
				{67, 191, 66, 97 },
				{67, 191, 66, 97 },
				{67, 191, 66, 97 },
				{67, 191, 66, 97 },
				{67, 191, 66, 97 },
				{67, 191, 66, 97 },
				{67, 191, 66, 97 },
				{67, 191, 66, 97 },
				{67, 191, 66, 97 },
				{67, 191, 66, 97 }
			}
		};
}

void NPC::setEnemyTwo()
{
	sheetData = gcnew array<int, 3>
	{
		{ // North
			{423 ,95 ,66 ,94},
			{423 ,95 ,66 ,94},
			{423 ,95 ,66 ,94},
			{423 ,95 ,66 ,94},
			{423 ,95 ,66 ,94},
			{423 ,95 ,66 ,94},
			{423 ,95 ,66 ,94},
			{423 ,95 ,66 ,94},
			{423 ,95 ,66 ,94},
			{423 ,95 ,66 ,94},
			{423 ,95 ,66 ,94},
		},
		{ // East
			{0,0,70,94},
			{71,0,70,94},
			{142,0,70,94},
			{0,95,70,94},
			{71,95,70,94},
			{142,95,70,94},
			{213,0,70,94},
			{284,0,70,94},
			{213,95,70,94},
			{355,0,70,94},
			{284,95,70,94}
		},
		{ // South
			{355,95,67 ,94},
			{355,95,67 ,94},
			{355,95,67 ,94},
			{355,95,67 ,94},
			{355,95,67 ,94},
			{355,95,67 ,94},
			{355,95,67 ,94},
			{355,95,67 ,94},
			{355,95,67 ,94},
			{355,95,67 ,94},
			{355,95,67 ,94}
		},
		{  // West
			{0,0,70,94},
			{71,0,70,94},
			{142,0,70,94},
			{0,95,70,94},
			{71,95,70,94},
			{142,95,70,94},
			{213,0,70,94},
			{284,0,70,94},
			{213,95,70,94},
			{355,0,70,94},
			{284,95,70,94}
		},
		{ // Stand
			{67, 188, 66, 94 },
			{67, 188, 66, 94 },
			{67, 188, 66, 94 },
			{67, 188, 66, 94 },
			{67, 188, 66, 94 },
			{67, 188, 66, 94 },
			{67, 188, 66, 94 },
			{67, 188, 66, 94 },
			{67, 188, 66, 94 },
			{67, 188, 66, 94 },
			{67, 188, 66, 94 }
		}
	};
}

void NPC::wander()
{
	//=================================================
	// Depending on a specified probability 
	// a random bearing is picked for the sprite
	//=================================================
	if(rGen->Next(WANDER_PROB) == 0) 
		setBearing(getRandomBearing());

	if(!walking)
		setBearing(getRandomBearing());
}
EBearing NPC::getRandomBearing()
{
	//=================================================
	// Return a random EBearing
	//=================================================
	int pick = rGen->Next(4);

	switch(pick)
	{	
		case 0:
			return WEST;
		case 1:
			return EAST;
		case 2:
			return NORTH;
		case 3:
			return SOUTH;
		/*case 4:
			return STAND;*/
	}
}