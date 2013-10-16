#pragma once

#include "Constants.h"
#include "MapManager.h"
#include "Sprite.h"
#include "Viewport.h"
#include "SoundManager.h"

using namespace System;

/// <summary>
/// Summary for SpriteList
///
///	   Note: The SpriteList controls all the sprites in the game, its main function
///			 is to draw and update the sprites.
///
/// </summary>

ref class SpriteList
	{
	private:
		Viewport^ viewport;

		int score;
		int flag;
		int flagCount;
		int coins;
		int lives;

		Sprite^ head;
		Sprite^ tail;

	public:
		SpriteList(Viewport^ startViewport);
		int length();
		Sprite^ get(int index);
		void add(Sprite^ newGameObject);
		void remove(Sprite^ gameObjectToDelete);
		void update();

		void pickupItem(Sprite^ otherSprite, SoundManager^ sManager);
		void collectCoin(SoundManager^ sManager);
		void checkCollisions(Sprite^ otherSprite, SoundManager^ sManager);
		void setSpritePositions(MapManager^ mManager);
		void setSpritesMagnitudes(int newXMag, int newYMag);
		void spriteAI();
		void renderSprites(int vX, int vY);
		void draw();

		int getScore()				{ return score; }
		int getCoins()				{ return coins; }
		int getLives()				{ return lives; }
		int getFlag()				{ return flag; }
		int getFlagCount()			{ return flagCount; }

		void setScore(int s)		{ score = s; }
		void setCoins(int c)		{ coins = c; }	
		void setLives(int l)		{ lives = l; }		
		void setFlag(int f)			{ flag = f; }
		void setFlagCount(int fc)	{ flagCount = fc; }
		
	};
