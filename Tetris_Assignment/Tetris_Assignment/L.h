#pragma once
#include "tetrimino.h"

#define L_X 6

ref class L :
public Tetrimino
	{
	public:
		L(Color color, Grid^ grid, Grid^ preview);
		virtual void rotate(array<Point>^ temp) override;
	};

