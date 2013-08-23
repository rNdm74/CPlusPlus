#pragma once
#include "block.h"

ref class T :
public Block
	{
	public:
		T(Color color, Grid^ grid);
		virtual void rotate(array<Point>^ temp) override;
	};
