#include "CutSphere.h"



CutSphere::CutSphere(int x0, int y0, int z0, int rd): m_x0(x0), m_y0(y0), m_z0(z0), m_rd(rd)
{
}

void CutSphere::draw(Sculptor& t)
{
	t.cutSphere(m_x0, m_y0, m_z0, m_rd);
}

