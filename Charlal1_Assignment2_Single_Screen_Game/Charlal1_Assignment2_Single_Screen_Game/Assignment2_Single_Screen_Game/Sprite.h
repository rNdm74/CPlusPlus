#pragma once

#include "FileReader.h"
#include "Constants.h"
#include "TileMap.h"
#include "ViewPort.h"
#include "SoundManager.h"


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
/// NOTE:	The Sprite class controls all the information that is required to 
///         use a sprite in the game.
///
/// </summary>

ref class Sprite
	{
#pragma region Variables

	protected:

		bool walking;
		bool alive;
		bool gameover;
		bool levelwin;
		bool hurtSound;

		int lives;
		int coins;
		int score;

		Bitmap^ spriteSheet;
		
		PixelFormat format;

		array<int, 3>^ spriteSheetData;
		array<Point>^ spriteDirection;
		array<Point>^ collisionOffsets;

		EAction action;
		EState state;		

		Graphics^ canvas;		
		Random^ rGen;
		
		Rectangle spriteFrame;
		Rectangle tileMapBounds;

		Viewport^ viewPort;
		TileMap^ tileMap;
		String^ filename;

		long hurtTime;

		int currentFrame;
		int frameTime;
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
		Sprite
		(
			Graphics^ startCanvas, 
			Viewport^ startViewPort, 
			FileReader^ startReader, 
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

		// 
		// Collision check
		//
		void hurt(SoundManager^ sManager);
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
		EState getRandomState();
		//
		//
		//

#pragma endregion
		
#pragma region Gets/Sets

		void setStartPosition(Point p)	{ startPosition = p; xPos = p.X; yPos = p.Y; }
		void resetPosition()			{ xPos = startPosition.X; yPos = startPosition.Y; }

		void setState(EState s);
		void setAction(EAction a)		{ action = a; }
		void setWalking(bool w)			{ walking = w; }		
		void setAlive(bool a)			{ alive = a; }
		void setGameOver(bool g)		{ gameover = g; }
		void setLevelWin(bool l)		{ levelwin = l; }

		void setXPos(int x)				{ xPos = x; }
		void setYPos(int y)				{ yPos = y; }
		void setXMag(int xM)			{ xMag = xM; }
		void setYMag(int yM)			{ yMag = yM; }
		
		void setLives(int l)			{ lives = l; }
		void setCoins(int c)			{ coins = c; }
		void setScore(int s)			{ score = s; }
		

		Rectangle getSpriteFrame()		{ return Rectangle(xPos, yPos, spriteFrame.Width, spriteFrame.Height); }
		Rectangle getTileMapBounds()	{ return tileMapBounds; }
		EAction getAction()				{ return action; }
		EState getState()				{ return state; }
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
