#include "StdAfx.h"
#include "Item.h"

Item::Item(TileMap^ startTileMap, EBoundsAction startAction, 
			   Graphics^ startCanvas, array<String^>^ filenames, 
			   int nFrames, Random^ startRGen, Point startPos, 
			   Viewport^ startViewPort)
	   : Sprite(startTileMap, startAction, startCanvas, filenames, 
				 nFrames, startRGen, startPos, startViewPort)
{
	sheetData = gcnew array<int, 3>
		{
			{
				{0,0,70,70},
				{70,0,70,70}
			},
			{
				{0,0,70,70},
				{70,0,70,70}
			},
			{
				{0,0,70,70},
				{70,0,70,70}
			},
			{
				{0,0,70,70},
				{70,0,70,70}
			}
		};

	frameWidth = sheetData[bearing, currentFrame, 2];
	frameHeight = sheetData[bearing, currentFrame, 3];

	frameDelay = 4;

	flag = true;
}
