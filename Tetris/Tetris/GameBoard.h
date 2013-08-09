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
		KeyEventArgs^  e;

		Point location;
		Rectangle client;
		Graphics^ canvas;		

	public:
		GameBoard(Point startLocation, Rectangle client, Graphics^ canvas);

		void input(KeyEventArgs^  e);
		void update();
		void render();

		void addObject();

		GameObjectList^ getBoard()	{ return board; }

		void setLocation(Point l)	{ location = l;	}
	};
