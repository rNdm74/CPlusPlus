#pragma once

#include "TileMap.h"

#define V_COLS 21
#define V_ROWS 15
 
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

	void checkViewportCanMove();
	
	void viewportMove(int xMove, int yMove);
	void viewportUpdate();
	void viewportDraw();

	int getViewportWorldX()	{ return viewportWorldX; }
	int getViewportWorldY()	{ return viewportWorldY; }

	void setMove(bool m)	{ move = m; }
};
