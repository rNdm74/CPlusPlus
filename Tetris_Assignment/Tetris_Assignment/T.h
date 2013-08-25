#pragma once
#include "tetrimino.h"

#define T_X 5

ref class T :
public Tetrimino
	{
	public:
		T(Color color, Grid^ grid, Grid^ preview);
		virtual void rotate(array<Point>^ temp) override;
	};
