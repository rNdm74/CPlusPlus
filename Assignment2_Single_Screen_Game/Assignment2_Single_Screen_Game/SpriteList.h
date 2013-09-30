#pragma once

#include "Sprite.h"
#include "Viewport.h"

/// <summary>
/// Summary for Sprite
///
///	   Note: If you change the name of this class, you will need to change the
///          'Resource File Name' property for the managed resource compiler tool
///          associated with all .resx files this class depends on.  Otherwise,
///          the designers will not be able to interact properly with localized
///          resources associated with this form.
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
