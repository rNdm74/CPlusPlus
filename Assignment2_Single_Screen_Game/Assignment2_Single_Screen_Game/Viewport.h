#pragma once

#include "Constants.h"
#include "TileMap.h"

/// <summary>
/// Summary for Viewport
///
///	   Note: The viewport renders only the tiles that are visible in its space
///
/// </summary>
 
ref class Viewport
{
private:
	int viewportWorldX;
	int viewportWorldY;
	int viewportTilesWide;
	int viewportTilesHigh;

	TileMap^ backgroundMap;
	Graphics^ canvas;
	

	bool move;
	int directionX;
	int directionY;

public:
	Viewport(int startX, int startY, int startTilesWide, int startTilesHigh, TileMap^ startBackgroundMap, Graphics^ startCanvas);

	void canViewportMove(int xMove, int yMove);	
	void moveRelativeToPlayer(int playerWorldX, int playerWorldY);
	void viewportDraw(int playerWorldX, int playerWorldY);

	int getViewportWorldX()								{ return viewportWorldX; }
	int getViewportWorldY()								{ return viewportWorldY; }
	ETileType getTileType(int tileX, int tileY)			{ return backgroundMap->getTileType(tileX, tileY); }

	Rectangle getViewportBounds();
};
