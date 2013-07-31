#pragma once

#include "GameObject.h"
#include "Enemy.h"
#include "Play.h"
#include "Ball.h"
#include "Wall.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class Game
{
private:
	//GameObject objects;

	Ball^ ball;
	Play^ player;
	Enemy^ enemy;
	Wall^ north;
	Wall^ south;

	int playerScore;
	int enemyScore;

public:
	Game();

	Play^ getPlayer(){return player;}

	void update();

	void render(Graphics^ g);
};
