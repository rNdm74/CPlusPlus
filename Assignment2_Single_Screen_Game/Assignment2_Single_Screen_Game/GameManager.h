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

public enum ESprite
	{
		PLAYER = 1,
		ENEMY1 = 2,
		ENEMY2 = 3,
		ENEMY3 = 4,
		ENEMY4 = 5,
		FLAG1 = 10,
		FLAG2 = 11,
		FLAG3 = 12
	};

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
				
		bool collision;

		Random^ rGen;

		CSVReader^ reader;

		Rectangle clientRectangle;

		Player^ knight;

		array<NPC^>^ chickens;

		array<Item^>^ flags;

		int score;
		int lives;

	public:
		GameManager(Graphics^ startCanvas, Rectangle clientRectangle);

		void keyDown(KeyEventArgs^  e);
		void keyUp(KeyEventArgs^  e);
		void updateGame();
		void drawGame();

	};
