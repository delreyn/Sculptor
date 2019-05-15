#include "CutVoxel.h"

#include <iostream>

CutVoxel::CutVoxel(int x, int y, int z) : m_x(x), m_y(y), m_z(z)
{
}

void CutVoxel::draw(Sculptor& t)
{
	t.cutVoxel(m_x, m_y, m_z);
	//std::cout << "dreww";
}

