#pragma once
#include "tetrimino.h"

#define Z_X 5

ref class Z :
public Tetrimino
	{
	public:
		Z(ResourceManager^ rm, Color color, GameGrid^ grid, Grid^ preview);
		virtual void rotate(array<Point>^ temp) override;
	};
