#pragma once
#include "tetrimino.h"

#define O_X 5

ref class O :
public Tetrimino
	{
	public:
		O(Color color, Grid^ grid, Grid^ preview);
		virtual void rotate(array<Point>^ temp) override;
	};
