#include "StdAfx.h"
#include "GameObjectManager.h"

GameObjectManager::GameObjectManager(Graphics^ canvas, Rectangle gameWindow)
{	
	gameObjects = gcnew GameObjectList();

	aliens = gcnew array<Alien^, 2>(NCOLS,NROWS);

	// Create blocks
	for(int col = 0; col < NCOLS; col++)
	{
		for(int row = 0; row < NROWS; row++)
		{
			gameObjects->add(gcnew Alien
			(
				RectangleF(100 + (40 * col), 40 + (40 * row),10,10),
				PointF(0,0),
				canvas
			));			
		}
	}

	player = gcnew Player(RectangleF(gameWindow.Width / 2 - 5, gameWindow.Height - 20,10,10), PointF(0.1,0.1), canvas);

	gameObjects->add(player);

}

void GameObjectManager::keyDown(KeyEventArgs^  e)
{
	player->keyDown(e);
}

void GameObjectManager::keyUp(KeyEventArgs^  e)
{
	player->keyUp(e);
}

void GameObjectManager::update()
{
	gameObjects->update();
}

void GameObjectManager::render()
{
	gameObjects->render();
}
