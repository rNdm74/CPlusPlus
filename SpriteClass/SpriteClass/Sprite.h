#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

#define WANDER_PROB 35
#define MIN_LIFE_EXPECTANCY 100
#define MAX_LIFE_EXPECTANCY 200
#define DIRECTION -1
#define SPEED 2

enum orientation
	{
		EAST,
		WEST
	};

ref class Sprite
	{
	private:
		Bitmap^ leftFrame;
		Bitmap^ rightFrame;

		Bitmap^ spriteSheet;
		Graphics^ canvas;		
		Random^ rGen;

		RectangleF srcRectangle;
		Rectangle boundsRect;

		int currentFrame;
		int nFrames;

		float frameWidth;
		float frameHeight;

		float xPos;
		float yPos;

		float xVel;
		float yVel;

		double growRate;
		double age;
		int scale;
		int lifeExpectancy;
		int tombStoneTime;

		bool dead;
		bool adult;

	public:
		Sprite(Graphics^ startCanvas, Bitmap^ startSpriteSheet, Random^ startRGen, Rectangle bounds);
		Sprite(Graphics^ startCanvas, Bitmap^ startSpriteSheet, Random^ startRGen, int startXPos, int startYPos, int startXVel, int startYVel);
	
		void init();
		void draw();
		void drawDead();
		void erase(Color eraseColor);
		void move();
		void checkBounds();
		void updateFrame();
		void setSpriteSheet(Bitmap^ newSpriteSheet, int newNframes);
		void wander();

		float getVerticalResolution() { return spriteSheet->VerticalResolution; }
	};
