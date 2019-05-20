#include "PutSphere.h"

/**
* This method will be used to insert an Ellipsoid shaped object with radius (rx,ry,rz),
*center point (x,y,z), colors(r,g,b) and tranparency a.
*
* @author Reyne Jasson
*
* @param x0	An integer number of the x-axis sphere center coordinate
* @param y0	An integer number of the y-axis sphere center coordinate
* @param z0	An integer number of the z-axis sphere center coordinate
* @param rd An integer number defining the lenght of the sphere radius
* @param r [0,1] interval defining the red color of the Ellipsoid to be drawn
* @param g [0,1] interval defining the green color of the Ellipsoid to be drawn
* @param b [0,1] interval defining the blue color of the Ellipsoid to be drawn
* @param a [0,1] interval defining the tranparency value of the Ellipsoid to be drawn
*
* @date 19/05/2019
*/

PutSphere::PutSphere(int x0, int y0, int z0, int rd, float r, float g, float b, float a)
	: m_x0(x0), m_y0(y0), m_z0(z0), m_rd(rd),
	m_r(r), m_g(g), m_b(b), m_a(a)
{
}
/**
* This method will be used to effectively draw in the sculpture object t.
*
* @author Reyne Jasson
* @param t	A Sculptor Object in which to draw
*
* @date 19/05/2019
*/
void PutSphere::draw(Sculptor& t)
{
	int i, j, k;
	float DisX, DisY, DisZ;
	
	t.setColor(m_r, m_b, m_b, m_a);
	
	//Verifies if Radius <= distance(center, point)
	for (i = m_z0 - m_rd; i < m_z0 + m_rd; i++) {
		DisZ = (static_cast<float>(i - m_z0)) / (static_cast<float>(m_rd));
		for (j = m_y0 - m_rd; j < m_y0 + m_rd; j++) {
			DisY = (static_cast<float>(j - m_y0)) / (static_cast<float>(m_rd));
			for (k = m_x0 - m_rd; k < m_x0 + m_rd; k++) {
				DisX = (static_cast<float>(k - m_x0)) / (static_cast<float>(m_rd));
				if ((DisX * DisX + DisY * DisY + DisZ * DisZ) <= 1.00) {
					t.putVoxel(i, j, k);
				}
			}
		}
	}
}


