#pragma once

#include "Constants.h"
#include "Sprite.h"
#include "SpriteList.h"
#include "TileMap.h"
#include "MapManager.h"
#include "Viewport.h"
#include "FileReader.h"

using namespace System::Windows::Forms;

/// <summary>
/// Summary for GameManager
///
///	   NOTE: The game manager will control all the classes that are required to 
///          run the game, the classes it will hold are:
///          SoundManager, FontManager, CSVReader, Viewport, SpriteList,
///          Sprite, TileMap, TileList, Tile.
///
/// </summary>

ref class GameManager
	{

#pragma region Variables

	private:
		Viewport^ foreground;
		Rectangle clientRectangle;

		FileReader^ reader;

		Graphics^ canvas;
		Graphics^ dbGraphics;
		Bitmap^ dbBitmap;

		Image^ background;
		
		TileMap^ tileMap;
		MapManager^ mManager;
		
		SpriteList^ alienList;
		SpriteList^ flagList;
		SpriteList^ playerList;
		Sprite^ player;

		Random^ rGen;

		int flag;
		int flagCount;
		int coinCount;
		int lives;
		int score;
		int highscore;
		int level;

		bool gameover;
		bool levelover;

		StreamReader^ fileReader;
		StreamWriter^ fileWriter;

#pragma endregion

#pragma region Constructor

	private:
		Sprite^ Create(int type);

	public:
		GameManager(Graphics^ startCanvas, Rectangle clientRectangle);

#pragma endregion

#pragma region Methods

		void keyDown(Keys code);
		void keyUp(Keys code);		
		
		void updateGame();
		void drawGame();

		void checkLevelPhase();
		void checkLevelWin();
		void checkLevelOver();		

		void initializeGame();
		void initializeObjectsPositons();	

#pragma endregion

#pragma region Gets/Sets

		Sprite^ getPlayer()		{ return player; }
		bool isGameOver()		{ return gameover; }
		bool isLevelOver()		{ return levelover; }
		
		int getLevel()			{ return level; }
		int getHighScore()		{ return highscore; }
		int getScore()			{ return score; }		
		int getCoins()			{ return coinCount; }

		int getLives()			{ return lives; }
		int getFlag()			{ return flag; }

		void setScore(int s)	{ player->setScore(s); }
		void setLevel(int l)	{ level = l; }


#pragma endregion

	};
