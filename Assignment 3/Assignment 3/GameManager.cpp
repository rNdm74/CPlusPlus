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
		initializeGame();
		//
		// Create object positions on the screen
		//
		initializeObjectsPositons();
	}
#pragma endregion


#pragma region Game Initialization
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void GameManager::initializeObjectsPositons()
		{
	
		}
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void GameManager::initializeGame()
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
			// Create Background Image
			//
		
			//
			// Create Spritelists
			//
						
			//
			// Create Player
			//
			player = gcnew Sprite
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
				 clientRectangle.Height - 100
			);
						
			//
			// Create NPC
			//
			cocoon = gcnew Sprite
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
				clientRectangle.Height - 100
			);
			
			makhana = gcnew Sprite
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
				clientRectangle.Height - 100
			);

			floppit = gcnew Sprite
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
				clientRectangle.Height - 100
			);

			fluppit = gcnew Sprite
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
				clientRectangle.Height - 100
			);

			peruna = gcnew Sprite
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
				clientRectangle.Height - 100
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
		void GameManager::keyDown(Keys code)
		{
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

		void GameManager::keyUp(Keys code)
		{	
		}

		void GameManager::mouseDown(Point p)
		{
			 movePoint = p;			 
			 direction = (viewport->getViewportWorldX() + movePoint.X > player->getXPos()) ? 1 : -1;
			 player->setAttacking(false);
		}

#pragma endregion


#pragma region Game Update and Draw
		/// <summary>
		/// Updates all game components after all components are
		/// updated checks are made to see what phase the
		/// game is in for example if a game is won.
		/// </summary>
		void GameManager::update()
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
			if(!player->getCollisionRectangle(viewport->getViewportWorldX(), viewport->getViewportWorldY()).Contains(movePoint))
			{
				player->move(direction);					 
			}
			else
			{
				if(!player->isAttacking())
				{
					player->setState(IDLE);
					direction = 0;
				}					 
			}
			//
			//
			//
			if(player->isAttacking() && player->isFinishedAction())
			 {
				 player->setState(IDLE);
			 }
			//
			// Updates Sprites Animation
			//
			player->update();
			floppit->update();
			fluppit->update();
			peruna->update();
			cocoon->update();
			makhana->update();
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
		void GameManager::draw()
		{	
			//viewportScroll += 512;
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
			player->draw(player->getXPos() - viewport->getViewportWorldX(), player->getYPos() - viewport->getViewportWorldY());	
			floppit->draw(floppit->getXPos() - viewport->getViewportWorldX(), floppit->getYPos() - viewport->getViewportWorldY());
			fluppit->draw(fluppit->getXPos() - viewport->getViewportWorldX(), fluppit->getYPos() - viewport->getViewportWorldY());
			peruna->draw(peruna->getXPos() - viewport->getViewportWorldX(), peruna->getYPos() - viewport->getViewportWorldY());
			cocoon->draw(cocoon->getXPos() - viewport->getViewportWorldX(), cocoon->getYPos() - viewport->getViewportWorldY());
			makhana->draw(makhana->getXPos() - viewport->getViewportWorldX(), makhana->getYPos() - viewport->getViewportWorldY());
			//
			// Draw mouse point
			//
			dbGraphics->DrawRectangle(gcnew Pen(Color::Pink), Rectangle(movePoint.X, movePoint.Y, 2,2));

			dbGraphics->FillRectangle(Brushes::Red, Rectangle(51, 51, 79, 9));
			dbGraphics->FillRectangle(Brushes::Blue, Rectangle(51, 61, 79, 9));
			dbGraphics->DrawRectangle(gcnew Pen(Color::DimGray), Rectangle(49, 49, 82, 22));
			dbGraphics->DrawRectangle(gcnew Pen(Color::WhiteSmoke), Rectangle(50, 50, 80, 20));

			
			

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
		void GameManager::checkLevelPhase()
		{
			
		}
		//
		//
		//	
		void GameManager::checkLevelWin()
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
		void GameManager::checkLevelOver()
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
