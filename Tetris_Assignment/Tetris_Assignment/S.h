#pragma once
#include "block.h"

ref class S :
public Block
	{
	public:
		S(array<Point>^ square, Color color, Grid^ grid);
		virtual void rotate() override;
	};
