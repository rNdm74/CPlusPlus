#pragma once

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

#define SPEED 1
#define MAX_SPEEDX 0.5
#define MAX_SPEEDY 0.5
#define DAMPING 0.05

ref class Shape
	{
	protected:
		float xVel;
		float yVel;
		float xPos;
		float yPos;
		float width;
		float height;
		Color color;
		Brush^ brush;
		Pen^ pen;
		bool visible;
		bool hit;

		Graphics^ canvas;

	public:
		Shape(float startXPos, float startYPos, float startWidth, float startHeight, 
			Graphics^ startCanvas, float startXVel, float startYVel, Color startColor);

		void keyDown(KeyEventArgs^  e);
		void keyUp(KeyEventArgs^  e);

		void move();		
		virtual void draw();

		void verticalBounce(float center);
		void verticalBounce();
		void horizontalBounce();
		
		bool collision(Shape^ s);


		RectangleF getBounds()	{ return RectangleF(xPos, yPos, width, height); }
		bool isVisible()		{ return visible; }
		float getCenterX()		{ return xPos + width / 2; }
		float getYVel()			{ return yVel; }
		float getYPos()			{ return yPos; }

		void setVisible(bool b) { visible = b; }
		void setYVel(float y)		{ yVel = y; }		
	};
