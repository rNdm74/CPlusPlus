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
		viewport = gcnew Viewport(0, 0, V_COLS, V_ROWS, tileMap, dbGraphics);

		//=================================================
		// Create spritelist
		//=================================================
		spriteList = gcnew SpriteList(viewport);

		Rectangle mapRect = tileMap->getMapBounds();

		//=================================================
		// Create Player
		//=================================================
		/*knight = gcnew Player
		(
			tileMap,
			WRAP,
			dbGraphics,
			gcnew array<String^>
			{
				"Knight Walk North 8.bmp",
				"Knight Walk East 8.bmp",							
				"Knight Walk South 8.bmp",
				"Knight Walk West 8.bmp"
			},
			KNIGHT_FRAMES,
			rGen,
			Point(mapRect.Width / 2 - 50, mapRect.Height / 2 - 50),
			viewport
		);
		
		knight->setWalking(false);*/
	
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
			spriteList->add(chickens[c]);

		spriteList->add(knight);*/
	}

void GameManager::updateGame()
	{
		//=================================================
		// Move Player
		//=================================================

		//=================================================
		// Set Viewport Position on Player
		//=================================================
		
		//=================================================
		// Updates Sprites Animation
		//=================================================

		//=================================================
		// NPC AI
		//=================================================		
	}

void GameManager::drawGame()
	{
		//=================================================
		// Draw Background to Canvas 
		//=================================================

		//=================================================
		// Draw Viewport to Canvas 
		//=================================================

		//=================================================
		// Draw Sprites to Canvas
		//=================================================

		//=================================================
		// Make Buffer Visible 
		//=================================================
		canvas->DrawImage(dbBitmap, clientRectangle);
	}
