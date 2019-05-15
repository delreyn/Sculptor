#pragma once
#include "FiguraGeometrica.h"
class PutBox :
	public FiguraGeometrica
{

	int	m_x0, m_y0, m_z0,
		m_x1, m_y1, m_z1;
	float m_r, m_g, m_b, m_a;

public:
	PutBox(int x0, int y0, int z0, int x1, int y1, int z1, float r, float g, float b, float a);
	void draw(Sculptor& t);
};

