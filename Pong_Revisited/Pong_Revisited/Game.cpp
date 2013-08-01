#include "StdAfx.h"
#include "Game.h"

Game::Game(Form^ f)
{
	form = f;

	//int w = f->R;

	//f->Text = w + "";
	
	ball = gcnew Ball(50, 400);
	player = gcnew Play(0, 50, ball);
	enemy = gcnew Enemy(f->Bounds.Width - 50, 50, ball);

	north = gcnew Wall(0, -16, f->Bounds.Width / 2, 16, ball);
	south = gcnew Wall(0, 546, f->Right / 2, 16, ball);

	objects = gcnew array<GameObject ^>{ ball, player, enemy, north, south };
}

void Game::update()
{
	for(int i = 0; i < objects->Length; i++) {
		objects[i]->update();
	}

	if(ball->getX() < 0 || ball->getX() > 800){
        ball->resetPosition();
    }    
}
void Game::render(Graphics^ g)
{
	for(int i = 0; i < objects->Length; i++) {
		objects[i]->render(g);
	}	
}
