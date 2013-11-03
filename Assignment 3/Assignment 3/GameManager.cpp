#include "StdAfx.h"
#include "GameManager.h"

#pragma region Constructor
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
GameManager::GameManager(Graphics^ startCanvas,  Rectangle startClientRectangle)
	{
		//
		// Create canvas from form
		//
		formCanvas = startCanvas;
		//
		// Client viewable screen bounds
		//
		clientRectangle = startClientRectangle;
		//
		// Game sounds
		//

		//
		// Create graphics size of the screen
		//
		dbBitmap = gcnew Bitmap(clientRectangle.Width, clientRectangle.Height);		 
		//
		// Grab its Graphics
		//
		dbGraphics = Graphics::FromImage(dbBitmap);	
		//
		// Create random
		//
		rGen = gcnew Random();
		//
		// Player lives
		//

		//
		// Start level
		//
		viewportScroll = 0;

		//
		// Create game with objects
		//
		InitializeGame();
		//
		// Create object positions on the screen
		//
		InitializeObjectsPositons();
	}
#pragma endregion


#pragma region Game Initialization
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void GameManager::InitializeObjectsPositons()
		{
	
		}
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
			// Get highscore from saved file
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
			// Create objectmap
			//

			//
			// Create viewport
			//
			viewport = gcnew Viewport(0, 0, V_COLS, V_ROWS, tileMap, dbGraphics);

			//
			// Create Hud Image
			//
			hud = gcnew Hud(dbGraphics);
					
			//
			// Create Spritelists
			//
						
			//
			// Create Player
			//
			player = gcnew Player
			(
				dbGraphics, 
				"player", 
				gcnew array<Point>
				{
					Point(0,14),		// Idle
					Point(15,29),		// Hurt
					Point(30,110),		// Boss Hurt
					Point(111,185),		// Lesser Ice
					Point(186,242),		// Greater Ice
					Point(243,260),		// Walk
					Point(261,290),		// Basic Attack
					Point(291,327),		// Dodge
					Point(328,383),		// Electric Storm
					Point(384,425),		// Heavy Attack
					Point(426,472),		// Whirlwind Attack
					Point(473,499)		// Heal		 
				 }, 
				 250, 
				 clientRectangle.Height - 200
			);
						
			//
			// Create NPC
			//
			cocoon = gcnew Enemy
			(
				dbGraphics, 
				"cocoon", 
				gcnew array<Point>
				{
					Point(0,22),		// Idle
					Point(23,71),		// Hurt
					Point(72,104),		// Desecrate
					Point(105,158),		// Tentishock
					Point(159,215),		// Oil Spill
					Point(216,249)		// Killed
				}, 
				(T_WIDTH * 4) - 100, 
				clientRectangle.Height - 200
			);
			
			makhana = gcnew Enemy
			(
				dbGraphics, 
				"makhana", 
				gcnew array<Point>
				{
					Point(0,22),		// Idle
					Point(23,60),		// Hurt
					Point(61,134),		// Desecrate
					Point(135,188),		// Tentishock
					Point(189,259),		// Oil Spill
					Point(260,303)		// Killed
				}, 
				(T_WIDTH * 5) - 100, 
				clientRectangle.Height - 200
			);

			floppit = gcnew Enemy
			(
				dbGraphics, 
				"floppit", 
				gcnew array<Point>
				{
					Point(0,7),			// Idle
					Point(7,46),		// Hurt
					Point(46,75),		// Desecrate
					Point(75,97),		// Tentishock
					Point(97,107),		// Oil Spill
					Point(108,125)		// Killed
				}, 
				T_WIDTH - 100, 
				clientRectangle.Height - 200
			);

			fluppit = gcnew Enemy
			(
				dbGraphics, 
				"fluppit", 
				gcnew array<Point>
				{
					Point(0,7),			// Idle
					Point(7,46),		// Hurt
					Point(46,75),		// Desecrate
					Point(75,97),		// Tentishock
					Point(97,107),		// Oil Spill
					Point(108,125)		// Killed
				},
				(T_WIDTH * 2) - 100, 
				clientRectangle.Height - 200
			);

			peruna = gcnew Enemy
			(
				dbGraphics, 
				"peruna", 
				gcnew array<Point>
				{
					Point(0,12),		// Idle
					Point(13,22),		// Hurt
					Point(23,47),		// Desecrate
					Point(48,72),		// Tentishock
					Point(73,91),		// Oil Spill
					Point(92,105)		// Killed
				}, 
				(T_WIDTH * 3) - 100, 
				clientRectangle.Height - 200
			);
		
			//
			// Create Items
			//
			enemyInPlay = floppit;

			enemies = gcnew array<Enemy^>
			{
				floppit,
				fluppit,
				peruna,
				cocoon,
				makhana
			};
					
			//				
			// 
			//	
			direction = 0;
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


#pragma region Keyboard Input
		/// <summary>
		/// Takes the key code data and changes the players state.
		/// </summary>
		void GameManager::KeyDown(Keys code)
		{
			if(code == Keys::NumPad8)
				health += 20;
			if(code == Keys::NumPad9)
				mana += 20;
			if(code == Keys::NumPad1)
				viewportScroll = 0;
			if(code == Keys::NumPad2)
				viewportScroll = 1024 + 512;
			if(code == Keys::NumPad3)
				viewportScroll = 2048 + 512;
			if(code == Keys::NumPad4)
				viewportScroll = 3072 + 512;
			if(code == Keys::NumPad5)
				viewportScroll = 4096 + 1024;
		}

		void GameManager::KeyUp(Keys code)
		{	
		}

		void GameManager::MouseDown(Point p)
		{
			 /*movePoint = p;			 
			 direction = (viewport->getViewportWorldX() + movePoint.X > player->getXPos()) ? 1 : -1;
			 player->setAttacking(false);*/
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
			enemyInPlay = enemies[player->getBattle()];
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
			viewport->moveRelativeToPlayer(battles[player->getBattle()], 0);
			
			//
			// Game Win
			//
										
			//
			// Game Over
			//
						
			//
			//
			//			
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
			//enemyInPlay->DrawHud(990, 150);			

			//
			// Make Buffer Visible 
			//
			formCanvas->DrawImage(dbBitmap, clientRectangle);
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
		void GameManager::CheckLevelPhase()
		{
			
		}
		//
		//
		//	
		void GameManager::CheckLevelWin()
		{
			//
			// Checks if a level has been completed, 
			// if it is completed and not at the max level 
			// a new game is initialized, the
			// flag value, flag count and coins collected are reset
			//			
		}
		//
		//
		//		
		void GameManager::CheckLevelOver()
		{
			//
			// Checks is the game is over, either all lives lost,
			// or max level has been reached.
			// A check is done to save the high score to and external file.
			//			
		}
		//
		//
		//		
#pragma endregion
