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
			hud = Image::FromFile("hud.png");

			healthImage = gcnew Bitmap(132, 132, PixelFormat::Format32bppArgb);
			manaImage = gcnew Bitmap(132, 132, PixelFormat::Format32bppArgb);		

			hGraphics = Graphics::FromImage(healthImage);
			mGraphics = Graphics::FromImage(manaImage);

			hGraphics->FillEllipse(gcnew SolidBrush(Color::FromArgb(200, 255, 0, 0)), Rectangle(0,0,132,132)); 
			mGraphics->FillEllipse(gcnew SolidBrush(Color::FromArgb(200, 0, 0, 255)), Rectangle(0,0,132,132));

			//mana = 100;
			//health = 100;
			
			for(int x = 0; x < 132; x++)
				for(int y = 0; y < 64; y++)
					healthImage->SetPixel(x, y, Color::Transparent);

			for(int x = 0; x < 132; x++)
				for(int y = 0; y < mana; y++)
					manaImage->SetPixel(x, y, Color::Transparent);
		
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
					
			//				
			// 
			//	
			direction = 0;
			//
			//
			//
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
			//
			// Update hud information
			//
									
			//
			// Alien AI
			//	
			
			//
			// Collision Checks
			//
			
			//
			// Move Viewport
			//			
			viewport->moveRelativeToPlayer(viewportScroll, 0);
			
			//
			// Move Sprites
			//
			//bool canAttack = player->getCollisionRectangle(viewport->getViewportWorldX(), viewport->getViewportWorldY()).Contains(movePoint);
			//bool isHome = player->getCollisionRectangle(viewport->getViewportWorldX(), viewport->getViewportWorldY()).Contains(Point(250, clientRectangle.Height - 250));

			//if(canAttack == false)
			//{
			//	player->move(direction);					 
			//}
			//else
			//{
			//	direction = 0;

			//	if(player->isAttacking() == false && isHome == false)
			//	{					
			//		player->setAttacking(true);
			//		player->setState(LESSER_WAND);						
			//	}				 
			//}

			//if(isHome)
			//{
			//	floppit->setState(IDLE);

			//	player->setAttacking(false);
			//	player->setState(IDLE);

			//	direction = 0;
			//}
			////
			////
			////
			//if(floppit->isAttacking() && floppit->isFinishedAction())
			//{
			//	floppit->setAttacking(false);
			//	floppit->setState(IDLE);	 
			//}
			////
			////
			////
			//if(player->isAttacking() && player->isFinishedAction())
			//{
			//	player->setAttacking(false);
			//	player->setState(IDLE);

			//	fluppit->setAttacking(true);
			//	floppit->setState(HURT);

			//	movePoint = Point(250, clientRectangle.Height - 250);
			//	mouseDown(movePoint);

			//}
			if(player->enemyChooseAttack())
			{				
				floppit->setSelectedAbility(safe_cast<EState>(rGen->Next(2,4)));
				floppit->setAttackStarted();
				player->setChooseAttack(false);
			}


			/*if(player->isHit())
			{

			}

			if(player->usedAbility())
			{
				battleTime = 0;
				
				
			}*/
			//
			// Health Hud Information
			//
			//if(player->isHurt())
			
			
				/*if(health >= 0)  health--;

				
				if(mana >= 0)  mana--;*/

			health = player->getHealth();

			if(health > 132) health = 132;

			if(healthRegen > 15 && health >= 0)
			{
				hGraphics->FillEllipse(gcnew SolidBrush(Color::FromArgb(200, 255, 0, 0)), Rectangle(0,0,132,132));
				
				for(int x = 0; x < 132; x++)
					for(int y = 0; y < health; y++)
						healthImage->SetPixel(x, y, Color::Transparent);

				//player->setHealth(-1);

				healthRegen = 0;
			}

			//
			// Mana Hud Information
			//
			//if(player->hasUsedAbility())
			mana = player->getMana();	
			if(mana > 132) mana = 132;

			if(manaRegen > 15 && mana >= 0)
			{
				mGraphics->FillEllipse(gcnew SolidBrush(Color::FromArgb(200, 0, 0, 255)), Rectangle(0,0,132,132));

				for(int x = 0; x < 132; x++)
					for(int y = 0; y < mana; y++)
						manaImage->SetPixel(x, y, Color::Transparent);	

				player->setMana(-1);

				manaRegen = 0;
			}

			if(player->isWaiting())
			{
				floppit->UpdateState(player);
				floppit->PerformAction();
			}
			
			if(floppit->isWaiting())
			{
				player->UpdateState(floppit);
				player->PerformAction();
			}

			//spriteInPlay = () ? floppit : player;

			
			//
			// Updates Sprites Animation
			//
			player->Update();
			floppit->Update();
			fluppit->Update();
			peruna->Update();
			cocoon->Update();
			makhana->Update();
			//
			// Game Win
			//
							
			//
			// Game Over
			//
			healthRegen++;	
			manaRegen++;
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
			// Draw Background to Canvas 
			//	
			
			//
			// Draw Viewport to Canvas 
			//			
			viewport->viewportDraw();
			//
			// Draw Sprites to Canvas
			//			
			player->Draw(player->getXPos() - viewport->getViewportWorldX(), player->getYPos() - viewport->getViewportWorldY());	
			floppit->Draw(floppit->getXPos() - viewport->getViewportWorldX(), floppit->getYPos() - viewport->getViewportWorldY());
			fluppit->Draw(fluppit->getXPos() - viewport->getViewportWorldX(), fluppit->getYPos() - viewport->getViewportWorldY());
			peruna->Draw(peruna->getXPos() - viewport->getViewportWorldX(), peruna->getYPos() - viewport->getViewportWorldY());
			cocoon->Draw(cocoon->getXPos() - viewport->getViewportWorldX(), cocoon->getYPos() - viewport->getViewportWorldY());
			makhana->Draw(makhana->getXPos() - viewport->getViewportWorldX(), makhana->getYPos() - viewport->getViewportWorldY());
			//
			// Draw mouse point
			//
			dbGraphics->DrawRectangle(gcnew Pen(Color::Pink), Rectangle(movePoint.X, movePoint.Y, 2,2));
			
			/*dbGraphics->DrawImageUnscaledAndClipped(healthImage, Rectangle(12, 12, 132, 132));
			dbGraphics->DrawImageUnscaledAndClipped(manaImage, Rectangle(860, 12, 132,132));*/
			dbGraphics->DrawImageUnscaledAndClipped(healthImage, Rectangle(358, 581, 132, 132));
			dbGraphics->DrawImageUnscaledAndClipped(manaImage, Rectangle(516, 581, 132,132));
			dbGraphics->DrawImage(hud, 0, 0, 1024, 768);

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
