#include "CutEllipsoid.h"



CutEllipsoid::CutEllipsoid(int x0, int y0, int z0, int rdX, int rdY, int rdZ)
	: m_x0(x0), m_y0(y0), m_z0(z0),
	m_rdX(rdX), m_rdY(rdY), m_rdZ(rdZ)
{
}

void CutEllipsoid::draw(Sculptor& t)
{
	t.cutEllipsoid(m_x0, m_y0, m_z0, m_rdX, m_rdY, m_rdZ);
}


