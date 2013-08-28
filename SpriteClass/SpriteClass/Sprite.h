#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

#define WANDER_PROB 35
#define LIFE_EXPECTANCY 1000
#define DIRECTION -1
#define SPEED 1

ref class Sprite
	{
	private:
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

		int age;

		bool dead;

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
	};
