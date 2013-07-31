#pragma once

#include "Game.h";

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class Main
{
private:
	Game^ game;

public:
	Main();
	
	Game^ getGame(){return game;}

	void update();

	void render(Graphics^ g);
};
