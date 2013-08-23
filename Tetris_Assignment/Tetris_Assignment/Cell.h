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
		bool gameBlock;
		bool solid;		

	public:
		Cell(Color color);

		void setColor(Color c)	{ cellColor = c; }
		void setBlock(bool b)	{ gameBlock = b; }
		void setSolid(bool s)	{ solid = s; }
		
		Color getColor()		{ return cellColor; }
		bool isBlock()			{ return gameBlock;	}
		bool isSolid()			{ return solid;	}		
	};
