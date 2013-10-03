#pragma once

#include "Constants.h"
#include "ObjectMap.h"
#include "Sprite.h"
#include "Viewport.h"

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
		int flags;
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

		void pickupItem(Sprite^ otherSprite);
		void collectCoin();
		void checkCollisions(Sprite^ otherSprite);
		void setSpritePositions(ObjectMap^ objectMap);
		void spriteAI();
		void renderSprites(int vX, int vY);
		void draw();

		int getScore()			{ return score; }
		int getCoins()			{ return coins; }
		int getLives()			{ return lives; }
		int getFlags()			{ return flags; }

		void setScore(int s)	{ score = s; }
		void setCoins(int c)	{ coins = c; }	
		void setLives(int l)	{ lives = l; }		
		void setFlags(int f)	{ flags = f; }
		
	};
