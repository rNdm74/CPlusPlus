#pragma once

#include "Constants.h"
#include "Sprite.h"
#include "SpriteList.h"
#include "TileMap.h"
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
		Viewport^ viewport;
		Rectangle clientRectangle;

		FileReader^ reader;

		Graphics^ formCanvas;
		Graphics^ dbGraphics;
		Bitmap^ dbBitmap;

		Image^ background;
		
		TileMap^ tileMap;

		Random^ rGen;

		StreamReader^ fileReader;
		StreamWriter^ fileWriter;

		Sprite^ player;
		Sprite^ cocoon;
		Sprite^ makhana;
		Sprite^ floppit;
		Sprite^ fluppit;
		Sprite^ peruna;

		int xPos;
		int yPos;

		int viewportScroll;

		Point movePoint;
		int direction;

#pragma endregion

#pragma region Constructor

	public:
		GameManager(Graphics^ startCanvas, Rectangle clientRectangle);

#pragma endregion

#pragma region Methods

		void keyDown(Keys code);
		void keyUp(Keys code);
		void mouseDown(Point p);
		
		void update();
		void draw();

		void checkLevelPhase();
		void checkLevelWin();
		void checkLevelOver();		

		void initializeGame();
		void initializeObjectsPositons();	

#pragma endregion

#pragma region Gets/Sets
//
//
//
//		int getXPos() { return player->getVelocityY(); }

#pragma endregion

	};
