#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class RectangleShape
	{
	private:
		int xPos;
		int yPos;
		int width;
		int height;

		Color color;

		Brush^ brush;
		Pen^ pen;

		Graphics^ canvas;

	public:
		RectangleShape(int startX, int startY, int startWidth, int startHeight, Graphics^ g);

		void update();
		void render();

		Rectangle getBounds() { return Rectangle(xPos, yPos, width, height); }
		void setColor(Color c)	{ color = c; }

	};
