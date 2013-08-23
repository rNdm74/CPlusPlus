#pragma once

#include "Grid.h"
#include "Block.h"
#include "L.h"
#include "J.h"
#include "Z.h"
#include "S.h"
#include "T.h"
#include "I.h"
#include "O.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;



ref class GridManager
{
private:
	array<Block^>^ blocks;

	Grid^ grid;

	Graphics^ graphics;

	Image^ background;
	PrivateFontCollection^ pfc;
	Font^ font;
	Brush^ fontBrush;
	
	int time;
	int waitTime;
	int blockInPlay;	

	Random^ rGen;

public:
	GridManager(Graphics^ dbGraphics);
	void moveLeft();
	void moveRight();
	void moveDown();
	void moveRotate();
	Block^ getGameBlock();
	void update();
	void render();

	int getPlayerScore() { return grid->getPlayerScore(); }
};
