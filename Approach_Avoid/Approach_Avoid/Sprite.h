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
#define HALF 2
#define WANDER_PROB 25
#define SPEED 1



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
		
		Rectangle frameRectangle;
		Rectangle boundsRect;

		bool walking;
		bool alive;

		int currentFrame;
		int frames;

		int frameWidth, frameHeight;
		int boundsX, boundsY;
		int xPos, yPos;
		int xMag, yMag;	
		

		int behavior;
		
		long frameTime;

	public:
		Sprite^ Next;

	public:
		// Construtor
		Sprite(EBoundsAction startAction, Graphics^ startCanvas,array<String^>^ filenames, int nFrames, Random^ startRgen, Point startPosm);

		// Methods
		void setSpriteSheet();
		void erase(Color eraseColor);

		bool isBoundsCollision();		
		void executeBoundsAction();
		
		void approach_avoid(Sprite^ target);

		void wrap();
		void reverse();
		void die();
		void stop();

		virtual void canSpriteMove(int viewportWorldX, int viewportWorldY);
		virtual void move(int viewportWorldX, int viewportWorldY);

		void wander();		
		void updateFrame();	

		void update();
		void draw();
		void draw(int newXPos, int newYPos);

		//=================================================
		// Gets and Sets
		//=================================================
		Rectangle getFrameRectangle()		{ return Rectangle(xPos, yPos, frameWidth, frameHeight); }
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
		EBearing getBearing()			{ return bearing; }
		void setBearing(EBearing b)		{ bearing = b; }
	};
