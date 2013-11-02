#pragma once

#include "Constants.h"
#include "Sprite.h"
#include "Player.h"
#include "Enemy.h"
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

		Image^ hud;
		Bitmap^ healthImage;
		Bitmap^ manaImage;
		Graphics^ hGraphics;
		Graphics^ mGraphics;
		int health;
		int mana;
		
		TileMap^ tileMap;

		Random^ rGen;

		StreamReader^ fileReader;
		StreamWriter^ fileWriter;

		Player^ player;
		Enemy^ cocoon;
		Enemy^ makhana;
		Enemy^ floppit;
		Enemy^ fluppit;
		Enemy^ peruna;

		Sprite^ spriteInPlay;

		long healthRegen;
		long manaRegen;

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

		void KeyDown(Keys code);
		void KeyUp(Keys code);
		void MouseDown(Point p);
		
		void Update();
		void Draw();

		void StartAttack();

		void CheckLevelPhase();
		void CheckLevelWin();
		void CheckLevelOver();		

		void InitializeGame();
		void InitializeObjectsPositons();	

#pragma endregion

#pragma region Gets/Sets
//
//
//
		void setPlayerAbility(EState s)		{ player->setSelectedAbility(s); }

		bool containsMouseLocation(Point p)	{ return floppit->getCollisionRectangle(viewport->getViewportWorldX(), viewport->getViewportWorldY()).Contains(p); }

#pragma endregion

	};
