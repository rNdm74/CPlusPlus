#pragma once
#include "block.h"

ref class I :
public Block
	{
	public:
		I(Color color, Grid^ grid);
		virtual void rotate(array<Point>^ temp) override;
	};
