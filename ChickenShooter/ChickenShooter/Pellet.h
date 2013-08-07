#pragma once

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

#define PELLET_DIAMETER 10
#define PELLET_SPEED 1
#define PELLET_MIN_VELOCITY 0.1

ref class Pellet
	{
	private:
		float xPos;
		float yPos;

		int diameter;

		float xVel;
		float yVel;

		bool isAlive;

		Color pelletColour;
		array<Color>^ colors;

		Graphics^ canvas;
		Brush^ brush;	

		Random^ rGen;

	private:
		void init(Graphics^ startCanvas, Random^ startRGen);

	public:
		Pellet^ Next;

	public:
		Pellet(Point startP, Graphics^ startCanvas, Random^ startRGen);
		Pellet(int startXPos, int startYPos, Graphics^ startCanvas, Random^ startRGen);

		void draw();
		void update();

		bool getIsAlive()			{ return isAlive; }
		void setIsAlive(bool a)		{ isAlive = a; }

		float getYPos()				{ return yPos; }
	};
