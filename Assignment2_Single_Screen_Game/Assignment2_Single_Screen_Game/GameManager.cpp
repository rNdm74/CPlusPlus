#include "StdAfx.h"
#include "GameManager.h"

GameManager::GameManager(Graphics^ startCanvas, Rectangle startClientRectangle)
	{
		//=================================================
		// Create the csv file reader
		//=================================================
		reader = gcnew CSVReader();

		//=================================================
		// Create canvas from form
		//================================================= 
		canvas = startCanvas;

		//=================================================
		// Client viewable screen bounds
		//=================================================
		clientRectangle = startClientRectangle;

		//=================================================
		// Create graphics size of the screen
		//=================================================
		dbBitmap = gcnew Bitmap(clientRectangle.Width, clientRectangle.Height);
		 
		//=================================================
		// Grab its Graphics
		//=================================================
		dbGraphics = Graphics::FromImage(dbBitmap);
		
		//=================================================
		// Create random
		//=================================================
		rGen = gcnew Random();

		//=================================================
		// Create background
		//=================================================
		tileMap = gcnew TileMap(dbGraphics, reader->getTileMap());

		//=================================================
		// Create viewport
		//=================================================
		foreground = gcnew Viewport(0, 0, N_COLS, N_ROWS, tileMap, dbGraphics);

		//=================================================
		// Create spritelist
		//=================================================
		
		spriteList = gcnew SpriteList(foreground);

		Rectangle mapRect = tileMap->getMapBounds();

		background = Image::FromFile("Images/bg.png");

		//
		// Object map
		//
		objectMap = gcnew ObjectMap(reader->getObjectMap(), reader->getCoinMap());


		//=================================================
		// Create Player
		//=================================================
		player = gcnew Player
		(
			tileMap,
			STOP,
			dbGraphics,
			"Images/player.png",
			11,
			rGen,
			Point(0, 0),
			foreground
		);

		player->setStartPosition(objectMap->getSpawnPosition(PLAYER, player->getHeight()));
		
		player->setWalking(false);
	
		//=================================================
		// Create NPCs
		//=================================================
		aliens = gcnew array<NPC^>(4);

		array<int>^ spriteType = gcnew array<int>
		{
			ENEMY1, 
			ENEMY2, 
			ENEMY3, 
			ENEMY4
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
				r
			);

			Point startPos = objectMap->getSpawnPosition(spriteType[i], aliens[i]->getHeight());

			aliens[i]->setXPos(startPos.X);
			aliens[i]->setYPos(startPos.Y);
		}

		flags = gcnew array<Item^>(3);

		spriteType = gcnew array<int>
		{
			FLAG1, 
			FLAG2, 
			FLAG3
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
				foreground
			);

			Point startPos = objectMap->getSpawnPosition(spriteType[i], flags[i]->getHeight());

			flags[i]->setXPos(startPos.X);
			flags[i]->setYPos(startPos.Y);
		}

		coins = gcnew array<Item^>(65);

		//addCoinsToGame();
		
		// Adds all game characters to the spritelist
		for(int i = 0; i < flags->Length; i++)
			spriteList->add(flags[i]);

		for(int i = 0; i < aliens->Length; i++)
			spriteList->add(aliens[i]);		

		spriteList->add(player);

		flagCount = 0;
		lives = 3;
	}

void GameManager::addCoinsToGame()
	{
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
				foreground
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
		
		for(int i = 0; i < coins->Length; i++)
			spriteList->add(coins[i]);

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

		if(flagCount == 3)
		{
			tileMap->setMapValue(1, 9, 9);
			addCoinsToGame();
		}

		lives = spriteList->getLives();

		if(player->isGameOver())
			Application::Exit();


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
		dbGraphics->DrawImageUnscaledAndClipped(background, clientRectangle);

		//=================================================
		// Draw Viewport to Canvas 
		//=================================================
		foreground->viewportDraw(0, 0);

		//=================================================
		// Draw Sprites to Canvas
		//=================================================
		spriteList->renderSprites(foreground->getViewportWorldX(), foreground->getViewportWorldY());		

		dbGraphics->DrawString("Flags: " + flagCount.ToString(), gcnew Font("Microsoft Sans Serif", 12), Brushes::Black, 10, 10);

		dbGraphics->DrawString("Lives: " + lives.ToString(), gcnew Font("Microsoft Sans Serif", 12), Brushes::Black, 500, 10);

		//=================================================
		// Make Buffer Visible 
		//=================================================
		canvas->DrawImage(dbBitmap, clientRectangle);
	}
