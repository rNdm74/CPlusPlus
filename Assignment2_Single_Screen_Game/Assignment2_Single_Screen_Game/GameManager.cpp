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
		objectMap = gcnew ObjectMap(reader->getObjectMap());


		//=================================================
		// Create Player
		//=================================================
		knight = gcnew Player
		(
			tileMap,
			WRAP,
			dbGraphics,
			gcnew array<String^>
			{
				"Images/player.png",
				"Images/player.png",
				"Images/player.png",
				"Images/player.png"
			},
			9,
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
				WRAP,
				dbGraphics,
				gcnew array<String^>
				{
					"Images/enemy" + r + ".png",								
					"Images/enemy" + r + ".png",
					"Images/enemy" + r + ".png",
					"Images/enemy" + r + ".png"
				},
				9,
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
				gcnew array<String^>
				{
					"Images/flag" + c + ".png",								
					"Images/flag" + c + ".png",
					"Images/flag" + c + ".png",
					"Images/flag" + c + ".png"
				},
				2,
				rGen,
				Point(0,0),
				foreground
			);

			Point startPos = objectMap->getSpawnPosition(spriteType[c], flags[c]->getHeight());

			flags[c]->setXPos(startPos.X);
			flags[c]->setYPos(startPos.Y);
		}

		// Adds all game characters to the spritelist
		for(int c = 0; c < flags->Length; c++)
			spriteList->add(flags[c]);

		for(int c = 0; c < chickens->Length; c++)
			spriteList->add(chickens[c]);		

		spriteList->add(knight);

		score = 0;
		lives = 3;
	}

void GameManager::keyDown(KeyEventArgs^  e)
	{
		 if(e->KeyCode==Keys::Up ||e->KeyCode==Keys::Down || e->KeyCode==Keys::Left || e->KeyCode==Keys::Right)
			 knight->setWalking(true);
		 
		 if(e->KeyCode==Keys::Up)
		 {
			knight->setBearing(NORTH);
		 }
		 
		 if(e->KeyCode==Keys::Down)
		 {
			knight->setBearing(SOUTH);	
		 }
		 
		 if(e->KeyCode==Keys::Right)
		 {
			knight->setBearing(EAST);	
		 }
		 
		 if(e->KeyCode==Keys::Left)
		 {
			knight->setBearing(WEST);	
		 }
	}

void GameManager::keyUp(KeyEventArgs^  e)
	{
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
		score = spriteList->getScore();
		lives = spriteList->getLives();

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

		

		dbGraphics->DrawString("Score: " + score.ToString(), gcnew Font("Microsoft Sans Serif", 12), Brushes::Black, 10, 10);

		dbGraphics->DrawString("Lives: " + lives.ToString(), gcnew Font("Microsoft Sans Serif", 12), Brushes::Black, 500, 10);

		//=================================================
		// Make Buffer Visible 
		//=================================================
		canvas->DrawImage(dbBitmap, clientRectangle);
	}
