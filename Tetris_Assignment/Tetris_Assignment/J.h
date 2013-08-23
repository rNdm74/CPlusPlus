#pragma once
#include "block.h"

ref class J :
public Block
	{
	public:
		J(Color color, Grid^ grid);
		virtual void rotate(array<Point>^ temp) override;
	};
