#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

#define WANDER_PROB 5
#define DIRECTION -1
#define SPEED 1

public enum EBearing{
		NORTH,
		SOUTH,
		EAST,
		WEST
	};

ref class Sprite
	{
	private:
		array<Bitmap^>^ spriteSheets;
		array<Point>^ spriteDirection;

		EBearing bearing;

		Graphics^ canvas;		
		Random^ rGen;

		Sprite^ knight;

		RectangleF srcRectangle;
		Rectangle boundsRect;

		int currentFrame;
		int nFrames;

		float frameWidth;
		float frameHeight;

		float xPos;
		float yPos;

		float xMag;
		float yMag;

	public:
		Sprite(Graphics^ startCanvas, array<String^>^ filenames, Random^ startRGen, Rectangle bounds);
		Sprite(Graphics^ startCanvas, array<String^>^ filenames, Random^ startRGen, Rectangle startBounds, Sprite^ startKnight);
		Sprite(Graphics^ startCanvas, array<String^>^ filenames, Random^ startRGen, int startXPos, int startYPos, int startXVel, int startYVel);
	
		void init(array<String^>^ filenames);
		void initFrame();
		void draw();
		void erase(Color eraseColor);
		void move();
		void checkBounds();
		void updateFrame();
		void setSpriteSheet(EBearing b);
		void wander();

		RectangleF getSrcRectangle()	{ return srcRectangle; }

		float getXPos()					{ return xPos; }
		float getYPos()					{ return yPos; }
		
		EBearing getBearing();
		void setBearing(EBearing b) { bearing = b; }
	};
