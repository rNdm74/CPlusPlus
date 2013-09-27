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
				"Images/p3_spritesheet.png",
				"Images/p3_spritesheet.png",							
				"Images/p3_spritesheet.png",
				"Images/p3_spritesheet.png"
			},
			11,
			rGen,
			Point(10, 608),
			foreground
		);
		
		knight->setWalking(false);
	
		//=================================================
		// Create NPCs
		//=================================================
		/*chickens = gcnew array<Chicken^>(10);				

		for(int c = 0; c < chickens->Length; c++)
		{
			chickens[c] = gcnew Chicken
			(
				tileMap,
				BOUNCE,
				dbGraphics,
				gcnew array<String^>
				{
					"Little Chicken Walk North 8.bmp",								
					"Little Chicken Walk East 8.bmp",
					"Little Chicken Walk South 8.bmp",
					"Little Chicken Walk West 8.bmp"
				},
				CHICKEN_FRAMES,
				rGen,
				Point(rGen->Next(260, 800), rGen->Next(260, 300)),
				viewport
			);
		}

		// Adds all game characters to the spritelist
		for(int c = 0; c < chickens->Length; c++)
			spriteList->add(chickens[c]);*/

		spriteList->add(knight);
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

		//=================================================
		// NPC AI
		//=================================================		
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

		//=================================================
		// Make Buffer Visible 
		//=================================================
		canvas->DrawImage(dbBitmap, clientRectangle);
	}
