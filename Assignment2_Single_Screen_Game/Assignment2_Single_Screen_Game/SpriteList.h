#pragma once

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
		Sprite^ checkCollisions(Sprite^ sprite);
		void renderSprites(int vX, int vY);
		void draw();

		int getScore()			{ return score; }
		void setScore(int s)	{ score = s; }
		int getCoins()			{ return coins; }
		int getLives()			{ return lives; }
		void setLives(int l)	{ lives = l; }
		int getFlags()			{ return flags; }
		void setFlags(int f)	{ flags = f; }
		
	};
