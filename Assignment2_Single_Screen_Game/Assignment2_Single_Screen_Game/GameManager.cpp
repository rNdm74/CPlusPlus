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
		// Create game with objects
		//
		initializeGame();
		//
		// Create object positions on the screen
		//
		initializeObjectsPositons();
	}
#pragma endregion


#pragma region Game Phaze Checks
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void GameManager::initializeObjectsPositons()
		{
			player->setStartPosition(objectMap->getSpawnPosition(PLAYER, player->getHeight()));		
			player->setWalking(false);

			array<int>^ spriteType = gcnew array<int>
			{
				ALIEN_ONE, 
				ALIEN_TWO, 
				ALIEN_THREE, 
				ALIEN_FOUR
			};

			for(int i = 0; i < aliens->Length; i++)
			{
				Point startPos = objectMap->getSpawnPosition(spriteType[i], aliens[i]->getHeight());

				aliens[i]->setXPos(startPos.X);
				aliens[i]->setYPos(startPos.Y);
			}

			spriteType = gcnew array<int>
			{
				RED_FLAG, 
				BLUE_FLAG, 
				YELLOW_FLAG
			};

			for(int i = 0; i < flags->Length; i++)
			{
				Point startPos = objectMap->getSpawnPosition(spriteType[i], flags[i]->getHeight());

				flags[i]->setXPos(startPos.X);
				flags[i]->setYPos(startPos.Y);
			}
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
			reader = gcnew CSVReader();
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
			// Create viewport
			//
			background = Image::FromFile("Images/bg.png");		
			//
			// Create spritelist
			//
			spriteList = gcnew SpriteList(foreground);
			//
			// Create Player
			//
			player = gcnew Sprite
			(
				tileMap, 
				foreground,
				STOP, 
				PLAYER,
				dbGraphics, 
				"Images/player.png",
				rGen, 
				reader->getPlayerMap(),
				PLAYER_X_MAG, 
				PLAYER_Y_MAG, 
				FRAME_DELAY
			);			
			//
			// Create NPCs
			//
			aliens = gcnew array<Sprite^>(N_ALIENS);		
			for(int i = 0; i < aliens->Length; i++)
			{
				int alien = rGen->Next(1, 3); // random for different aliens

				aliens[i] = gcnew Sprite
				(
					tileMap,
					foreground,
					BOUNCE,
					ENEMY,
					dbGraphics,				
					"Images/enemy" + alien + ".png",
					rGen,
					(alien == 1) ? reader->getPlayerMap() : reader->getAlienMap(),
					ALIEN_X_MAG,
					ALIEN_Y_MAG,
					FRAME_DELAY
				);			
			}
			//
			// Create Flags
			//
			flags = gcnew array<Sprite^>(N_FLAG);		
			for(int i = 0; i < flags->Length; i++)
			{			
				flags[i] = gcnew Sprite
				(
					tileMap,
					foreground,
					STOP,
					FLAG,
					dbGraphics,
					"Images/flag" + i + ".png",
					rGen,
					reader->getItemMap(),
					FLAG_X_MAG,
					FLAG_Y_MAG,
					FLAG_FRAME_DELAY
				);			
			}
			//				
			// Adds all game characters to the spritelist
			//
			for(int i = 0; i < flags->Length; i++)		// FLAGS
				spriteList->add(flags[i]);			

			for(int i = 0; i < aliens->Length; i++)		// ALIENS
				spriteList->add(aliens[i]);			

			spriteList->add(player);					// PLAYER
		}
#pragma endregion


#pragma region Keyboard Input
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void GameManager::keyDown(KeyEventArgs^  e)
		{
			 if(e->KeyCode==Keys::Up)
				player->setBearing(NORTH); // Move player up	
			 
			 if(e->KeyCode==Keys::Down)
				player->setBearing(SOUTH); // Move player down	
			 
			 if(e->KeyCode==Keys::Right)
				player->setBearing(EAST);  // Move player right
			 
			 if(e->KeyCode==Keys::Left)
				player->setBearing(WEST);  // Move player left
		}
		void GameManager::keyUp(KeyEventArgs^  e)
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
			flagCount = spriteList->getFlags();
			coinCount = spriteList->getCoins();
			score = spriteList->getScore();
			lives = spriteList->getLives();
			//
			// Set Viewport Position on Player
			//
			int playerX = player->getXPos() + (player->getWidth() / 2);
			int playerY = player->getYPos() + (player->getHeight() / 2);
			foreground->moveRelativeToPlayer(playerX, playerY);		
			//
			// Updates Sprites Animation
			//
			spriteList->update();		
			//
			// Game Phaze
			//
			checkGamePhaze();		
			//
			// Game Win
			//
			checkGameWin();				
			//
			// Game Over
			//
			checkGameOver();
			//
			// NPC AI
			//	
			for(int c = 0; c < aliens->Length; c++)
				aliens[c]->wander();
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
			dbGraphics->DrawString("Flags: " + flagCount.ToString(), gcnew Font("Comic Sans MS", 16), Brushes::WhiteSmoke, 10, 10);
			dbGraphics->DrawString("Coins: " + coinCount.ToString(), gcnew Font("Comic Sans MS", 16), Brushes::WhiteSmoke, 110, 10);
			dbGraphics->DrawString("Lives: " + lives.ToString(), gcnew Font("Comic Sans MS", 16), Brushes::WhiteSmoke, 210, 10);
			dbGraphics->DrawString("Score: " + score.ToString(), gcnew Font("Comic Sans MS", 16), Brushes::WhiteSmoke, 310, 10);
			dbGraphics->DrawString("HighScore: " + highscore.ToString(), gcnew Font("Comic Sans MS", 16), Brushes::WhiteSmoke, 500, 10);
			//
			// Draw Viewport to Canvas 
			//
			foreground->viewportDraw(0, 0);
			//
			// Draw Sprites to Canvas
			//
			spriteList->renderSprites(foreground->getViewportWorldX(), foreground->getViewportWorldY());	
			//
			// Make Buffer Visible 
			//
			canvas->DrawImage(dbBitmap, clientRectangle);
		}
#pragma endregion


#pragma region Game Phaze Checks
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void GameManager::checkGamePhaze()
		{
			if(flagCount == 3)					// All flags have been collected
			{
				spriteList->setFlags(0);		// Reset Flags

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

				spriteList->setScore(score);	// Set current score to new game
				spriteList->setLives(lives);	// Set current lives to new game

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
