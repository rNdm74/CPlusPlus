#pragma once
#include "tetrimino.h"

#define J_X 6

ref class J :
public Tetrimino
	{
	public:
		J(Color color, GameGrid^ grid, Grid^ preview);
		virtual void rotate(array<Point>^ temp) override;
	};
