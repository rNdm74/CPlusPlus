#pragma once

#include "TileMap.h"
#include "ViewPort.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Drawing::Imaging;

/// <summary>
/// Summary for Sprite
///
/// WARNING: The Sprite class controls all the information that is required to 
///          use a sprite in the game.
///
/// </summary>

ref class Sprite
	{
	protected:

#pragma region Variables
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>

		bool player;
		bool flag;
		bool enemy;
		bool coin;
		bool walking;
		bool alive;
		bool gameover;
		bool levelwin;

		Bitmap^ spriteSheet;
		Bitmap^ spriteBitmap;
		PixelFormat format;

		array<int, 3>^ sheetData;

		array<Point>^ spriteDirection;
		
		array<Point>^ boundPoints;
		array<Point>^ bounds;		

		EBoundsAction action;
		EBearing bearing;		

		Graphics^ canvas;		
		Random^ rGen;
		
		Rectangle frameRectangle;
		Rectangle boundsRect;

		Viewport^ viewPort;
		TileMap^ tileMap;		

		int currentFrame;
		long frameTime;
		int frameDelay;
		int frames;

		int frameWidth;
		int frameHeight;

		int xPos;
		int yPos;

		int xMag;
		int yMag;

		int boundsX;
		int boundsY;

		Point startPosition;		

#pragma endregion
	private:
		ETileType getTileType(int offsetX, int offsetY);

	public:
		Sprite^ Next;

	public:
		//
		// Construtor
		//
		Sprite(TileMap^ startTileMap, EBoundsAction startAction, 
			   Graphics^ startCanvas, String^ filename, 
			   int nFrames, Random^ startRgen, Point startPos, 
			   Viewport^ startViewPort, ESprite startSprite);
		
#pragma region Methods
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>

		void setSpriteSheet();
		void erase(Color eraseColor);
		// 
		// collision check
		//
		bool isBoundsCollision();
		bool collided(Sprite^ sprite);
		//
		// bounds action
		//
		void executeBoundsAction();	
		void wrap();					
		void reverse();					
		void die();						
		void stop();	
		//
		// moving and updating sprite
		//
		
		bool checkTile(ETileType tileType);
		void canSpriteMove(int viewportWorldX, int viewportWorldY);
		bool checkCanMove(EBearing spriteBearing, int viewportWorldX, int viewportWorldY);
		void move(int viewportWorldX, int viewportWorldY);				
		void updateFrame();
		//
		// draw sprite
		//
		void draw(int newXPos, int newYPos);

#pragma endregion
		
#pragma region Gets/Sets
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>

		Rectangle getFrameRectangle()	{ return Rectangle(xPos, yPos, frameRectangle.Width, frameRectangle.Height); }
		Rectangle getBoundsRectangle()	{ return boundsRect; }

		EBoundsAction getAction()		{ return action; }
		void setAction(EBoundsAction a)	{ action = a; }

		bool isWalking()				{ return walking; }
		void setWalking(bool w)			{ walking = w; }

		bool isAlive()					{ return alive; }
		void setAlive(bool a)			{ alive = a; }

		void setStartPosition(Point p)	{ startPosition = p; xPos = p.X; yPos = p.Y; }
		void resetPosition()			{ xPos = startPosition.X; yPos = startPosition.Y; }

		int getXPos()					{ return xPos; }
		void setXPos(int x)				{ xPos = x; }

		int getYPos()					{ return yPos; }
		void setYPos(int y)				{ yPos = y; }

		int getWidth()					{ return frameWidth; }
		int getHeight()					{ return frameHeight; }
		
		EBearing getBearing()			{ return bearing; }
		void setBearing(EBearing b);

		bool isEnemy()					{ return enemy; }
		bool isPlayer()					{ return player; }
		bool isFlag()					{ return flag; }
		bool isCoin()					{ return coin; }
		bool isGameOver()				{ return gameover; }
		void setGameOver(bool g)		{ gameover = g; }
		bool isLevelWin()				{ return levelwin; }
		void setLevelWin(bool l)		{ levelwin = l; }

#pragma endregion

	};
