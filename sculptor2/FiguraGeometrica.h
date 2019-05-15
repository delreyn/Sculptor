#pragma once

#include "VoxelClass.h"

class FiguraGeometrica
{
public:
	FiguraGeometrica();
	virtual void draw(Sculptor& t) = 0;
	~FiguraGeometrica();
};

