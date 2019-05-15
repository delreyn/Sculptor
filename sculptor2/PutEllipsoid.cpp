#include "PutEllipsoid.h"



PutEllipsoid::PutEllipsoid(int x0, int y0, int z0,int rdX,int rdY,int rdZ, float r, float g, float b, float a)
	: m_x0(x0), m_y0(y0), m_z0(z0), 
	m_rdX(rdX), m_rdY(rdY), m_rdZ(rdZ),
	m_r(r), m_g(g), m_b(b)
{

}

void PutEllipsoid::draw(Sculptor& t)
{
	t.setColor(m_r, m_g, m_b, m_a);
	t.putEllipsoid(m_x0, m_y0, m_z0, m_rdX, m_rdY, m_rdZ);
}

