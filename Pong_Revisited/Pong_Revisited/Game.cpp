#include "StdAfx.h"
#include "Game.h"

Game::Game()
{
	ball = gcnew Ball(50, 400);
	player = gcnew Play(0, 50, ball);
	enemy = gcnew Enemy(770, 50, ball);

	north = gcnew Wall(0, 0, 800, 16, ball);
	south = gcnew Wall(0, 546, 800, 16, ball);
}

void Game::update()
{	
	ball->update();
	player->update();
	enemy->update();

	north->update();
	south->update();

	if(ball->getX() > 800){
        ball->resetPosition();
    }

    if(ball->getX() < 0){
        ball->resetPosition();
    }
}
void Game::render(Graphics^ g)
{	
	ball->render(g);
	player->render(g);
	enemy->render(g);

	north->render(g);
	south->render(g);
}
