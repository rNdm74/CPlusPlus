#pragma once

#include "Sprite.h"
#include "SpriteList.h"
#include "TileMap.h"
#include "ObjectMap.h"
#include "Viewport.h"
#include "CsvReader.h"


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
	private:
		Viewport^ foreground;

		Graphics^ canvas;
		Graphics^ dbGraphics;
		Bitmap^ dbBitmap;

		Image^ background;

		TileMap^ tileMap;
		ObjectMap^ objectMap;
		
		SpriteList^ spriteList;
				
		bool gameover;

		Random^ rGen;

		CSVReader^ reader;

		Rectangle clientRectangle;

		Sprite^ player;
		array<Sprite^>^ aliens;
		array<Sprite^>^ flags;
		array<Sprite^>^ coins;

		int flagCount;
		int coinCount;
		int lives;

		int score;
		int highscore;

		StreamReader^ fileReader;
		StreamWriter^ fileWriter;

	public:
		GameManager(Graphics^ startCanvas, Rectangle clientRectangle);

		void keyDown(KeyEventArgs^  e);
		void keyUp(KeyEventArgs^  e);
		void createGame();
		void updateGame();
		void drawGame();

		void checkGamePhaze();
		void checkGameWin();
		void checkGameOver();

		void addCoinsToGame();

		Sprite^ getPlayer()	{ return player; }
		bool isGameOver()	{ return gameover; }
		String^ getHighScore()	{ return highscore.ToString(); }
		String^ getScore()		{ return score.ToString(); }

	};
