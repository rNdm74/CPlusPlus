#include "StdAfx.h"
#include "GameManager.h"

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
		// Create game
		//
		createGame();		
	}

void GameManager::addCoinsToGame()
	{	
		for(int i = 0; i < coins->Length; i++)
		{
			spriteList->add(coins[i]);
		}
	}

void GameManager::createGame()
	{
		fileReader = gcnew StreamReader("data.dat");
		String^ line = fileReader->ReadLine();
		highscore = int::Parse(line);		
		fileReader->Close();
		//
		// Create the csv file reader
		//
		reader = gcnew CSVReader("tilemap.csv", "objectmap.csv", "coinmap.csv");
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
		player = gcnew Player
		(
			tileMap,
			STOP,
			dbGraphics,
			"Images/player.png",
			11,
			rGen,
			Point(0, 0),
			foreground,
			PLAYER
		);
		player->setStartPosition(objectMap->getSpawnPosition(PLAYER, player->getHeight()));		
		player->setWalking(false);	
		//
		// Create NPCs
		//
		aliens = gcnew array<NPC^>(4);

		array<int>^ spriteType = gcnew array<int>
		{
			ALIEN_ONE, 
			ALIEN_TWO, 
			ALIEN_THREE, 
			ALIEN_FOUR
		};

		for(int i = 0; i < aliens->Length; i++)
		{
			int r = rGen->Next(1, 3);

			aliens[i] = gcnew NPC
			(
				tileMap,
				BOUNCE,
				dbGraphics,				
				"Images/enemy" + r + ".png",
				11,
				rGen,
				Point(0,0),
				foreground,
				ENEMY,
				r
			);

			Point startPos = objectMap->getSpawnPosition(spriteType[i], aliens[i]->getHeight());

			aliens[i]->setXPos(startPos.X);
			aliens[i]->setYPos(startPos.Y);
		}

		flags = gcnew array<Item^>(3);

		spriteType = gcnew array<int>
		{
			RED_FLAG, 
			BLUE_FLAG, 
			YELLOW_FLAG
		};

		for(int i = 0; i < flags->Length; i++)
		{
			
			flags[i] = gcnew Item
			(
				tileMap,
				WRAP,
				dbGraphics,
				"Images/flag" + i + ".png",	
				2,
				rGen,
				Point(0,0),
				foreground,
				FLAG
			);

			Point startPos = objectMap->getSpawnPosition(spriteType[i], flags[i]->getHeight());

			flags[i]->setXPos(startPos.X);
			flags[i]->setYPos(startPos.Y);
		}

		coins = gcnew array<Item^>(65);

		for(int i = 0; i < coins->Length; i++)
		{
			
			coins[i] = gcnew Item
			(
				tileMap,
				WRAP,
				dbGraphics,
				"Images/coinGold.png",	
				2,
				rGen,
				Point(0,0),
				foreground,
				COIN
			);			
		}

		array<int, 2>^ coinsMap = objectMap->getCoinMap();

		int count = 0;

		for(int col = 0; col < N_COLS; col++)
		{
			for(int row = 0; row < N_ROWS; row++)
			{
				if(coinsMap[row, col] == COIN)
				{
					int xPos = (col * T_SIZE);
					int yPos = ((row + 1) * T_SIZE) - coins[count]->getHeight();

					coins[count]->setXPos(xPos);
					coins[count]->setYPos(yPos);

					count++;
				}				
			}
		}

		
				
		// Adds all game characters to the spritelist
		for(int i = 0; i < flags->Length; i++)
			spriteList->add(flags[i]);

		for(int i = 0; i < aliens->Length; i++)
			spriteList->add(aliens[i]);		

		spriteList->add(player);

		imageOneX = 0;
		imageTwoX = 1024;
	}

