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
				viewport, 
				reader, 
				tileMap, 
				STOP, 
				rGen, 
				PLAYER, 
				PLAYER_X_MAG,   
				PLAYER_Y_MAG, 
				FRAME_DELAY,
				"Sprites/1.png",
				tileMap->getMapBounds()
			);

			player->setXPos(clientRectangle.Width / HALF);
			player->setYPos(534);

			player->setState(STAND);			
			//
			// Create NPC
			//
		
			//
			// Create Items
			//
			
		
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
			double radiansAngle;

			if(code==Keys::Up)
				player->setState(NORTH); // Move player up	
			 
			if(code==Keys::Down)
				player->setState(SOUTH); // Move player down	
			 
			if(code==Keys::Right)
			{
				radiansAngle = 300 * 0.01745;
				player->setState(EAST);  // Move player right
			}
			 
			if(code==Keys::Left)
			{
				radiansAngle = 200 * 0.01745;
				player->setState(WEST);  // Move player left
			}

			if(code==Keys::Space && !player->isJumping())
			{
				player->setJumping(true);
				player->setState(JUMP);
				
				/*radiansAngle = 300 * 0.01745;

				int velocityX = Math::Cos(radiansAngle) * 20;
				int velocityY = Math::Sin(radiansAngle) * 20;*/

				player->setVelocityX(player->getvelocityX);
				player->setVelocityY(-20);
			}
		}

		void GameManager::keyUp(Keys code)
		{

			player->setState(STAND);     // Make player stand			
		}

#pragma endregion


#pragma region Game Update and Draw
		/// <summary>
		/// Updates all game components after all components are
		/// updated checks are made to see what phase the
		/// game is in for example if a game is won.
		/// </summary>
		void GameManager::updateGame()
		{
			//
			// Update hud information
			//
			viewportScroll += SPEED;
						
			//
			// Alien AI
			//	

			
			//
			// Collision Checks
			//
			player->move
			(
				player->getXPos() - viewport->getViewportWorldX(), 
				player->getYPos() - viewport->getViewportWorldY()
			);
			//
			// Move Viewport
			//
			viewport->canViewportMove(viewportScroll, 0);
			
			//
			// Updates Sprites Animation
			//
			player->updateFrame();
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
		void GameManager::drawGame()
		{		
			//
			// Draw Background to Canvas 
			//	
			
			//
			// Draw Viewport to Canvas 
			//
			viewport->viewportDraw(viewportScroll, 0);
			//
			// Draw Sprites to Canvas
			//
			player->draw
			(
				player->getXPos() - viewport->getViewportWorldX(), 
				player->getYPos() - viewport->getViewportWorldY()
			);

			
			
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
