#pragma once
#include "tetrimino.h"

#define I_X 5

ref class I :
public Tetrimino
	{
	public:
		I(ResourceManager^ rm, Color color, GameGrid^ grid, Grid^ preview);
		virtual void rotate(array<Point>^ temp) override;
	};
