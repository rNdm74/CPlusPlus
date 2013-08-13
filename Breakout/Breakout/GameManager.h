#pragma once

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

#include "Shape.h"
#include "RectangleShape.h"
#include "EllipseShape.h"

ref class GameManager
	{
	private:
		array<Shape^,2>^ blocks;

		Shape^ northWall;
		Shape^ westWall;
		Shape^ eastWall;

		Shape^ paddle;
		Shape^ ball;

		Graphics^ canvas;
		Size screen;

		int rows;
		int columns;

		int brokenBrickCount;

		int lifes;

		bool gameRunning;

	public:
		GameManager(Graphics^ g, Size s, int c, int r);

		void keyDown(KeyEventArgs^  e);
		void keyUp(KeyEventArgs^  e);

		void update();
		void render();

		void resetGame(SizeF s);
		
		bool checkGameOver();
		bool checkBallOutOfBounds();
		bool checkCollision(Shape^ ball);
		
		void setGameRunning(bool b) { gameRunning = b; }
		bool getGameRunning()		{ return gameRunning; }
		int getBrokenBrickCount()	{ return brokenBrickCount; }
		int getLifes()				{ return lifes; }
	};
