#pragma once

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


#define SPEED 4

ref class Shape
	{
	protected:
		int xVel;
		int yVel;
		int	xPos;
		int yPos;
		int width;
		int height;
		Color color;
		Brush^ brush;
		Pen^ pen;
		bool visible;
		bool hit;

		Graphics^ canvas;

	public:
		Shape(int startXPos, int startYPos, int startWidth, int startHeight, 
			Graphics^ startCanvas, int startXVel, int startYVel, Color startColor);

		void erase();
		void keyDown(KeyEventArgs^  e);
		void keyUp(KeyEventArgs^  e);
		void move();
		virtual void draw();
		void collision(Shape^ s);

		Rectangle getBounds() { return Rectangle(xPos, yPos, width, height); }

		bool isVisible() { return visible; }
		
		//void setXPos(int x)	{ xPos = x; }
		//void setXVel(int x)	{ xVel = x; }
		int getYPos()		{ return yPos; }
		//int getXVel()		{ return xVel; }
	};
