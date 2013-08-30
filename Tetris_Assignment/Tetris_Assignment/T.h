#pragma once
#include "tetrimino.h"

#define T_X 5

ref class T :
public Tetrimino
	{
	public:
		T(ResourceManager^ rm, Color color, GameGrid^ grid, Grid^ preview);
		virtual void rotate(array<Point>^ temp) override;
	};
