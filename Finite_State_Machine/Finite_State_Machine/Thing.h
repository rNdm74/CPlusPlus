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

		int isAlive;
		int angle;
		int radius;		
		
		Graphics^ canvas;
		Random^ rGen;

		int speed;
		int width, height;
		int worldWidth, worldHeight;

		Bitmap^ thingImage;

	public:
		Thing();
		Thing(Graphics^ startCanvas, Random^ startRandom, int startWorldWidth, int startWorldHeight, String^ imageFileName);

		void Move();
		void ChangeRandomDirection();
		void Draw();
		void PointMeAt(int newX, int newY);
		double ComputeDistance(Thing^ otherGuy);	
	};
