#pragma once

#include "CsvReader.h"
#include "Constants.h"
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

		//bool player;
		//bool flag;
		//bool enemy;
		//bool coin;
		bool walking;
		bool alive;
		bool gameover;
		bool levelwin;

		int lives;
		int coins;
		int score;

		Bitmap^ spriteSheet;
		
		PixelFormat format;

		array<int, 3>^ spriteSheetData;
		array<Point>^ spriteDirection;
		array<Point>^ collisionOffsets;

		EAction action;
		EBearing bearing;		

		Graphics^ canvas;		
		Random^ rGen;
		
		Rectangle spriteFrame;
		Rectangle tileMapBounds;

		Viewport^ viewPort;
		TileMap^ tileMap;
		String^ filename;

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

		int objectNumber;

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
		Sprite
		(
			Graphics^ startCanvas, 
			Viewport^ startViewPort, 
			CSVReader^ startReader, 
			TileMap^ startTileMap,
			EAction startAction,
			Random^ startRGen, 
			int startObjectNumber, 
			int startXMag, 
			int startYMag, 
			int startFrameDelay,
			String^ startFilename,
			Rectangle startTileMapBounds
		);
		
#pragma region Methods
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
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
		void bounce();					
		void die();	
		void coin();
		void stop();	
		//
		// Moving and updating sprite
		//		
		void clamp(int col, int row);		
		void move(int viewportWorldX, int viewportWorldY);				
		void updateFrame();
		//
		// Draw sprite
		//
		void draw(int newXPos, int newYPos);
		void draw();
		//
		// AI sprite
		//
		bool collectCoin();
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
		void setAction(EAction a)		{ action = a; }
		void setWalking(bool w)			{ walking = w; }		
		void setAlive(bool a)			{ alive = a; }
		void setGameOver(bool g)		{ gameover = g; }
		void setLevelWin(bool l)		{ levelwin = l; }

		void setXPos(int x)				{ xPos = x; }
		void setYPos(int y)				{ yPos = y; }
		
		void setLives(int l)			{ lives = l; }
		void setCoins(int c)			{ coins = c; }
		void setScore(int s)			{ score = s; }
		

		Rectangle getSpriteFrame()		{ return Rectangle(xPos, yPos, spriteFrame.Width, spriteFrame.Height); }
		Rectangle getTileMapBounds()	{ return tileMapBounds; }
		EAction getAction()				{ return action; }
		EBearing getBearing()			{ return bearing; }
		String^ getFilename()			{ return filename; }

		int getObjectNumber()			{ return objectNumber; }
		int getWidth()					{ return frameWidth; }
		int getHeight()					{ return frameHeight; }	
		int getXPos()					{ return xPos; }
		int getYPos()					{ return yPos; }
		
		int getLives()					{ return lives; }
		int getCoins()					{ return coins; }
		int getScore()					{ return score; }

		bool isWalking()				{ return walking; }
		bool isAlive()					{ return alive; }
		bool isGameOver()				{ return gameover; }		
		bool isLevelWin();		

#pragma endregion

	};
