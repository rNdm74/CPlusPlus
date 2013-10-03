#include "StdAfx.h"
#include "GameManager.h"

#pragma region Constructor
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
GameManager::GameManager(Graphics^ startCanvas, Rectangle startClientRectangle)
	{
		//
		// Create canvas from form
		//
		canvas = startCanvas;
		//
		// Client viewable screen bounds
		//
		clientRectangle = startClientRectangle;
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
		// Font for game
		//
		font = gcnew Font("Comic Sans MS", 16);
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
			playerList->setSpritePositions(objectMap);
			
			alienList->setSpritePositions(objectMap);

			flagList->setSpritePositions(objectMap);			
		}
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void GameManager::initializeGame()
		{
			fileReader = gcnew StreamReader("data.dat");
			String^ line = fileReader->ReadLine();
			highscore = int::Parse(line);		
			fileReader->Close();
			//
			// Create the csv file reader
			//
			reader = gcnew CSVReader(rGen);
			//
			// Create tilemap
			//
			tileMap = gcnew TileMap(dbGraphics, reader->getTileMap());
			//
			// Create objectmap
			//
			objectMap = gcnew ObjectMap(reader->getObjectMap(), reader->getCoinMap());
			//
			// Create viewport
			//
			foreground = gcnew Viewport(0, 0, N_COLS, N_ROWS, tileMap, dbGraphics);
			//
			// Create Background Image
			//
			background = Image::FromFile("Images/bg.png");
			//
			// Create Spritelists
			//
			alienList = gcnew SpriteList(foreground);
			flagList = gcnew SpriteList(foreground);
			playerList = gcnew SpriteList(foreground);
			//
			// Create Player
			//
			playerList->add
			(
				gcnew Sprite
				(
					dbGraphics,
					foreground,
					reader,
					tileMap,					
					STOP,
					rGen, 
					PLAYER,
					PLAYER_X_MAG, 
					PLAYER_Y_MAG, 
					FRAME_DELAY,
					PLAYER_FILENAME,
					tileMap->getBounds()
				)	
			);	

			player = playerList->get(0);
			//
			// Create Aliens
			//
			for(int alien = ALIEN_ONE; alien <= ALIEN_FOUR; alien++)		
			{
				alienList->add
				(
					gcnew Sprite
					(
						dbGraphics,
						foreground,
						reader,
						tileMap,						
						STOP,
						rGen,
						alien,
						ALIEN_X_MAG,
						ALIEN_Y_MAG,
						FRAME_DELAY,
						"Images/enemy"+ alien +".png",
						tileMap->getBounds()
					)
				);
			}			
			//
			// Create Flags
			//
			for(int flag = RED_FLAG; flag < YELLOW_FLAG + 1; flag++)		
			{
				flagList->add
				(
					gcnew Sprite
					(
						dbGraphics,
						foreground,
						reader,
						tileMap,						
						STOP,						
						rGen,
						flag,
						FLAG_X_MAG,
						FLAG_Y_MAG,
						FLAG_FRAME_DELAY,
						"Images/flag"+ flag +".png",
						tileMap->getBounds()						
					)
				);	
			}			
			//				
			// 
			//				
		}
#pragma endregion


#pragma region Keyboard Input
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void GameManager::keyDown(Keys code)
		{
			 if(code==Keys::Up)
				player->setBearing(NORTH); // Move player up	
			 
			 if(code==Keys::Down)
				player->setBearing(SOUTH); // Move player down	
			 
			 if(code==Keys::Right)
				player->setBearing(EAST);  // Move player right
			 
			 if(code==Keys::Left)
				player->setBearing(WEST);  // Move player left
		}
		void GameManager::keyUp(Keys code)
		{
			player->setBearing(STAND);     // Make player stand
		}
#pragma endregion


