#include "CutBox.h"


CutBox::CutBox(int x0, int y0, int z0, int x1, int y1, int z1)
	: m_x0(x0), m_y0(y0), m_z0(z0),
	m_x1(x1), m_y1(y1), m_z1(z1)
{
}

void CutBox::draw(Sculptor& t)
{
	t.cutBox(m_x0, m_x1, m_y0, m_y1, m_z0, m_z1);
}

