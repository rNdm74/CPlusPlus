#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class Cell
	{
	private:
		Color cellColor;
		bool full;
	public:
		Cell(Color color);

		void setColor(Color c)	{ cellColor = c; }
		void setFull(bool b)	{ full = b; }

		Color getColor()		{ return cellColor; }
		bool isFull()			{ return full;	}
	};
