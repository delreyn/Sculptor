#pragma once
#include "FiguraGeometrica.h"
class CutVoxel :
	public FiguraGeometrica
{
	int m_x, m_y, m_z;
public:
	CutVoxel(int x, int y, int z);
	void draw(Sculptor& t);

};

