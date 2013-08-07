#pragma once

#include "PelletList.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

#define CHICKEN_SPEED	1
#define FONT_SIZE		20
#define FONT_X			20
#define FONT_Y			20
#define RADIUS			5
	
ref class Chicken
	{
	private:
		int xPos;
		int yPos;
		int width;
		int height;

		int direction;

		PelletList^ pellets;
		Graphics^ canvas;
		Random^ rGen;
		Image^ image;
		Font^ font;

	public:
		Chicken(int startX, int startY, Graphics^ g);

		void draw();
		void update();
		void shoot();

		Point getCenter()			{ return Point((xPos + width / 2) - RADIUS, (yPos + height / 2) - RADIUS); }
		void setDirection(int d)	{ direction = d; }
	};
