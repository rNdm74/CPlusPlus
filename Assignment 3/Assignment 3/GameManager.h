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

		RectangleF srcRectangle;
		Image^ clockBackground;
		Image^ clockTick;
		Image^ clockOverlay;
		static int turnTime = 1;
		int clockTime;
		int currentFrame;
		int nFrames;
		int frameWidth;
		int frameHeight;

		int xPos;
		int yPos;

#pragma endregion

	public:
		GameManager(Graphics^ startCanvas, Player^ startPlayer, array<Enemy^>^ startEnemies);
	
		void Update();
		void Draw();

		void StartAttack();	
		void InitializeGame();
		bool CanUseAbility(EState selectedAbility);	

#pragma region Gets/Sets

		String^ getPlayerHealth()					{ return (132 - player->getHealth()).ToString(); }
		String^ getPlayerMana()						{ return (132 - player->getMana()).ToString(); }
		String^ getEnemyHealth()					{ return (132 - enemyInPlay->getHealth()).ToString(); }

		bool isPlayerHit()							{ return player->isHurt(); }
		bool isPlayerTurn()							{ return player->isWaiting(); }
		bool hasPlayerUsedAbility()					{ return player->hasUsedAbility(); }

		bool isEnemyHit()							{ return enemyInPlay->isHurt(); }
		bool isEnemyTurn()							{ return enemyInPlay->isWaiting(); }
		bool hasEnemyUsedAbility()					{ return enemyInPlay->hasUsedAbility(); }
		
		int getAvailableMana()						{ return (132 - player->getMana()); }
		String^ getEnemyInPlayName()				{ return enemyInPlay->getFilename(); }

		void setPlayerHealthCost(int hc)		    { player->setHealthCost(hc); }
		void setPlayerManaCost(int mc)				{ player->setManaCost(mc); }

		void setPlayerPotion(String^ potion)		{ player->setPotion(potion); }
		void setPlayerAbility(EState s)				{ player->setSelectedAbility(s); }

		bool isGameOver()							{ return player->isGameOver(); }
		//bool clickedOnEnemy(Point p)				{ return enemyInPlay->getCollisionRectangle(viewport->getViewportWorldX(), viewport->getViewportWorldY()).Contains(p); }		
		//bool clickedOnPlayer(Point p)				{ return player->getCollisionRectangle(viewport->getViewportWorldX(), viewport->getViewportWorldY()).Contains(p); }

		void showInventory(bool inventoryClicked)	{ if(inventoryClicked){ hud->showInventory();}else{hud->hideInventory();}}				

#pragma endregion

	};
