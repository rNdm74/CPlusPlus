#pragma once

#include "TileMap.h"

#define V_COLS 26
#define V_ROWS 19
#define OFFSET 100
 
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