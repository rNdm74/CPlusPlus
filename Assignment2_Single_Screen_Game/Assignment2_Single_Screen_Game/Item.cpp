#include "StdAfx.h"
#include "Item.h"

Item::Item(TileMap^ startTileMap, EBoundsAction startAction, 
			   Graphics^ startCanvas, String^ filename, 
			   int nFrames, Random^ startRGen, Point startPos, 
			   Viewport^ startViewPort)
	   : Sprite(startTileMap, startAction, startCanvas, filename, 
				 nFrames, startRGen, startPos, startViewPort)
{

	coin = true;
	flag = true;

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
			},
			{
				{0,0,70,70},
				{70,0,70,70}
			}
		};

	frameWidth = sheetData[bearing, currentFrame, 2];
	frameHeight = sheetData[bearing, currentFrame, 3];

	frameDelay = 4;
}
