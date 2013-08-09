#pragma once

#include "GameObjectList.h"
#include "GameObject.h"

#define CELL_SIZE 20

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

ref class GameBoard
	{
	private:
		GameObjectList^ board;

	public:
		GameBoard(Rectangle client, Graphics^ canvas);
		void update();
		void render();

		GameObjectList^ getBoard() { return board; }
	};
