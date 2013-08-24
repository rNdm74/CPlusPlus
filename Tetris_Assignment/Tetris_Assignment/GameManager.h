#pragma once

#include "GameGrid.h"
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

#define GAMEGRID_COLS 14
#define GAMEGRID_ROWS 26
#define PREVIEW_COLS 8
#define PREVIEW_ROWS 6
#define START_X 6
#define ALPHA 99

ref class GridManager
{
private:
	array<Block^>^ blocks;

	GameGrid^ grid;
	Grid^ preview;

	Graphics^ graphics;
	Rectangle screenBounds;

	Image^ background;
	PrivateFontCollection^ pfc;
	Font^ font;
	Brush^ fontBrush;
	
	int time;
	int waitTime;
	int blockInPlay;

	array<int>^ blockStats;
	array<EBlockType>^ blockTypes;

	Random^ rGen;

public:
	GridManager(Graphics^ dbGraphics, Rectangle screenBounds);

	void moveLeft();
	void moveRight();
	void moveDown();
	void moveRotate();

	Block^ generateBlock();
	
	void update();
	void updateStats(EBlockType type);
	
	void render();

	int getPlayerScore() { return grid->getPlayerScore(); }
};
