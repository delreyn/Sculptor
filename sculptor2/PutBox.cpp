#include "PutBox.h"


/**
* This method will be used to turn on all voxels from x0 to x, y0 to y and z0 to z
* with supplied colors and tranparency values.
*
* @author Reyne Jasson
*
* @param x0	A integer number of the x-axis starting coordinate
* @param x1	A integer number of the x-axis final coordinate
* @param y0	A integer number of the y-axis starting coordinate
* @param y1	A integer number of the y-axis final coordinate
* @param z0	A integer number of the z-axis starting coordinate
* @param z1	A integer number of the z-axis final coordinate
*
* @param r [0,1] interval defining the red color of the box to be drawn
* @param g [0,1] interval defining the green color of the box to be drawn
* @param b [0,1] interval defining the blue color of the box to be drawn
* @param a [0,1] interval defining the tranparency value of the box to be drawn
*
* @date 19/05/2019
*/
PutBox::PutBox(int x0, int y0, int z0, int x1, int y1, int z1, float r, float g, float b, float a)
	: m_x0(x0), m_y0(y0), m_z0(z0),
	m_x1(x1), m_y1(y1), m_z1(z1),
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
void PutBox::draw(Sculptor& t)
{
	t.setColor(m_r, m_g, m_b, m_a);
	int i, j, k;
	for (i = m_z0; i < m_z1; i++) {
		for (j = m_y0; j < m_y1; j++) {
			for (k = m_x0; k < m_x1; k++) {
				t.putVoxel(i, j, k);
			}
		}
	}
}
