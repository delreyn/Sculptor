#include "PutBox.h"



PutBox::PutBox(int x0, int y0, int z0, int x1, int y1, int z1, float r, float g, float b, float a)
	: m_x0(x0), m_y0(y0), m_z0(z0),
	m_x1(x1), m_y1(y1), m_z1(z1),
	m_r(r), m_g(g), m_b(b), m_a(a)
{
}

void PutBox::draw(Sculptor& t)
{
	t.setColor(m_r, m_g, m_b, m_a);
	t.putBox(m_x0, m_x1, m_y0, m_y1, m_z0, m_z1);
}
