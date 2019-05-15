#include "PutVoxel.h"


PutVoxel::PutVoxel(int x, int y, int z, float r, float g, float b, float a) 
	: m_x(x), m_y(y), m_z(z),
m_r(r), m_g(g), m_b(b), m_a(a)
{
}

void PutVoxel::draw(Sculptor& t) {
	t.setColor(m_r, m_g, m_b, m_a);
	t.putVoxel(m_x, m_y, m_z);

}

PutVoxel::~PutVoxel()
{
}
