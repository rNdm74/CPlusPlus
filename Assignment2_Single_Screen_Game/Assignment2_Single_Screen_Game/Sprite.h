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
		array<Point>^ offsets;

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

		Point startPosition;		

#pragma endregion

	private:
		ETileType getTileType(Point offset);

	public:
		Sprite^ Next;

	public:
		//
		// Construtor
		//
		Sprite(TileMap^ startTileMap, Viewport^ startViewPort, 
			   EBoundsAction startAction, ESprite startSprite,
			   Graphics^ startCanvas, String^ filename,
			   Random^ startRgen, array<int,3>^ startMap, 
			   int startXMag, int startYMag, int startFrameDelay);
		
#pragma region Methods
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>

		void setSpriteSheet();
		void erase(Color eraseColor);
		// 
		// Collision check
		//
		bool isBoundsCollision();
		bool collided(Sprite^ sprite);
		//
		// Bounds action
		//
		void executeBoundsAction();	
		void wrap();					
		void reverse();					
		void die();						
		void stop();	
		//
		// Moving and updating sprite
		//		
		bool collectCoin();
		bool isTileWalkable(ETileType tileType);
		void canSpriteMove(int viewportWorldX, int viewportWorldY);		
		void move(int viewportWorldX, int viewportWorldY);				
		void updateFrame();
		//
		// Draw sprite
		//
		void draw(int newXPos, int newYPos);
		//
		// AI sprite
		//
		void wander();
		EBearing getRandomBearing();

#pragma endregion
		
#pragma region Gets/Sets
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>		
		
		void setStartPosition(Point p)	{ startPosition = p; xPos = p.X; yPos = p.Y; }
		void resetPosition()			{ xPos = startPosition.X; yPos = startPosition.Y; }		
		void setBearing(EBearing b);
		void setAction(EBoundsAction a)	{ action = a; }
		void setWalking(bool w)			{ walking = w; }		
		void setAlive(bool a)			{ alive = a; }
		void setXPos(int x)				{ xPos = x; }
		void setYPos(int y)				{ yPos = y; }
		void setGameOver(bool g)		{ gameover = g; }
		void setLevelWin(bool l)		{ levelwin = l; }

		Rectangle getFrameRectangle()	{ return Rectangle(xPos, yPos, frameRectangle.Width, frameRectangle.Height); }
		Rectangle getBoundsRectangle()	{ return boundsRect; }
		EBoundsAction getAction()		{ return action; }
		EBearing getBearing()			{ return bearing; }
		int getXPos()					{ return xPos; }
		int getYPos()					{ return yPos; }
		int getWidth()					{ return frameWidth; }
		int getHeight()					{ return frameHeight; }		
		bool isWalking()				{ return walking; }
		bool isAlive()					{ return alive; }
		bool isEnemy()					{ return enemy; }
		bool isPlayer()					{ return player; }
		bool isFlag()					{ return flag; }
		bool isCoin()					{ return coin; }
		bool isGameOver()				{ return gameover; }		
		bool isLevelWin()				{ return levelwin; }		

#pragma endregion

	};
