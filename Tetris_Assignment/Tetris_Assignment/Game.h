#pragma once

#include "Sound.h"

using namespace System;
using namespace System::Resources;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Drawing::Text;


enum EGameState // Different game states
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
		Sound^ gSound;
		ResourceManager^ rManager;

	public:
		static bool Play;

	public:
		Game(ResourceManager^ rm, Graphics^ dbGraphics, Rectangle screenBounds, Font^ gameFont, Brush^ fontBrush, Sound^ sound);
		virtual EGameState input(KeyEventArgs^  e);
		virtual void update();
		virtual void render();
	};
