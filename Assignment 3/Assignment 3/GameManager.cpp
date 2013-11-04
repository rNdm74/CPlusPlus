#include "StdAfx.h"
#include "GameManager.h"

#pragma region Constructor
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
GameManager::GameManager(Graphics^ startCanvas, Player^ startPlayer, array<Enemy^>^ startEnemies)
	{
		//
		//
		//
		player = startPlayer;

		//
		//
		//
		enemies = startEnemies;				
		
		//
		// Grab its Graphics
		//
		dbGraphics = startCanvas;	

		//
		// Create random
		//
		rGen = gcnew Random();
		
		//
		// Create game with objects
		//
		InitializeGame();
	}
#pragma endregion

#pragma region Initialize Game
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void GameManager::InitializeGame()
		{
			//
			// Clean up
			//
			
			//
			// Create the csv file reader
			//
			reader = gcnew FileReader();

			//
			// Create tilemap
			//
			tileMap = gcnew TileMap(dbGraphics, reader->getMap("tilemap.map"));

			//
			// Create viewport
			//
			viewport = gcnew Viewport(0, 0, V_COLS, V_ROWS, tileMap, dbGraphics);

			//
			// Create Hud Image
			//
			hud = gcnew Hud(dbGraphics);
					
			//
			// Create enemies
			//
						
			//
			//
			//
			enemyInPlay = enemies[0];			
			
			//
			//
			//
			battles = gcnew array<int>
			{
				0,
				1024 + 512,
				2048 + 512,
				3072 + 512,
				4096 + 1024
			};
		}
#pragma endregion


#pragma region Game Update and Draw
		/// <summary>
		/// Updates all game components after all components are
		/// updated checks are made to see what phase the
		/// game is in for example if a game is won.
		/// </summary>
		void GameManager::Update()
		{	
			enemyInPlay = enemies[player->getBattleSelection()];
			//
			// Update hud information
			//
			hud->Update(player, enemyInPlay);
					
			//
			// AI
			//	
			player->Update();
			player->UpdateState(enemyInPlay);	
			player->PerformAction(enemyInPlay);

			

			if(player->enemyChooseAttack() && enemyInPlay->isAlive())
			{				
				enemyInPlay->setSelectedAbility(safe_cast<EState>(rGen->Next(2,5)));
				enemyInPlay->setAttackStarted();
				player->setChooseAttack(false);
			}

			enemyInPlay->Update();
			enemyInPlay->UpdateState(player);
			enemyInPlay->PerformAction(player);

			//
			// Move Viewport
			//	
			viewport->moveRelativeToPlayer(battles[player->getBattleSelection()], 0);			
		}
		/// <summary>
		/// Draws all game components to an off screen canvas.
		/// The components are drawn in order: 
		/// background, viewport, sprites, form
		/// Once all drawn to the canvas it is then 
		/// drawn to the main form canvas.
		/// </summary>		
		void GameManager::Draw()
		{			
			//
			// Draw Viewport to Canvas 
			//			
			viewport->viewportDraw();

			//
			// Draw Sprites to Canvas
			//			
			player->Draw(player->getXPos() - viewport->getViewportWorldX(), player->getYPos() - viewport->getViewportWorldY());	
			enemyInPlay->Draw(enemyInPlay->getXPos() - viewport->getViewportWorldX(), enemyInPlay->getYPos() - viewport->getViewportWorldY());
			
			//
			// Draw HUD
			//
			hud->Draw();
		}
#pragma endregion


#pragma region Game Phase Checks
		/// <summary>
		/// Checks the three main phases in the game
		/// the contents of this method with the code editor.
		/// </summary>
		void GameManager::StartAttack()
		{
			player->setAttackStarted();
		}
		//
		//
		//
		bool GameManager::CanUseAbility(EState selectedAbility)	
		{
			int availableMana = 132 - player->getMana();
			int abilityCost = 5 * safe_cast<int>(selectedAbility);
		
			return (abilityCost < availableMana);
		}
		//
		//
		//		
#pragma endregion
