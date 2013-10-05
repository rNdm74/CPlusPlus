#include "StdAfx.h"
#include "Viewport.h"

Viewport::Viewport(int startX, int startY, int startTilesWide, int startTilesHigh, TileMap^ startBackgroundMap, Graphics^ startCanvas)
{
	viewportWorldX = startX;
	viewportWorldY = startY;
	viewportTilesWide = startTilesWide;
	viewportTilesHigh = startTilesHigh;
	backgroundMap = startBackgroundMap;
	canvas = startCanvas;
	move = true;
}
//
// Checks if the viewport can move
//
void Viewport::canViewportMove(int xMove, int yMove)
{
	//converts back into pixels
	int boundsX = (N_COLS * T_SIZE) - (viewportTilesWide * T_SIZE);
	int boundsY = (N_ROWS * T_SIZE) - (viewportTilesHigh * T_SIZE);
	
	// if the viewport is with bounds allow the viewport to move
	if(xMove < boundsX && xMove > 0)
		viewportWorldX = xMove;

	if(yMove < boundsY && yMove > 0)
		viewportWorldY = yMove;

	
}
//
// If scrolling tilemap the viewport will move based on the player
//
void Viewport::moveRelativeToPlayer(int playerWorldX, int playerWorldY)
{
	// Creates a point that the view port will be drawn to based on the players position
	// with teh player in the centre
	int newViewportWorldX = playerWorldX - ((viewportTilesWide * T_SIZE) / 2);
	int newViewportWorldY = playerWorldY - ((viewportTilesHigh * T_SIZE) / 2);

	// Gets the viewport width 
	int viewportWidth = (N_COLS * T_SIZE) - (viewportTilesWide * T_SIZE);
	int viewportHeight = (N_ROWS * T_SIZE) - (viewportTilesHigh * T_SIZE);

	// Checks if viewport can move
	if(newViewportWorldX < viewportWidth && newViewportWorldX > 0)
		viewportWorldX = newViewportWorldX;
	if(newViewportWorldY < viewportHeight && newViewportWorldY > 0)
		viewportWorldY = newViewportWorldY;

	// Sets viewport to wrap when player moves from west to east
	if(playerWorldX > (N_COLS * T_SIZE) - OFFSET)
		viewportWorldX = viewportWidth;

	// Sets viewport to wrap when player moves from east to west
	if(playerWorldX < OFFSET)
		viewportWorldX = 0;

	// Sets viewport to wrap when player moves from south to north
	if(playerWorldY > (N_ROWS * T_SIZE) - OFFSET)
		viewportWorldY = viewportHeight;

	// Sets viewport to wrap when player moves from north to south
	if(playerWorldY < OFFSET)
		viewportWorldY = 0;	
}
//
// Draws the tilemap to the form
//
void Viewport::viewportDraw(int playerWorldX, int playerWorldY)
{
	// converts viewport world location to tile
	int startTileColumn = viewportWorldX / T_SIZE;	
	int startTileRow = viewportWorldY / T_SIZE;

	// get the remainder when the viewport world location is devided by the tile size
	int offsetX = viewportWorldX % T_SIZE;
	int offsetY = viewportWorldY % T_SIZE;	

	// loop through all the tiles on the viewport 
	// it gets the correct tile bitmap and then draws it to screenX and screenY
	for(int col = startTileColumn; col < startTileColumn + viewportTilesWide; col++)
	{
		for(int row = startTileRow; row < startTileRow + viewportTilesHigh; row++)
		{			
			Bitmap^ tileBitmap = backgroundMap->getTileBitmap(row, col);			

			// converts tiles back to pixels
			int screenX = (col - startTileColumn) * T_SIZE - offsetX;
			int screenY = (row - startTileRow) * T_SIZE - offsetY;

			// Draws tile to the screen
			canvas->DrawImage(tileBitmap, screenX, screenY);
		}
	}
}

Rectangle Viewport::getViewportBounds()
{
	// Returns the dimensions of the viewport
	int vWidth = viewportTilesWide * T_SIZE;
	int vHeight = viewportTilesHigh * T_SIZE;
	
	return Rectangle(0, 0, vWidth, vHeight); 
}