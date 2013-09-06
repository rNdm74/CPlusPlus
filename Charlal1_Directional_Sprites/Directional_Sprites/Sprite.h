#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

//=================================================
// Constants
//=================================================
#define MAX_DIRECTIONS 4
#define WANDER_PROB 10
#define SPEED 2


//=================================================
// Bearing
//=================================================
public enum EBearing
	{
		NORTH,
		SOUTH,
		EAST,
		WEST
	};

ref class Sprite
	{
	private:
		//=================================================
		// Variables
		//=================================================
		array<Bitmap^>^ spriteSheets;
		array<Point>^ spriteDirection;

		EBearing bearing;

		Graphics^ canvas;		
		Random^ rGen;
		
		Rectangle srcRectangle;
		Rectangle boundsRect;

		bool walking;

		int currentFrame;
		int frames;

		int frameWidth;
		int frameHeight;

		int xPos;
		int yPos;

		int xMag;
		int yMag;

	public:
		//=================================================
		// Construtor
		//=================================================
		Sprite(Graphics^ startCanvas, array<String^>^ filenames, int nFrames, Random^ startRGen, Rectangle bounds);

		//=================================================
		// Methods
		//=================================================	
		void setSpriteSheet();
		void erase(Color eraseColor);

		void checkBounds();
		void move();
		void wander();
		
		void updateFrame();		

		void draw();

		//=================================================
		// Gets and Sets
		//=================================================
		Rectangle getSrcRectangle()	{ return Rectangle(xPos, yPos, srcRectangle.Width,	srcRectangle.Height); }

		bool isWalking()				{ return walking; }
		void setWalking(bool w)			{ walking = w; }

		int getXPos()					{ return xPos; }
		int getYPos()					{ return yPos; }
		
		EBearing getRandomBearing();
		void setBearing(EBearing b)		{ bearing = b; }
	};
