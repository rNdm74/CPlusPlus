#pragma once

#include "Shape.h"
#include "RectangleShape.h"
#include "EllipseShape.h"

ref class BlockManager
	{
	private:
		array<Shape^,2>^ blocks;
		Shape^ paddle;
		Shape^ ball;

		Graphics^ canvas;
		Size screen;

		int rows;
		int columns;

	public:
		BlockManager(Graphics^ g, Size s);

		void keyDown(KeyEventArgs^  e);
		void keyUp(KeyEventArgs^  e);

		void update();
		void render();
	};
