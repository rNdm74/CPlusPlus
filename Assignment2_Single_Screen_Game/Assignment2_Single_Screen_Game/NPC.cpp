#include "StdAfx.h"
#include "NPC.h"

NPC::NPC(TileMap^ startTileMap, EBoundsAction startAction, 
			   Graphics^ startCanvas, array<String^>^ filenames, 
			   int nFrames, Random^ startRGen, Point startPos, 
			   Viewport^ startViewPort)
    : Sprite(startTileMap, startAction, startCanvas, filenames, 
				 nFrames, startRGen, startPos, startViewPort)
	{
	}
