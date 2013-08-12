#pragma once

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

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

		Graphics^ canvas;

	public:
		Shape(int startXPos, int startYPos, int startWidth, int startHeight, 
			Graphics^ startCanvas, int startXVel, int startYVel, Color startColor);

		void erase();
		void move();
		virtual void draw();
		void collision(Shape^ object);
	};
