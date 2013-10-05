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
		// S
		//
		//lives = N_LIVES;
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
			playerList->setSpritePositions(spawnMap);
			
			alienList->setSpritePositions(spawnMap);

			flagList->setSpritePositions(spawnMap);			
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
			delete fileReader;
			delete reader;
			delete tileMap;
			delete spawnMap;
			delete foreground;
			delete background;
			delete alienList;
			delete flagList;
			delete playerList;
			//
			// Get highscore from saved file
			//
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
			spawnMap = gcnew SpawnMap(reader->getSpawnMap(), reader->getCoinMap());
			//
			// Create viewport
			//
			foreground = gcnew Viewport(0, 0, N_COLS, N_ROWS, tileMap, dbGraphics);
			//
			// Create Background Image
			//
			background = Image::FromFile("Images/playscreen.png");			
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
					"Images/player.png",
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
						BOUNCE,
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
			for(int flag = BLUE_FLAG; flag < GREEN_FLAG + 1; flag++)		
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
				player->setState(NORTH); // Move player up	
			 
			 if(code==Keys::Down)
				player->setState(SOUTH); // Move player down	
			 
			 if(code==Keys::Right)
				player->setState(EAST);  // Move player right
			 
			 if(code==Keys::Left)
				player->setState(WEST);  // Move player left
		}
		void GameManager::keyUp(Keys code)
		{
			player->setState(STAND);     // Make player stand
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
			// Update hud information
			//
			lives = player->getLives();
			flag = flagList->getFlag();
			flagCount = flagList->getFlagCount();
			coinCount = player->getCoins();
			score = player->getScore() + flagList->getScore();
			if(score > highscore) highscore = score;			
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
			// Game Phase
			//
			checkLevelPhase();		
			//
			// Game Win
			//
			checkLevelWin();				
			//
			// Game Over
			//
			checkLevelOver();
			//
			//
			//			
		}
		
		void GameManager::drawGame()
		{		
			//
			// Draw Background to Canvas 
			//	
			dbGraphics->DrawImageUnscaled(background, 0, 0, clientRectangle.Width, clientRectangle.Height);
			//
			// Draw Viewport to Canvas 
			//
			foreground->viewportDraw(0, 0);
			//
			// Draw Sprites to Canvas
			//
			flagList->draw();
			alienList->draw();
			playerList->draw();
			//
			// Make Buffer Visible 
			//
			canvas->DrawImage(dbBitmap, clientRectangle);
		}
#pragma endregion


#pragma region Game Phase Checks
		/// <summary>
		/// Checks the three main phases in the game
		/// the contents of this method with the code editor.
		/// </summary>
		//
		//
		//
		void GameManager::checkLevelPhase()
		{
			//
			// Required method for Designer support - do not modify
			// the contents of this method with the code editor.
			//
			if(flagCount == 4)										// All flags have been collected
			{
				flagList->setFlagCount(0);							// Reset Flags must have to pick up coins
				//flagList->setFlag(0);								// Sets Flag number to 0 for reset on level win				
				spawnMap->addCoinsToGame(tileMap);					// Makes coins visible					
				tileMap->setMapValue(4, 9, 9);						// Shows exit post
			}
		}
		//
		//
		//	
		void GameManager::checkLevelWin()
		{
			//
			// Checks if a game is won, if player has won 
			// Make a new game and transfers current lives 
			// and score to new game
			//
			levelover = player->isLevelWin();						// Level has been won

			if(levelover)								
			{				 
				initializeGame();									// Create a game
				initializeObjectsPositons();						// Positions sprites on screen

				flagList->setFlag(0);
				flagList->setFlagCount(flagCount);
				player->setCoins(0);				

				player->setLevelWin(false);							// Resets level win												
			}
		}
		//
		//
		//		
		void GameManager::checkLevelOver()
		{
			//
			// The check game over method checks is the game is over
			// If the game is over sets a flag and records the highscore
			//
			if(lives == 0)											// All lives lost
			{	
				if(score >= highscore)								// If playerscore is greater write to file				
				{
					fileWriter = gcnew StreamWriter("data.dat");	// Open file
					fileWriter->Write(score.ToString());			// Write to score
					fileWriter->Close();							// Close file

					delete fileWriter;
				}	

				if(player->isAlive())
				{
					gameover = true;								// Game over is set		
					player->setGameOver(gameover);					// Sets gameover to true
				}
			}
		}
		//
		//
		//		
#pragma endregion
