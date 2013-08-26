#pragma once
#include "grid.h"

using namespace System::Media;

ref class GameGrid :
public Grid
{
private:
	int playerScore;
	int playerLines;
	int playerLevel;

public:
	GameGrid(Point location, Graphics^ dbGraphics, Sound^ sound, int cols, int rows);

	virtual void update() override;

	virtual bool isRowFull(int rowNumber) override; //- all cells in row are full 
	virtual void deleteRow(int rowNumber) override; //- cell up above is now my color cycle up from bottom

	int getPlayerScore()			{ return playerScore; }
	int getPlayerLines()			{ return playerLines; }
	int getPlayerLevel()			{ return playerLevel; }
};
