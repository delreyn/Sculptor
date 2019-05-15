#include "PutSphere.h"



PutSphere::PutSphere(int x0, int y0, int z0, int rd, float r, float g, float b, float a)
	: m_x0(x0), m_y0(y0), m_z0(z0), m_rd(rd),
	m_r(r), m_g(g), m_b(b), m_a(a)
{
}

void PutSphere::draw(Sculptor& t)
{
	t.setColor(m_r, m_b, m_b, m_a);
	t.putSphere(m_x0, m_y0, m_z0, m_rd);
}


