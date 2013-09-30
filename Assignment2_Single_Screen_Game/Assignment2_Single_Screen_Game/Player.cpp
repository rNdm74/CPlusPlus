#include "StdAfx.h"
#include "Player.h"

Player::Player(TileMap^ startTileMap, EBoundsAction startAction, 
			   Graphics^ startCanvas, String^ filename, 
			   int nFrames, Random^ startRGen, Point startPos, 
			   Viewport^ startViewPort, ESprite startSprite)
	   : Sprite(startTileMap, startAction, startCanvas, filename, 
				 nFrames, startRGen, startPos, startViewPort, startSprite)
	{
		xMag = 8;
		yMag = 10;

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

		frameWidth = sheetData[bearing, currentFrame, WIDTH];
		frameHeight = sheetData[bearing, currentFrame, HEIGHT];
	}


