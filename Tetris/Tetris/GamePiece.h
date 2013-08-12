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

ref class GamePiece
	{
	private:
		GameObjectList^ piece;
		KeyEventArgs^  e;

		Point location;
		Rectangle client;
		Graphics^ canvas;		

	public:
		GamePiece(Point startLocation, Rectangle client, Graphics^ canvas);

		void input(KeyEventArgs^  e);
		void update();
		void render();

		void addObject(Point p);

		GameObjectList^ getPiece()	{ return piece; }

		void setLocation(Point l)	{ location = l;	}
	};
