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
		knight = gcnew Player
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

		knight->setStartPosition(objectMap->getSpawnPosition(PLAYER, knight->getHeight()));
		
		knight->setWalking(false);
	
		//=================================================
		// Create NPCs
		//=================================================
		chickens = gcnew array<NPC^>(4);

		array<int>^ spriteType = gcnew array<int>
		{
			ENEMY1, 
			ENEMY2, 
			ENEMY3, 
			ENEMY4
		};

		for(int c = 0; c < chickens->Length; c++)
		{
			int r = rGen->Next(1, 3);

			chickens[c] = gcnew NPC
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

			Point startPos = objectMap->getSpawnPosition(spriteType[c], chickens[c]->getHeight());

			chickens[c]->setXPos(startPos.X);
			chickens[c]->setYPos(startPos.Y);
		}

		flags = gcnew array<Item^>(3);

		spriteType = gcnew array<int>
		{
			FLAG1, 
			FLAG2, 
			FLAG3
		};

		for(int c = 0; c < flags->Length; c++)
		{
			
			flags[c] = gcnew Item
			(
				tileMap,
				WRAP,
				dbGraphics,
				"Images/flag" + c + ".png",	
				2,
				rGen,
				Point(0,0),
				foreground
			);

			Point startPos = objectMap->getSpawnPosition(spriteType[c], flags[c]->getHeight());

			flags[c]->setXPos(startPos.X);
			flags[c]->setYPos(startPos.Y);
		}

		coins = gcnew array<Item^>(65);

		//addCoinsToGame();
		
		// Adds all game characters to the spritelist
		for(int c = 0; c < flags->Length; c++)
			spriteList->add(flags[c]);

		for(int c = 0; c < chickens->Length; c++)
			spriteList->add(chickens[c]);		

		spriteList->add(knight);

		flagCount = 0;
		lives = 3;
	}

void GameManager::addCoinsToGame()
	{
		for(int c = 0; c < coins->Length; c++)
		{
			
			coins[c] = gcnew Item
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
		
		for(int c = 0; c < coins->Length; c++)
			spriteList->add(coins[c]);

	}

void GameManager::keyDown(KeyEventArgs^  e)
	{
		 if(e->KeyCode==Keys::Up ||e->KeyCode==Keys::Down || e->KeyCode==Keys::Left || e->KeyCode==Keys::Right)
			 knight->setWalking(true);
		 		 
		 if(e->KeyCode==Keys::Up)
		 {
			knight->setBearing(NORTH);			
		 }		 
		 else if(e->KeyCode==Keys::Down)
		 {
			knight->setBearing(SOUTH);	
		 }		 
		 else if(e->KeyCode==Keys::Right)
		 {
			knight->setBearing(EAST);	
		 }		 
		 else if(e->KeyCode==Keys::Left)
		 {
			knight->setBearing(WEST);	
		 }
	}

void GameManager::keyUp(KeyEventArgs^  e)
	{
		knight->setBearing(STAND);
		knight->setWalking(false);
	}

void GameManager::updateGame()
	{
		//=================================================
		// Move Player
		//=================================================
		//knight->move(foreground->getViewportWorldX(), foreground->getViewportWorldY());

		//=================================================
		// Set Viewport Position on Player
		//=================================================
		int knightX = knight->getXPos() + (knight->getWidth() / 2);
		int knightY = knight->getYPos() + (knight->getHeight() / 2);

		foreground->moveRelativeToPlayer(knightX, knightY);
		
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

		if(knight->isGameOver())
			Application::Exit();


		//=================================================
		// NPC AI
		//=================================================	
		for(int c = 0; c < chickens->Length; c++)
			chickens[c]->wander();
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
