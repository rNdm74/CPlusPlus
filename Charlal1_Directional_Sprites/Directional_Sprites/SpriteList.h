#pragma once

#include "Sprite.h"
#include "Viewport.h"

ref class SpriteList
	{
	private:
		Viewport^ viewport;

		Sprite^ head;
		Sprite^ tail;
	public:
		SpriteList(Viewport^ startViewport);
		int length();
		Sprite^ get(int item);
		void add(Sprite^ newGameObject);
		void remove(Sprite^ gameObjectToDelete);
		void update();
		void renderSprites(int vX, int vY);
		void draw();
	};
