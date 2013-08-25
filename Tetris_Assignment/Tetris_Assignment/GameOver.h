#pragma once

#include "Game.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Drawing::Text;

ref class GameOver:
public Game
{
	private:
		bool gameOver;
	public:
		GameOver(Graphics^ dbGraphics, Rectangle screenBounds, Font^ gameFont, Brush^ fontBrush);
		
		virtual EGameState input(KeyEventArgs^  e) override;
		virtual void update() override;
		virtual void render() override; 
		
};
