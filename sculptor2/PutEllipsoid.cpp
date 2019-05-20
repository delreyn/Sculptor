#include "PutEllipsoid.h"

/**
* This method will be used to insert an Ellipsoid shaped object with radius (rx,ry,rz),
*center point (x,y,z), colors(r,g,b) and tranparency a.
*
* @author Reyne Jasson
*
* @param x0	An integer number of the x-axis sphere center coordinate
* @param y0	An integer number of the y-axis sphere center coordinate
* @param z0	An integer number of the z-axis sphere center coordinate
* @param rdX An integer number defining the lenght of the x-axis sphere radius
* @param rdY An integer number defining the lenght of the y-axis sphere radius
* @param rdZ An integer number defining the lenght of the z-axis sphere radius
* @param r [0,1] interval defining the red color of the Ellipsoid to be drawn
* @param g [0,1] interval defining the green color of the Ellipsoid to be drawn
* @param b [0,1] interval defining the blue color of the Ellipsoid to be drawn
* @param a [0,1] interval defining the tranparency value of the Ellipsoid to be drawn
*
* @date 19/05/2019
*/

PutEllipsoid::PutEllipsoid(int x0, int y0, int z0,int rdX,int rdY,int rdZ, float r, float g, float b, float a)
	: m_x0(x0), m_y0(y0), m_z0(z0), 
	m_rdX(rdX), m_rdY(rdY), m_rdZ(rdZ),
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
void PutEllipsoid::draw(Sculptor& t)
{

	int i, j, k;
	double DisX, DisY, DisZ;

	t.setColor(m_r, m_g, m_b, m_a);
	
	for (i = m_z0 - m_rdZ; i < m_z0 + m_rdZ; i++) {
		DisX = (static_cast<double>(i - m_z0)) / static_cast<double>(m_rdZ);
		for (j = m_y0 - m_rdY; j < m_y0 + m_rdY; j++) {
			DisY = (static_cast<double>(j - m_y0)) / static_cast<double>(m_rdY);
			for (k = m_x0 - m_rdX; k < m_x0 + m_rdX; k++) {
				DisZ = (static_cast<double>(k - m_x0)) / static_cast<double>(m_rdX);
				if ((DisX * DisX + DisY * DisY + DisZ * DisZ) <= 1.00) {
					t.putVoxel(i, j, k);
				}
			}
		}
	}
}

