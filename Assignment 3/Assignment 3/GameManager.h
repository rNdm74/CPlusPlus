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
#include "FrameManager.h"

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
		//FrameManager^ fManager;

		Viewport^ viewport;
		Hud^ hud;

		Rectangle clientRectangle;

		FileReader^ reader;

		
		Graphics^ dbGraphics;
		//Bitmap^ dbBitmap;

		int health;
		int mana;
		
		TileMap^ tileMap;

		Random^ rGen;

		//StreamReader^ fileReader;
		//StreamWriter^ fileWriter;		

		Player^ player;
		/*Enemy^ cocoon;
		Enemy^ makhana;
		Enemy^ floppit;
		Enemy^ fluppit;
		Enemy^ peruna;*/

		Enemy^ enemyInPlay;

		//array<Point>^ startLocations;

		
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
		GameManager(Graphics^ startCanvas,  Rectangle startClientRectangle, Player^ startPlayer, array<Enemy^>^ startEnemies);

#pragma endregion

#pragma region Methods

		void KeyDown(Keys code);
		void KeyUp(Keys code);
		void MouseDown(Point p);
		
		void Update();
		void Draw();

		void StartAttack();

		void ResetGame();

		void CheckLevelWin();
		void CheckLevelOver();		

		void InitializeGame();
		void InitializeGameCharacters();	

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

		String^ getEnemyInPlayName()				{ return enemyInPlay->getFilename(); }

		void setPlayerPotion(String^ potion)		{ player->setPotion(potion); }
		void setPlayerAbility(EState s)				{ player->setSelectedAbility(s); }

		bool isGameOver()							{ return player->isGameOver(); }
		bool clickedOnEnemy(Point p)				{ return enemyInPlay->getCollisionRectangle(viewport->getViewportWorldX(), viewport->getViewportWorldY()).Contains(p); }
		
		bool clickedOnPlayer(Point p)				{ return player->getCollisionRectangle(viewport->getViewportWorldX(), viewport->getViewportWorldY()).Contains(p); }

#pragma endregion

	};
