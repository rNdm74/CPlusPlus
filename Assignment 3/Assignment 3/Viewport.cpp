#include "StdAfx.h"
#include "Viewport.h"

Viewport::Viewport(int startX, int startY, int startTilesWide, int startTilesHigh, TileMap^ startBackgroundMap, Graphics^ startCanvas)
{
	viewportWorldX = startX; 
	viewportWorldY = startY; 
	viewportTilesWide = startTilesWide;  // V_COLS
	viewportTilesHigh = startTilesHigh;  // V_ROWS
	backgroundMap = startBackgroundMap;
	canvas = startCanvas;
}

void Viewport::canViewportMove(int xMove, int yMove)
{
	//converts back into pixels
	int boundsX = (N_COLS * T_WIDTH) - (viewportTilesWide * T_WIDTH);
	int boundsY = (N_ROWS * T_HEIGHT) - (viewportTilesHigh * T_HEIGHT);
	
	// if the viewport is with bounds allow the viewport to move
	if(xMove < boundsX && xMove > 0)
		viewportWorldX = xMove;

	if(yMove < boundsY && yMove > 0)
		viewportWorldY = yMove;	
}

void Viewport::moveRelativeToPlayer(int playerWorldX, int playerWorldY)
{
	// Creates a point that the view port will be drawn to based on the players position
	// with teh player in the centre
	int newViewportWorldX = playerWorldX - ((viewportTilesWide * T_WIDTH) / 2);
	int newViewportWorldY = playerWorldY - ((viewportTilesHigh * T_HEIGHT) / 2);

	// Gets the viewport width 
	int viewportWidth = (N_COLS * T_WIDTH) - (viewportTilesWide * T_WIDTH);
	int viewportHeight = (N_ROWS * T_HEIGHT) - (viewportTilesHigh * T_HEIGHT);

	

	// Checks if viewport can move
	if(newViewportWorldX < viewportWidth && newViewportWorldX > 0)
		viewportWorldX = newViewportWorldX;
	if(newViewportWorldY < viewportHeight && newViewportWorldY > 0)
		viewportWorldY = newViewportWorldY;

	// Sets viewport to wrap when player moves from west to east
	if(playerWorldX > (N_COLS * T_WIDTH) - OFFSET)
		viewportWorldX = viewportWidth;

	// Sets viewport to wrap when player moves from east to west
	if(playerWorldX < OFFSET)
		viewportWorldX = 0;

	// Sets viewport to wrap when player moves from south to north
	if(playerWorldY > (N_ROWS * T_HEIGHT) - OFFSET)
		viewportWorldY = viewportHeight;

	// Sets viewport to wrap when player moves from north to south
	if(playerWorldY < OFFSET)
		viewportWorldY = 0;	
}


void Viewport::viewportDraw()
{
	// converts viewport world location to tile
	int startTileColumn = viewportWorldX / T_WIDTH;	
	int startTileRow = viewportWorldY / T_HEIGHT;

	// get the remainder when the viewport world location is devided by the tile size
	int offsetX = viewportWorldX % T_WIDTH;
	int offsetY = viewportWorldY % T_HEIGHT;	

	// loop through all the tiles on the viewport 
	// it gets the correct tile bitmap and then draws it to screenX and screenY
	for(int col = startTileColumn; col < startTileColumn + viewportTilesWide; col++)
	{
		for(int row = startTileRow; row < startTileRow + viewportTilesHigh; row++)
		{			
			Bitmap^ tileBitmap = backgroundMap->getTileBitmap(row, col);			

			// converts tiles back to pixels
			int screenX = (col - startTileColumn) * T_WIDTH - offsetX;
			int screenY = (row - startTileRow) * T_HEIGHT - offsetY;

			canvas->DrawImageUnscaledAndClipped(tileBitmap, Rectangle(screenX, screenY, T_WIDTH, T_HEIGHT));
		}
	}
}

Rectangle Viewport::getViewportBounds()
{
	// Returns the dimensions of the viewport
	int vWidth = viewportTilesWide * T_WIDTH;
	int vHeight = viewportTilesHigh * T_HEIGHT;
	
	return Rectangle(0, 0, vWidth, vHeight); 
}