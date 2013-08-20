#pragma once
#include "block.h"

ref class Z :
public Block
	{
	public:
		Z(array<Point>^ square, Color color, Grid^ grid);
		virtual void rotate() override;
	};
