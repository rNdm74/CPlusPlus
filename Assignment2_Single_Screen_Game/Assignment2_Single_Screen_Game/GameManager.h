#pragma once

#include "Constants.h"
#include "Sprite.h"
#include "SpriteList.h"
#include "TileMap.h"
#include "ObjectMap.h"
#include "Viewport.h"
#include "CsvReader.h"

using namespace System::Windows::Forms;

/// <summary>
/// Summary for GameManager
///
///	   NOTE: The gamemanager will control all the classes that are required to 
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

		CSVReader^ reader;

		Graphics^ canvas;
		Graphics^ dbGraphics;
		Bitmap^ dbBitmap;

		Image^ background;
		
		TileMap^ tileMap;
		ObjectMap^ objectMap;
		
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

		StreamReader^ fileReader;
		StreamWriter^ fileWriter;

		Font^ font;

#pragma endregion

#pragma region Constructor

	public:
		GameManager(Graphics^ startCanvas, Rectangle clientRectangle);
#pragma endregion

#pragma region Methods

		void keyDown(Keys code);
		void keyUp(Keys code);		
		
		void updateGame();
		void drawGame();

		void checkGamePhase();
		void checkGameWin();
		void checkGameOver();

		void initializeGame();
		void initializeObjectsPositons();

		void addCoinsToGame();

#pragma endregion

#pragma region Gets/Sets

		Sprite^ getPlayer()		{ return player; }
		bool isGameOver()		{ return gameover; }
		String^ getHighScore()	{ return highscore.ToString(); }
		String^ getScore()		{ return score.ToString(); }		
		String^ getCoins()		{ return coinCount.ToString(); }
		int getLives()			{ return lives; }
		int getFlag()			{ return flag; }


#pragma endregion

	};
