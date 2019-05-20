#include "CutVoxel.h"

#include <iostream>

/**
* This method will be used to turn off a Voxel in an (x,y,z) coordinate.
*
* @author Reyne Jasson
* @param x	A integer number of the x coordinate intended to cut the Voxel
* @param y	A integer number of the y coordinate intended to cut the Voxel
* @param z	A integer number of the y coordinate intended to cut the Voxel
*
* @date 19/05/2019
*/
CutVoxel::CutVoxel(int x, int y, int z) : m_x(x), m_y(y), m_z(z)
{
}
/**
* This method will be used to turn off a Voxel in an (x,y,z) coordinate from the Sculpture Object.
*
* @author Reyne Jasson
* @param t	A Sculptor Object in which to draw
*
* @date 19/05/2019
*/
void CutVoxel::draw(Sculptor& t)
{
	t.cutVoxel(m_z, m_y, m_x);
	//std::cout << "dreww";
}

