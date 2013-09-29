#pragma once

#include "TileMap.h"

/// <summary>
/// Summary for Sprite
///
///	   Note: If you change the name of this class, you will need to change the
///          'Resource File Name' property for the managed resource compiler tool
///          associated with all .resx files this class depends on.  Otherwise,
///          the designers will not be able to interact properly with localized
///          resources associated with this form.
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