void GameManager::keyDown(KeyEventArgs^  e)
	{
		 if(e->KeyCode==Keys::Up ||e->KeyCode==Keys::Down || e->KeyCode==Keys::Left || e->KeyCode==Keys::Right)
			 player->setWalking(true);
		 		 
		 if(e->KeyCode==Keys::Up)
		 {
			player->setBearing(NORTH);			
		 }		 
		 else if(e->KeyCode==Keys::Down)
		 {
			player->setBearing(SOUTH);	
		 }		 
		 else if(e->KeyCode==Keys::Right)
		 {
			player->setBearing(EAST);	
		 }		 
		 else if(e->KeyCode==Keys::Left)
		 {
			player->setBearing(WEST);	
		 }
	}

void GameManager::keyUp(KeyEventArgs^  e)
	{
		player->setBearing(STAND);
		player->setWalking(false);
	}

void GameManager::updateGame()
	{
		//=================================================
		// Move Player
		//=================================================
		//player->move(foreground->getViewportWorldX(), foreground->getViewportWorldY());

		//=================================================
		// Set Viewport Position on Player
		//=================================================
		int playerX = player->getXPos() + (player->getWidth() / 2);
		int playerY = player->getYPos() + (player->getHeight() / 2);

		foreground->moveRelativeToPlayer(playerX, playerY);
		
		//=================================================
		// Updates Sprites Animation
		//=================================================
		spriteList->update();

		flagCount = spriteList->getFlags();
		coinCount = spriteList->getCoins();
		score = spriteList->getScore();
		lives = spriteList->getLives();

		if(flagCount == 3)
		{
			spriteList->setFlags(0);

			tileMap->setMapValue(1, 9, 9);

			addCoinsToGame();						
		}

		

		if(lives == 0)
		{
			player->setGameOver(true);

			fileReader = gcnew StreamReader("data.dat");
			String^ line = fileReader->ReadLine();
			int temp = int::Parse(line);		
			fileReader->Close();

			if(temp < score)
			{
				fileWriter = gcnew StreamWriter("data.dat");
				fileWriter->Write(score.ToString());
				fileWriter->Close();
			}

			Application::Exit();
		}
		
		if(player->isLevelWin())
		{
			
			createGame();

			spriteList->setScore(score);
			spriteList->setLives(lives);

			player->setLevelWin(false);
		}
			


		//=================================================
		// NPC AI
		//=================================================	
		for(int c = 0; c < aliens->Length; c++)
			aliens[c]->wander();
	}

void GameManager::drawGame()
	{
		//=================================================
		// Draw Background to Canvas 
		//=================================================
		/*imageOneX-=1;
		imageTwoX-=1;

		if(imageOneX <= -1024)
		{
			imageOneX = 1024;
		}

		if(imageTwoX <= -1024)
		{
			imageTwoX = 1024;
		}*/

		dbGraphics->DrawImageUnscaled(background, Rectangle(0, 0, 1027, 768));
		//dbGraphics->DrawImageUnscaledAndClipped(background, Rectangle(imageTwoX, 0, 1024, 768));

		//=================================================
		// Draw Viewport to Canvas 
		//=================================================
		foreground->viewportDraw(0, 0);

		//=================================================
		// Draw Sprites to Canvas
		//=================================================
		spriteList->renderSprites(foreground->getViewportWorldX(), foreground->getViewportWorldY());		

		dbGraphics->DrawString("Flags: " + flagCount.ToString(), gcnew Font("Microsoft Sans Serif", 16), Brushes::WhiteSmoke, 10, 10);
		dbGraphics->DrawString("Coins: " + coinCount.ToString(), gcnew Font("Microsoft Sans Serif", 16), Brushes::WhiteSmoke, 110, 10);
		dbGraphics->DrawString("Lives: " + lives.ToString(), gcnew Font("Microsoft Sans Serif", 16), Brushes::WhiteSmoke, 210, 10);
		dbGraphics->DrawString("Score: " + score.ToString(), gcnew Font("Microsoft Sans Serif", 16), Brushes::WhiteSmoke, 310, 10);
		dbGraphics->DrawString("HighScore: " + highscore.ToString(), gcnew Font("Microsoft Sans Serif", 16), Brushes::WhiteSmoke, 500, 10);

		//=================================================
		// Make Buffer Visible 
		//=================================================
		canvas->DrawImage(dbBitmap, clientRectangle);
	}
