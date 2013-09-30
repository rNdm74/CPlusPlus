#pragma once

#include "NPC.h"
#include "Item.h"
#include "Player.h"
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
		int imageOneX;
		int imageTwoX;

		TileMap^ tileMap;
		ObjectMap^ objectMap;
		
		SpriteList^ spriteList;
				
		

		Random^ rGen;

		CSVReader^ reader;

		Rectangle clientRectangle;


		Player^ player;
		array<NPC^>^ aliens;
		array<Item^>^ flags;
		array<Item^>^ coins;

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

		void addCoinsToGame();

		Player^ getPlayer()	{ return player; }

	};
