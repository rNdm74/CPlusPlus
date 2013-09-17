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

void Viewport::checkViewportCanMove()
{
	//converts back into pixels
	int boundsX = (N_COLS * T_SIZE) - (viewportTilesWide * T_SIZE);
	int boundsY = (N_ROWS * T_SIZE) - (viewportTilesHigh * T_SIZE);

	// temp bounds checking for viewport
	if(viewportWorldX < 1)
		viewportWorldX = 1;

	if(viewportWorldX > boundsX)
		viewportWorldX = boundsX;

	if(viewportWorldY < 1)
		viewportWorldY = 1;

	if(viewportWorldY > boundsY)
		viewportWorldY = boundsY;
}

void Viewport::viewportUpdate()
{
	// move check bounds
	checkViewportCanMove();

	viewportWorldX += 1 * directionX;
	viewportWorldY += 1 * directionY;	
}

void Viewport::viewportMove(int xMove, int yMove)
{
	checkViewportCanMove();

	viewportWorldX += xMove;
	viewportWorldY += yMove;
}

void Viewport::viewportDraw()
{
	int startTileColumn = viewportWorldX / T_SIZE;	
	int startTileRow = viewportWorldY / T_SIZE;

	int offsetX = viewportWorldX % T_SIZE;
	int offsetY = viewportWorldY % T_SIZE;	

	for(int col = startTileColumn; col < startTileColumn + V_COLS; col++)
	{
		for(int row = startTileRow; row < startTileRow + V_ROWS; row++)
		{			
			Bitmap^ tile = backgroundMap->getTileBitmap(row, col);			

			int screenX = (col - startTileColumn) * T_SIZE - offsetX;
			int screenY = (row - startTileRow) * T_SIZE - offsetY;

			canvas->DrawImage(tile, screenX, screenY);
		}
	}
}

Rectangle Viewport::getViewportBounds()
{
	int vWidth = viewportTilesWide * T_SIZE;
	int vHeight = viewportTilesHigh * T_SIZE;
	
	return Rectangle(viewportWorldX, viewportWorldY, vWidth, vHeight); 
}