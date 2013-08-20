#pragma once
#include "block.h"

ref class J :
public Block
	{
	public:
		J(array<Point>^ square, Color color, Grid^ grid);
		virtual void rotate() override;
	};
