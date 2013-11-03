#pragma once

#include "Hud.h"
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
		Hud^ hud;
		Rectangle clientRectangle;

		FileReader^ reader;

		Graphics^ formCanvas;
		Graphics^ dbGraphics;
		Bitmap^ dbBitmap;

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

		Enemy^ enemyInPlay;

		
		array<int>^ battles;
		array<Enemy^>^ enemies;

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
		bool playerHasWon()							{ return (enemyInPlay->getHealth() >= 131); }
		bool playerHasLost()						{ return (player->getHealth() >= 131); }

		bool canUseAbility(EState selectedAbility)	
		{
			int availableMana = 132 - player->getMana();
			int abilityCost = 5 * safe_cast<int>(selectedAbility);
		
			return (abilityCost < availableMana);
		}

		void setPlayerAbility(EState s)				{ player->setSelectedAbility(s); }

		bool clickedOnEnemy(Point p)				{ return enemyInPlay->getCollisionRectangle(viewport->getViewportWorldX(), viewport->getViewportWorldY()).Contains(p); }
		
		bool clickedOnPlayer(Point p)				{ return player->getCollisionRectangle(viewport->getViewportWorldX(), viewport->getViewportWorldY()).Contains(p); }

#pragma endregion

	};
