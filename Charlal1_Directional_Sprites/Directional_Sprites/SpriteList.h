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
		void update();
		void draw();
	};
