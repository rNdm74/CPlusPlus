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
	int boundsX = (N_COLS * T_SIZE) - (V_COLS * T_SIZE);
	int boundsY = (N_ROWS * T_SIZE) - (V_ROWS * T_SIZE);

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
	checkViewportCanMove();

	viewportWorldX += 2 * directionX;
	viewportWorldY += 2 * directionY;	
}

void Viewport::viewportMove(int xMove, int yMove)
{
	directionX = xMove;
	directionY = yMove;
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
