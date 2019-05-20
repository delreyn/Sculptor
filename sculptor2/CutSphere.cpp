#include "CutSphere.h"


/**
* This method will be used to remove a sphere shaped 3D object with radius and
* center point (x,y,z).
*
* @author Reyne Jasson
*
* @param x0	An integer number of the x-axis sphere center coordinate
* @param y0	An integer number of the y-axis sphere center coordinate
* @param z0	An integer number of the z-axis sphere center coordinate
* @param rd An integer number defining the lenght of the sphere radius
*
* @date 19/05/2019
*/
CutSphere::CutSphere(int x0, int y0, int z0, int rd): m_x0(x0), m_y0(y0), m_z0(z0), m_rd(rd)
{
}

/**
* This method will be used to remove a sphere shaped 3D object with radius and
* center point (x,y,z) from the Sculpture Object t.
*
* @author Reyne Jasson
*
* @param t	ASculpture Object to draw
*
* @date 19/05/2019
*/
void CutSphere::draw(Sculptor& t)
{
	int i, j, k;
	float DisX, DisY, DisZ;

	//Verifies if Radius <= distance(center, point)
	for (i = m_z0-m_rd; i < m_z0+m_rd; i++) {
		DisZ = (static_cast<float>(i - m_z0)) / (static_cast<float>(m_rd));
		for (j = m_y0 - m_rd; j < m_y0 + m_rd; j++) {
			DisY = (static_cast<float>(j - m_y0)) / (static_cast<float>(m_rd));
			for (k = m_x0 - m_rd; k< m_x0 + m_rd; k++) {
				DisX = (static_cast<float>(k - m_x0)) / (static_cast<float>(m_rd));
				if ((DisX * DisX + DisY * DisY + DisZ * DisZ) <= 1.00) {
					t.cutVoxel(i, j, k);
				}
			}
		}
	}
}

