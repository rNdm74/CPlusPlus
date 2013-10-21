#pragma once

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

ref class Thing
	{
	protected:
		Point location;
		Point direction;
		
		Graphics^ canvas;
		Random^ rGen;

		int speed;

		int angle;
		int radius;	
		
		int worldWidth, worldHeight;

		Bitmap^ thingImage;

	public:
		Thing();
		Thing(Graphics^ startCanvas, Random^ startRandom, int startWorldWidth, int startWorldHeight, String^ imageFileName, int startRadius);

		void Move();
		void ChangeRandomDirection();
		void Draw();
		void PointMeAt(int newX, int newY);
		double ComputeDistance(Thing^ otherGuy);

		bool collided(Thing^ thing);						
		
		int getRadius()			{ return radius; }
		Point getCenter()		{ return Point(location.X + (radius / 2), location.Y + (radius / 2)); }
		Point getLocation()		{ return location; }				
		Rectangle getBounds()	{ return Rectangle(location, Size(thingImage->Width, thingImage->Height)); }
	};
