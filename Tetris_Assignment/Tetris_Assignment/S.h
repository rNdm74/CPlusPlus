#pragma once
#include "tetrimino.h"

#define S_X 5

ref class S :
public Tetrimino
	{
	public:
		S(ResourceManager^ rm, Color color, GameGrid^ grid, Grid^ preview);
		virtual void rotate(array<Point>^ temp) override;
	};
