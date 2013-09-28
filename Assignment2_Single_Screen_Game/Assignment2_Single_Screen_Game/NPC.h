#pragma once
#include "sprite.h"

public enum EEnemyType
	{
		SNAIL = 0,
		SLIME = 1,
		FLY = 2
	};

ref class NPC :
public Sprite
	{
	public:
		NPC(TileMap^ startTileMap, EBoundsAction startAction, 
			   Graphics^ startCanvas, array<String^>^ filenames, 
			   int nFrames, Random^ startRGen, Point startPos, 
			   Viewport^ startViewPort, int startEnemyType);

		void setEnemyOne();
		void setEnemyTwo();

		bool collision(Rectangle r);
		bool checkCanMove(EBearing spriteBearing, int viewportWorldX, int viewportWorldY);
		virtual void move(int viewportWorldX, int viewportWorldY) override;
		virtual void canSpriteMove(int viewportWorldX, int viewportWorldY) override;
	};
