#include "StdAfx.h"
#include "GameObjectManager.h"

GameObjectManager::GameObjectManager(Graphics^ canvas, Rectangle gameWindow)
{	
	rGen = gcnew Random();
	playerBullets = gcnew GameObjectList();
	alienBullets = gcnew GameObjectList();

	aliens = gcnew GameObjectList();
	
	// Create blocks
	for(int col = 0; col < NCOLS; col++)
	{
		for(int row = 0; row < NROWS; row++)
		{
			aliens->add(gcnew Alien
			(
				RectangleF(10+(60 * col), 40 + (40 * row),20,20),
				PointF(0,0),
				canvas,
				row,
				rGen,
				alienBullets
			));			
		}
	}

	player = gcnew Player(RectangleF(gameWindow.Width / 2 - 5, gameWindow.Height - 20,10,10), PointF(0.1,0.1), canvas, playerBullets);
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
	alienBullets->update();
	playerBullets->update();
	
	aliens->update();
	player->update();
	

	for(int bullet = 0; bullet < alienBullets->length(); bullet++)
		checkCollision(aliens, (Bullet^)alienBullets->get(bullet));

	for(int bullet = 0; bullet < playerBullets->length(); bullet++)
		//checkCollision(player, (Bullet^)playerBullets->get(bullet));
	

	if(rGen->Next(1000) == 0) aliens->get(rGen->Next(0,22))->shoot();
}

void GameObjectManager::render()
{
	alienBullets->render();
	playerBullets->render();	
	aliens->render();
	player->render();
}

bool GameObjectManager::checkCollision(GameObjectList^ list, Bullet^ bullet)
{
	for(int item = 0; item < list->length(); item++)
	{
		GameObject^ object = list->get(item);

		if(object->isVisible())
		{
			if(object->collision(bullet))
			{
				//ball->verticalBounce(block->getCenterX());
				alienBullets->remove(bullet);
				object->setVisible(false);
				//brokenBrickCount++;						
				return true;
			}
		}
	}

	return false;
}

bool GameObjectManager::checkCollision(GameObject^ object, Bullet^ bullet)
{	
	if(object->isVisible())
	{
		if(object->collision(bullet))
		{
			//ball->verticalBounce(block->getCenterX());
			playerBullets->remove(bullet);
			object->setVisible(false);
			//brokenBrickCount++;						
			return true;
		}
	}

	return false;
}
