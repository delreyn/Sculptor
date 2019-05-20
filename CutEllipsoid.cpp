#include "CutEllipsoid.h"


/**
* This method will be used to cut an Ellipsoid shaped object with radius (rx,ry,rz)
* and center point (x,y,z).
*
* @author Reyne Jasson
*
* @param x0	An integer number of the x-axis sphere center coordinate
* @param y0	An integer number of the y-axis sphere center coordinate
* @param z0	An integer number of the z-axis sphere center coordinate
* @param rdX An integer number defining the lenght of the x-axis sphere radius
* @param rdY An integer number defining the lenght of the y-axis sphere radius
* @param rdZ An integer number defining the lenght of the z-axis sphere radius
*
* @date 19/05/2019
*/
CutEllipsoid::CutEllipsoid(int x0, int y0, int z0, int rdX, int rdY, int rdZ)
	: m_x0(x0), m_y0(y0), m_z0(z0),
	m_rdX(rdX), m_rdY(rdY), m_rdZ(rdZ)
{
}

/**
* This method will be used to cut an Ellipsoid shaped object with radius (rx,ry,rz)
* and center point (x,y,z) in the Sculpture t object.
*
* @author Reyne Jasson
*
* @param t	An integer number of the x-axis sphere center coordinate
*
* @date 19/05/2019
*/
void CutEllipsoid::draw(Sculptor& t){

	int i, j, k;
	double DisX, DisY, DisZ;

	for (i = m_z0-m_rdZ; i < m_z0 + m_rdZ; i++) {
		DisX = (static_cast<double>(i - m_z0)) / static_cast<double>(m_rdZ);
		for (j = m_y0 - m_rdY; j < m_y0 + m_rdY; j++) {
			DisY = (static_cast<double>(j - m_y0)) / static_cast<double>(m_rdY);
			for (k = m_x0 - m_rdX; k < m_x0 + m_rdX; k++) {
				DisZ = (static_cast<double>(k - m_x0)) / static_cast<double>(m_rdX);
				if ((DisX * DisX + DisY * DisY + DisZ * DisZ) <= 1.00) {
					t.cutVoxel(i, j, k);
				}
			}
		}
	}
	// t.cutEllipsoid(m_x0, m_y0, m_z0, m_rdX, m_rdY, m_rdZ);
}

