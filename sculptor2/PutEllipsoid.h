#pragma once
#include "FiguraGeometrica.h"
class PutEllipsoid :
	public FiguraGeometrica
{
	int	m_x0, m_y0, m_z0,
		m_rdX, m_rdY, m_rdZ;
	float m_r, m_g, m_b, m_a;
	
public:
	PutEllipsoid(int x0, int y0, int z0, int rdX, int rdY, int rdZ, float r, float g, float b, float a);
	void draw(Sculptor& t);
};
