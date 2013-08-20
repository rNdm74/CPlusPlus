#pragma once
#include "block.h"

ref class I :
public Block
	{
	public:
		I(array<Point>^ square, Color color, Grid^ grid);
		virtual void rotate() override;
	};
