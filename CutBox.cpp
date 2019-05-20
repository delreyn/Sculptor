#include "CutBox.h"

/**
* This method will be used to iniatilize local variables to cut a Box.
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
* @date 19/05/2019
*/
CutBox::CutBox(int x0, int y0, int z0, int x1, int y1, int z1)
	: m_x0(x0), m_y0(y0), m_z0(z0),
	m_x1(x1), m_y1(y1), m_z1(z1)
{
}

/**
* This method will be used to turn off all Voxels from x0 to x, y0 to y and z0 to z.
*
* @author Reyne Jasson
*
* @param t	An Sculptor class to be draw
*
* @date 19/05/2019
*/
void CutBox::draw(Sculptor& t)
{
	int i, j, k;
	for (i = m_z0; i < m_z1; i++) {
		for (j = m_y0; j < m_y1; j++) {
			for (k = m_x0; k < m_x1; k++) {
				t.cutVoxel(i, j, k);
			}
		}
	}
}

