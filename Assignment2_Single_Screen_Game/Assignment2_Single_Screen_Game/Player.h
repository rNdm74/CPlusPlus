#pragma once
#include "sprite.h"

ref class Player :
public Sprite
	{		
	public:
		Player(TileMap^ startTileMap, EBoundsAction startAction, 
			   Graphics^ startCanvas, array<String^>^ filenames, 
			   int nFrames, Random^ startRgen, Point startPos, 
			   Viewport^ startViewPort);

		bool collision(Rectangle r);
		bool checkCanMove(EBearing spriteBearing, int viewportWorldX, int viewportWorldY);
		virtual void move(int viewportWorldX, int viewportWorldY) override;
		virtual void canSpriteMove(int viewportWorldX, int viewportWorldY) override;
	};
