#pragma once

#include "Hud.h"
#include "Constants.h"
#include "Sprite.h"
#include "Player.h"
#include "Enemy.h"
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
		Graphics^ dbGraphics;

		TileMap^ tileMap;

		FileReader^ reader;

		Viewport^ viewport;

		Hud^ hud;		

		Random^ rGen;	

		Player^ player;
		Enemy^ enemyInPlay;

		array<Enemy^>^ enemies;
		array<int>^ battles;		
		
		String^ whosTurntIsIt;

#pragma endregion

	public:
		GameManager(Graphics^ startCanvas, Player^ startPlayer, array<Enemy^>^ startEnemies);
	
		void Update();
		void Draw();

		void StartAttack();	
		void InitializeGame();
		bool CanUseAbility(EState selectedAbility);	

#pragma region Gets/Sets

		bool playerHasWon()							{ return (enemyInPlay->getHealth() >= 131); }
		bool playerHasLost()						{ return (player->getHealth() >= 131); }

		bool isPlayerTurn()							{ return enemyInPlay->isWaiting(); }
		//bool isEnemyTurn()							{ return if(enemyInPlay->isWaiting()); }
		
		int getAvailableMana()						{ return (132 - player->getMana()); }
		String^ getEnemyInPlayName()				{ return enemyInPlay->getFilename(); }

		void setPlayerPotion(String^ potion)		{ player->setPotion(potion); }
		void setPlayerAbility(EState s)				{ player->setSelectedAbility(s); }

		bool isGameOver()							{ return player->isGameOver(); }
		bool clickedOnEnemy(Point p)				{ return enemyInPlay->getCollisionRectangle(viewport->getViewportWorldX(), viewport->getViewportWorldY()).Contains(p); }		
		bool clickedOnPlayer(Point p)				{ return player->getCollisionRectangle(viewport->getViewportWorldX(), viewport->getViewportWorldY()).Contains(p); }

#pragma endregion

	};
