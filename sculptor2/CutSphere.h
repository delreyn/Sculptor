#pragma once
#include "FiguraGeometrica.h"
class CutSphere :
	public FiguraGeometrica
{
	int m_x0, m_y0, m_z0, m_rd;
public:
	CutSphere(int x0, int y0, int z0, int rd);
	void draw(Sculptor& t);
	
};

