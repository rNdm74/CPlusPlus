#pragma once

#include "Shape.h"
#include "RectangleShape.h"

ref class BlockManager
	{
	private:
		array<Shape^,2>^ blocks;
		Graphics^ canvas;
		Size screen;

		int rows;
		int columns;

	public:
		BlockManager(Graphics^ g, Size s);
		void input();
		void update();
		void render();
	};
