#pragma once

#include "Game.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Drawing::Text;

#define DIRECTION -1

ref class GameMenu :
public Game
	{
	private:
		float xPos;
		float yPos;

		float vel;


		Image^ logo;
		System::String^ label;
		
	public:
		GameMenu(Graphics^ dbGraphics, Rectangle screenBounds, Font^ gameFont, Brush^ fontBrush);

		virtual EGameState input(KeyEventArgs^  e) override;
		virtual void update() override;
		virtual void render() override; 

		void setLabel(System::String^ l) { label = l; }
		
	};