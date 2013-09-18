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

void Viewport::canViewportMove(int xMove, int yMove)
{
	//converts back into pixels
	int boundsX = (N_COLS * T_SIZE) - (viewportTilesWide * T_SIZE);
	int boundsY = (N_ROWS * T_SIZE) - (viewportTilesHigh * T_SIZE);
	
	if(xMove < boundsX && xMove > 0)
		viewportWorldX = xMove;

	if(yMove < boundsY && yMove > 0)
		viewportWorldY = yMove;
}

void Viewport::moveRelativeToPlayer(int playerWorldX, int playerWorldY)
{
	int newViewportWorldX = playerWorldX - ((viewportTilesWide * T_SIZE) / 2);
	int newViewportWorldY = playerWorldY - ((viewportTilesHigh * T_SIZE) / 2);

	canViewportMove(newViewportWorldX, newViewportWorldY);
}


void Viewport::viewportDraw(int playerWorldX, int playerWorldY)
{
	int startTileColumn = viewportWorldX / T_SIZE;	
	int startTileRow = viewportWorldY / T_SIZE;

	int offsetX = viewportWorldX % T_SIZE;
	int offsetY = viewportWorldY % T_SIZE;	

	for(int col = startTileColumn; col < startTileColumn + V_COLS; col++)
	{
		for(int row = startTileRow; row < startTileRow + V_ROWS; row++)
		{			
			Bitmap^ tileBitmap = backgroundMap->getTileBitmap(row, col);			

			int screenX = (col - startTileColumn) * T_SIZE - offsetX;
			int screenY = (row - startTileRow) * T_SIZE - offsetY;

			canvas->DrawImage(tileBitmap, screenX, screenY);

			// shows solid tiles
			/*ETileType tileType = backgroundMap->getTileType(row, col);
			if(tileType == SOLID)
				canvas->FillRectangle(Brushes::Black, screenX, screenY, T_SIZE, T_SIZE);*/

			//// show tile player is on
			//int x = playerWorldX / T_SIZE;
			//int y = playerWorldY / T_SIZE;

			//if(x == col && y == row)
			//{
			//	canvas->FillRectangle(Brushes::Blue, screenX, screenY, T_SIZE, T_SIZE);

			//	if(tileType == SOLID)
			//	{
			//		canvas->FillRectangle(Brushes::Red, screenX, screenY, T_SIZE, T_SIZE);					
			//	}
			//}
			//// show tile values
			//String^ t = (col + "," + row);
			//canvas->DrawString(t, gcnew Font("Microsoft Sans Serif", 8), Brushes::White, col * T_SIZE,row * T_SIZE);
		}
	}
}

Rectangle Viewport::getViewportBounds()
{
	int vWidth = viewportTilesWide * T_SIZE;
	int vHeight = viewportTilesHigh * T_SIZE;
	
	return Rectangle(0, 0, vWidth, vHeight); 
}