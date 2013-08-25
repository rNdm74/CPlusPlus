#pragma once

#include "PlaySound.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Drawing::Text;

enum EGameState 
	{
		MENU = 0,
		PLAY = 1,
		OVER = 2
	};

ref class Game abstract
	{
	protected:
		Image^ background;
		Graphics^ graphics;
		Rectangle screenBounds;
		Font^ font;
		Brush^ brush;

	public:
		Game(Graphics^ dbGraphics, Rectangle screenBounds, Font^ gameFont, Brush^ fontBrush);
		virtual EGameState input(KeyEventArgs^  e);
		virtual void update();
		virtual void render();
	};
