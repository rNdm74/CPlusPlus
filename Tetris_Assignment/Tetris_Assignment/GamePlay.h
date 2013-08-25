#pragma once

#include "Game.h"
#include "GameGrid.h"
#include "Tetrimino.h"
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
using namespace System::Media;

#define GAMEGRID_COLS 14
#define GAMEGRID_ROWS 25
#define PREVIEW_COLS 8
#define PREVIEW_ROWS 6

#define ALPHA 75

ref class GamePlay:
public Game
{
private:
	Tetrimino^ tetriminoInPlay;
	Tetrimino^ nextTetrimino;

	GameGrid^ grid;
	Grid^ preview;
		
	int time;
	int waitTime;
	

	bool drop;
	

	array<int>^ tetriminoStats;
	array<ETetriminoType>^ tetriminoTypes;

	Random^ rGen;

public:
	GamePlay(Graphics^ dbGraphics, Rectangle screenBounds, Font^ gameFont, Brush^ fontBrush);

	void moveLeft();
	void moveRight();
	void moveDown();
	void moveRotate();

	Tetrimino^ generateTetrimino();
	bool isGameOver();
	int getTotalStats();
	
	virtual EGameState input(KeyEventArgs^  e) override;
	virtual void update() override;
	virtual void render() override;

	void updateStats(ETetriminoType type);
		
	int getPlayerScore()	{ return grid->getPlayerScore(); }
	bool getDrop()			{ return drop; }
	void setDrop(bool b)	{ drop = b; }
};