#pragma region Game Update and Draw
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void GameManager::updateGame()
		{
			//
			// Get hud information
			//
			flagCount = flagList->getFlags();
			coinCount = player->getCoins();
			score = player->getScore() + flagList->getScore();
			lives = player->getLives();
			//
			// Set Viewport Position on Player
			// 
			int playerX = player->getXPos() + (player->getWidth() / HALF);
			int playerY = player->getYPos() + (player->getHeight() / HALF);
			foreground->moveRelativeToPlayer(playerX, playerY);	
			//
			// Alien AI
			//	
			alienList->spriteAI();
			//
			// Collision Checks
			//
			alienList->checkCollisions(player);
			flagList->pickupItem(player);
			playerList->collectCoin();
			//
			// Updates Sprites Animation
			//
			flagList->update();
			alienList->update();
			playerList->update();
			//
			// Game Phaze
			//
			checkGamePhase();		
			//
			// Game Win
			//
			checkGameWin();				
			//
			// Game Over
			//
			checkGameOver();
			//
			//
			//			
		}
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void GameManager::drawGame()
		{		
			//
			// Draw Background to Canvas 
			//	
			dbGraphics->DrawImageUnscaled(background, Rectangle(0, 0, clientRectangle.Width, clientRectangle.Height));
			//
			// Draw hud information 
			//
			dbGraphics->DrawString("Score: " + score.ToString(), font, Brushes::WhiteSmoke, 10, 10);
			dbGraphics->DrawString("Flags: " + flagCount.ToString(), font, Brushes::WhiteSmoke, 370, 10);
			dbGraphics->DrawString("Coins: " + coinCount.ToString(), font, Brushes::WhiteSmoke, 470, 10);
			dbGraphics->DrawString("Lives: " + lives.ToString(), font, Brushes::WhiteSmoke, 570, 10);			
			dbGraphics->DrawString("High Score: " + highscore.ToString(), font, Brushes::WhiteSmoke, 800, 10);
			//
			// Draw Viewport to Canvas 
			//
			foreground->viewportDraw(0, 0);
			//
			// Draw Sprites to Canvas
			//
			flagList->renderSprites(foreground->getViewportWorldX(), foreground->getViewportWorldY());
			alienList->renderSprites(foreground->getViewportWorldX(), foreground->getViewportWorldY());
			playerList->renderSprites(foreground->getViewportWorldX(), foreground->getViewportWorldY());
			//
			// Make Buffer Visible 
			//
			canvas->DrawImage(dbBitmap, clientRectangle);
		}
#pragma endregion


#pragma region Game Phase Checks
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void GameManager::checkGamePhase()
		{
			if(flagCount == 3)					// All flags have been collected
			{
				flagList->setFlags(0);			// Reset Flags must have to pick up coins

				tileMap->setMapValue(1, 9, 9);	// Shows exit post

				addCoinsToGame();				// Makes coins visible					
			}
		}
		/// <summary>
		/// Checks if a game is won, if player has won 
		/// Make a new game and transfers current lives 
		/// and score to new game
		/// </summary>
		void GameManager::checkGameWin()
		{
			if(player->isLevelWin())			// Level has been won
			{		
				initializeGame();				// Create a game
				initializeObjectsPositons();	// Positions sprites on screen

				flagList->setFlags(flagCount);

				player->setCoins(coinCount);
				player->setScore(score);		// Set current score to new game
				player->setLives(lives);		// Set current lives to new game

				player->setLevelWin(false);		// Resets level win 
			}
		}
		/// <summary>
		/// The check game over method checks is the game is over
		/// If the game is over sets a flag and records the highscore
		/// </summary>
		void GameManager::checkGameOver()
		{
			if(lives == 0)											// All lives lost
			{		
				player->setGameOver(true);							// Sets gameover to true
				gameover = player->isGameOver();					// Game over is set				
				
				if(score > highscore)								// If playerscore is greater write to file				
				{
					fileWriter = gcnew StreamWriter("data.dat");	// Open file
					fileWriter->Write(score.ToString());			// Write to score
					fileWriter->Close();							// Close file
				}		
			}
		}
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void GameManager::addCoinsToGame()
		{			
			array<int, 2>^ coinMap = reader->getCoinMap();

			for(int col = 0; col < N_COLS; col++)
			{
				for(int row = 0; row < N_ROWS; row++)
				{
					int coin = coinMap[row, col];

					if(coin != 0)
						tileMap->setMapValue(col, row, coin);
				}
			}
		}
#pragma endregion
