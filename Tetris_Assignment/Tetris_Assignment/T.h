#pragma once
#include "block.h"

ref class T :
public Block
	{
	public:
		T(array<Point>^ square, Color color, Grid^ grid);
		virtual void rotate() override;
	};
