#pragma once
#include "GameObjectList.h"
#include "GameObject.h"
#include "Alien.h"
#include "Player.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

#define NCOLS 10
#define NROWS 4

ref class GameObjectManager
{
private:
	GameObjectList^ gameObjects;

	array<Alien^, 2>^ aliens;

	Player^ player;	

public:
	GameObjectManager(Graphics^ startCanvas, Rectangle gameWindow);
	void keyUp(KeyEventArgs^  e);
	void keyDown(KeyEventArgs^  e);
	void update();
	void render();
};
