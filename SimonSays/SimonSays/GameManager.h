#pragma once

#include "RectangleShape.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;



ref class GameManager
	{
	private:
		Graphics^ canvas;

		Size size;

		array<RectangleShape^, 2>^ rectArray;

	public:
		GameManager(Graphics^ g, Size s);

		void mouseMove(MouseEventArgs^  e);
		void mouseDown(MouseEventArgs^  e);
		void mouseUp(MouseEventArgs^  e);
		void update();
		void render();
	};
