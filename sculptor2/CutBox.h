#pragma once
#include "FiguraGeometrica.h"
class CutBox :
	public FiguraGeometrica
{
	int	m_x0, m_y0, m_z0,
		m_x1, m_y1, m_z1;
public:
	CutBox(int x0, int y0, int z0, int x1, int y1, int z1);
	void draw(Sculptor& t);
};

