#pragma once
#include "tetrimino.h"

#define O_X 5

ref class O :
public Tetrimino
	{
	public:
		O(ResourceManager^ rm, Color color, GameGrid^ grid, Grid^ preview);
		virtual void rotate(array<Point>^ temp) override;
	};
