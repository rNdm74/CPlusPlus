#pragma once

#include "Sprite.h"

ref class SpriteList
	{
	private:
		Sprite^ head;
		Sprite^ tail;
	public:
		SpriteList();
		int length();
		Sprite^ get(int item);
		void add(Sprite^ newGameObject);
		void remove(Sprite^ gameObjectToDelete);
		void checkSpriteCollision(int vX, int vY);
		void update();
		void approach_avoid(Sprite^ target);
		void renderSprites(int vX, int vY);
		void draw();
	};
