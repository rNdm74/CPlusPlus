#pragma once

#include "TileMap.h"

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
#define HALF 2
#define WANDER_PROB 25
#define SPEED 2


//=================================================
// Bearing
//=================================================
public enum EBearing
	{
		NORTH = 0,
		EAST = 1,
		SOUTH = 2,
		WEST = 3
	};

public enum EBoundsAction
	{
		BOUNCE,
		WRAP,
		DIE,
		STOP, 
		WALK
	};

ref class Sprite
	{
	protected:
		//=================================================
		// Variables
		//=================================================
		array<Bitmap^>^ spriteSheets;
		array<Point>^ spriteDirection;

		EBoundsAction action;
		EBearing bearing;		

		Graphics^ canvas;		
		Random^ rGen;
		
		Rectangle srcRectangle;
		Rectangle boundsRect;

		TileMap^ tilemap;

		bool walking;
		bool alive;

		int currentFrame;
		int frames;

		int frameWidth;
		int frameHeight;

		int xPos;
		int yPos;

		int xMag;
		int yMag;

		long frameTime;

	public:
		Sprite^ Next;

	public:
		//=================================================
		// Construtor
		//=================================================
		Sprite(TileMap^ startTileMap, EBoundsAction startAction, Graphics^ startCanvas, array<String^>^ filenames, int nFrames, Random^ startRgen, Point startPos, Rectangle bounds);

		//=================================================
		// Methods
		//=================================================	
		void setSpriteSheet();
		void erase(Color eraseColor);

		bool isBoundsCollision();		
		void executeBoundsAction();
		void canSpriteMove(int xPos, int yPos);

		void wrap();
		void reverse();
		void die();
		void stop();

		virtual void move();
		void wander();		
		void updateFrame();	

		void update();
		void draw();
		void draw(int newXPos, int newYPos);

		//=================================================
		// Gets and Sets
		//=================================================
		Rectangle getSrcRectangle()		{ return Rectangle(xPos, yPos, srcRectangle.Width,	srcRectangle.Height); }
		Rectangle getBoundsRectangle()	{ return boundsRect; }

		EBoundsAction getAction()		{ return action; }
		void setAction(EBoundsAction a)	{ action = a; }

		bool isWalking()				{ return walking; }
		void setWalking(bool w)			{ walking = w; }

		bool isAlive()					{ return alive; }
		void setAlive(bool a)			{ alive = a; }

		int getXPos()					{ return xPos; }
		void setXPos(int x)				{ xPos = x; }

		int getYPos()					{ return yPos; }
		void setYPos(int y)				{ yPos = y; }

		int getWidth()					{ return frameWidth; }
		int getHeight()					{ return frameHeight; }
		
		EBearing getRandomBearing();
		void setBearing(EBearing b)		{ bearing = b; }
	};
