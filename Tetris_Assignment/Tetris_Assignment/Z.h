#pragma once
#include "block.h"

ref class Z :
public Block
	{
	public:
		Z(Color color, Grid^ grid);
		virtual void rotate(array<Point>^ temp) override;
	};
