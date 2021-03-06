#include "StdAfx.h"
#include "GameManager.h"

#pragma region Constructor
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
GameManager::GameManager(Graphics^ startCanvas,  Rectangle startClientRectangle, SoundManager^ soundManager)
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
		sManager = soundManager;
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
		lives = N_LIVES;
		//
		// Start level
		//
		level = START_LEVEL;
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
			playerList->setSpritePositions(mManager); 
			
			alienList->setSpritePositions(mManager);

			flagList->setSpritePositions(mManager);			
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
			delete mManager;
			delete viewport;
			delete background;
			delete alienList;
			delete flagList;
			delete playerList;			
			//
			// Get highscore from saved file
			//
			fileReader = gcnew StreamReader(DATAFILE);
			String^ line = fileReader->ReadLine();
			highscore = int::Parse(line);		
			fileReader->Close();
			//
			// Create the csv file reader
			//
			reader = gcnew FileReader();
			//
			// Create tilemap
			//
			tileMap = gcnew TileMap(dbGraphics, reader->getTileMap(level));
			//
			// Create objectmap
			//
			mManager = gcnew MapManager(reader->getSpawnMap(level), reader->getCoinMap(level));
			//
			// Create viewport
			//
			viewport = gcnew Viewport(0, 0, N_COLS, N_ROWS, tileMap, dbGraphics);
			//
			// Create Background Image
			//
			background = Image::FromFile(BACKGROUND);			
			//
			// Create Spritelists
			//
			alienList = gcnew SpriteList(viewport);
			flagList = gcnew SpriteList(viewport);
			playerList = gcnew SpriteList(viewport);
			//
			// Create Player
			//
			playerList->add(Create(STOP, PLAYER, PLAYER_X_MAG, PLAYER_Y_MAG, FRAME_DELAY));				
			player = playerList->get(0);	// Gets the player from his list
			player->setLives(lives);		// passes currents lives to player
			//
			// Create Aliens
			//
			for(int alien = ALIEN_ONE; alien <= ALIEN_FOUR; alien++)
				alienList->add(Create(BOUNCE, alien, ALIEN_X_MAG, ALIEN_Y_MAG, FRAME_DELAY));
			//
			// Create Flags
			//
			for(int flag = BLUE_FLAG; flag <= GREEN_FLAG; flag++)
				flagList->add(Create(STOP, flag, FLAG_X_MAG, FLAG_Y_MAG, FLAG_FRAME_DELAY));	
			//				
			// 
			//			
		}

		Sprite^ GameManager::Create(EAction action, int type, int xMag, int yMag, int frameDelay)
{
	return gcnew Sprite
	(
		dbGraphics,
		viewport,
		reader,
		tileMap,					
		action,
		rGen, 
		type,
		xMag, 
		yMag, 
		frameDelay,
		"Images/Sprites/" + type + ".png",
		tileMap->getBounds()
	);
	////
	//// 
	////
	//if(type == PLAYER)
	//{
	//	return gcnew Sprite
	//	(
	//		dbGraphics,
	//		viewport,
	//		reader,
	//		tileMap,					
	//		STOP,
	//		rGen, 
	//		type,
	//		xMag, 
	//		yMag, 
	//		frameDelay,
	//		"Images/Sprites/" + type + ".png",
	//		tileMap->getBounds()
	//	);
	//}
	////
	////
	////
	//if(type == ALIEN_ONE || type == ALIEN_TWO || type == ALIEN_THREE || type == ALIEN_FOUR)
	//{
	//	return gcnew Sprite
	//	(
	//		dbGraphics,
	//		viewport,
	//		reader,
	//		tileMap,						
	//		BOUNCE,
	//		rGen,
	//		type,
	//		ALIEN_X_MAG,
	//		ALIEN_Y_MAG,
	//		FRAME_DELAY,
	//		"Images/enemy" + type + ".png",
	//		tileMap->getBounds()
	//	);
	//}
	////
	////
	////
	//if(type == BLUE_FLAG || type == ORANGE_FLAG || type == YELLOW_FLAG || type == GREEN_FLAG)
	//{
	//	return gcnew Sprite
	//	(
	//		dbGraphics,						// 
	//		viewport,
	//		reader,
	//		tileMap,						
	//		STOP,						
	//		rGen,
	//		type,
	//		FLAG_X_MAG,
	//		FLAG_Y_MAG,
	//		FLAG_FRAME_DELAY,
	//		"Images/flag"+ type +".png",
	//		tileMap->getBounds()						
	//	);
	//}

	//return nullptr;
}
#pragma endregion


#pragma region Keyboard Input
		/// <summary>
		/// Takes the key code data and changes the players state.
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
		/// Updates all game components after all components are
		/// updated checks are made to see what phase the
		/// game is in for example if a game is won.
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
			alienList->checkCollisions(player, sManager);
			flagList->pickupItem(player, sManager);
			playerList->collectCoin(sManager);
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
			dbGraphics->DrawImageUnscaled(background, 0, 0, clientRectangle.Width, clientRectangle.Height);
			//
			// Draw Viewport to Canvas 
			//
			viewport->viewportDraw(0, 0);
			//
			// Draw Sprites to Canvas
			//
			flagList->draw();
			alienList->draw();
			playerList->draw();
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
			//
			// Checks all the flags have been collected by the player
			//
			if(flagCount == N_FLAGS)									// All flags have been collected
			{
				alienList->setSpritesMagnitudes(NEW_ALIEN_X_MAG, NEW_ALIEN_Y_MAG);
				flagList->setFlagCount(0);								// Reset Flags must have to pick up coins		
				mManager->addCoinsToGame(tileMap);						// Makes coins visible					
				tileMap->setMapValue(EXIT_COL, EXIT_ROW, EXIT_TILE);	// Shows exit post
			}
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
			levelwin = player->isLevelWin();							// Level has been won			 

			if(levelwin)								
			{	
				level++;												// Changes to next level

				if(level <= N_LEVELS)
				{
					initializeGame();									// Create a game
					initializeObjectsPositons();						// Positions sprites on screen

					flagList->setFlag(0);								// Hud flags are not displayed
					flagList->setFlagCount(0);							// Tracks flags that are picked up
					player->setCoins(0);								// Resets coins for next level

					player->setLevelWin(false);							// Resets level win
				}				
			}
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
			if(level > N_LEVELS || lives == 0)						// All lives lost or max level reached
			{
				sManager->levelOver->PlaySync();					//Play level win sound here

				levelover = true;									// Game over is set

				if(score >= highscore)								// If score is greater than highscore write to file				
				{
					fileWriter = gcnew StreamWriter(DATAFILE);		// Open file
					fileWriter->Write(score.ToString());			// Write to score
					fileWriter->Close();							// Close file

					delete fileWriter;								// Clean up
				}
			}
		}
		//
		//
		//		
#pragma endregion
