#pragma once

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

#define SPEED 20;

ref class GameObject
	{
	private:
		Point location;
		Size size;

		int yVel;
		int xVel;

		int direction;
		int count;

		bool placed;

		Brush^ brush;
		Pen^ pen;

		Rectangle screen;
		Graphics^ graphics;

	public:
		GameObject^ Next;
		
	public:
		GameObject(Point startLocation, Size startSize, Rectangle screenBounds, Graphics^ canvas, Color color);

		void input(KeyEventArgs^  e);
		void update();
		void render();

		void setLocation(Point l)	{ location = l; }
		Point getLocation()		{ return location; }

		void setDirection(int d)	{ direction = d; }

	};
