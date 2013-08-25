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
		Image^ cellImage;
		bool tetrimino;
		bool solid;		

	public:
		Cell(Color color);

		void setImage(Image^ i)		{ cellImage = i; }
		void setColor(Color c)		{ cellColor = c; }
		void setTetrimino(bool t)	{ tetrimino = t; }
		void setSolid(bool s)		{ solid = s; }
		
		Image^ getImage()		{ return cellImage; }
		Color getColor()		{ return cellColor; }
		bool isTetrimino()		{ return tetrimino;	}
		bool isSolid()			{ return solid;	}		
	};
