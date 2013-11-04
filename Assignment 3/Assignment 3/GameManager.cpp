#include "StdAfx.h"
#include "GameManager.h"

#pragma region Constructor
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
GameManager::GameManager(Graphics^ startCanvas,  Rectangle startClientRectangle, Player^ startPlayer, array<Enemy^>^ startEnemies)
	{
		//
		// Create canvas from form
		//
		//formCanvas = startCanvas;
		//
		// Client viewable screen bounds
		//
		clientRectangle = startClientRectangle;

		player = startPlayer;

		enemies = startEnemies;

		//
		//
		//
		//fManager = startFrameManager;

		
		//
		// Create graphics size of the screen
		//
		//dbBitmap = gcnew Bitmap(clientRectangle.Width, clientRectangle.Height);		 
		//
		// Grab its Graphics
		//
		dbGraphics = startCanvas;	
		//
		// Create random
		//
		rGen = gcnew Random();
		
		//
		// Start level
		//
		viewportScroll = 0;	

		//
		//
		//
		/*int startY = clientRectangle.Height - 200;

		startLocations = gcnew array<Point>
		{
			Point(250,				   startY),
			Point((T_WIDTH)		- 100, startY),
			Point((T_WIDTH * 2) - 100, startY),
			Point((T_WIDTH * 3) - 100, startY),
			Point((T_WIDTH * 4) - 100, startY),
			Point((T_WIDTH * 5) - 100, startY),
		};*/

		//
		//
		//

		//
		// Create object
		//
		//InitializeGameCharacters();

		//
		// Create game with objects
		//
		InitializeGame();
	}
#pragma endregion


#pragma region Initialize Game Characters
				
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void GameManager::InitializeGameCharacters()
		{
			////
			//// Create Player
			////
			//player = gcnew Player
			//(
			//	dbGraphics, 
			//	"player", 				
			//	startLocations[PLAYER],
			//	fManager->getPlayerList()
			//);
			//			
			///// <summary>
			///// Required method for Designer support - do not modify
			///// the contents of this method with the code editor.
			///// </summary>
			//cocoon = gcnew Enemy
			//(
			//	dbGraphics, 
			//	"cocoon", 				
			//	startLocations[COCOON],
			//	fManager->getCocoonList()
			//);
			////
			////
			////			
			//makhana = gcnew Enemy
			//(
			//	dbGraphics, 
			//	"makhana", 				
			//	startLocations[MAKHANA],
			//	fManager->getMakhanaList()
			//);
			////
			////
			////
			//floppit = gcnew Enemy
			//(
			//	dbGraphics, 
			//	"floppit", 				 
			//	startLocations[FLOPPIT],
			//	fManager->getFloppitList()
			//);
			////
			////
			////
			//fluppit = gcnew Enemy
			//(
			//	dbGraphics, 
			//	"fluppit", 				
			//	startLocations[FLUPPIT],
			//	fManager->getFluppitList()
			//);
			////
			////
			////			
			//peruna = gcnew Enemy
			//(
			//	dbGraphics, 
			//	"peruna",
			//	startLocations[PERUNA],
			//	fManager->getPerunaList()
			//);

			//fManager->GarbageCollect();
			//fManager = nullptr;
			//delete fManager;

			//GC::GetTotalMemory(true);
			//GC::Collect(0);
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
			/*enemies = gcnew array<Enemy^>
			{
				floppit,
				fluppit,
				peruna,
				cocoon,
				makhana
			};*/
			
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







#pragma region Keyboard Input
		/// <summary>
		/// Takes the key code data and changes the players state.
		/// </summary>
		void GameManager::KeyDown(Keys code)
		{			
		}
		//
		//
		//
		void GameManager::KeyUp(Keys code)
		{	
		}
		//
		//
		//
		void GameManager::MouseDown(Point p)
		{
		}		
		//
		//
		//
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

			/*dbGraphics->FillRectangle(Brushes::Black, 250 + (1024 * 0), clientRectangle.Height - 200, 2 ,2);  
			dbGraphics->FillRectangle(Brushes::Black, 250 + (1024 * 1), clientRectangle.Height - 200, 2 ,2);  
			dbGraphics->FillRectangle(Brushes::Black, 250 + (1024 * 2), clientRectangle.Height - 200, 2 ,2);  
			dbGraphics->FillRectangle(Brushes::Black, 250 + (1024 * 3), clientRectangle.Height - 200, 2 ,2);  
			dbGraphics->FillRectangle(Brushes::Black, 250 + (1024 * 4), clientRectangle.Height - 200, 2 ,2);*/  

			
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
		void GameManager::ResetGame()
		{
			/*player->setLocation(startLocations[PLAYER]);
			floppit->setLocation(startLocations[FLOPPIT]);
			fluppit->setLocation(startLocations[FLUPPIT]);
			peruna->setLocation(startLocations[PERUNA]);
			cocoon->setLocation(startLocations[COCOON]);
			makhana->setLocation(startLocations[MAKHANA]);*/			
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
