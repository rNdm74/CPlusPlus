#pragma once

#include "NPC.h"
#include "Player.h"
#include "Sprite.h"
#include "SpriteList.h"
#include "TileMap.h"
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

		SpriteList^ spriteList;
				
		bool collision;

		Random^ rGen;

		CSVReader^ reader;

		Rectangle clientRectangle;

		Player^ knight;

		array<NPC^>^ chickens;

	public:
		GameManager(Graphics^ startCanvas, Rectangle clientRectangle);

		void keyDown(KeyEventArgs^  e);
		void keyUp(KeyEventArgs^  e);
		void updateGame();
		void drawGame();

	};
