#pragma once

#include "PelletList.h"

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	
ref class Chicken
	{
	private:
		int xPos;
		int yPos;

		int direction;
		int speed;

		PelletList^ pellets; 
		
		Image^ image;

		Graphics^ canvas;

		Random^ rGen;

		Font^ font;

	public:
		Chicken(int startX, int startY, Graphics^ g);		
		void draw();
		void update();
		void shoot();

		void setDirection(int d) { direction = d; }
	};
