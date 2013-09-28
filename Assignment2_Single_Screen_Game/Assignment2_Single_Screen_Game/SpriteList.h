#pragma once

#include "Sprite.h"
#include "Viewport.h"

ref class SpriteList
	{
	private:
		Viewport^ viewport;
		int score;
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

		int getScore()	{ return score; }
		int getLives()	{ return lives; }
	};
