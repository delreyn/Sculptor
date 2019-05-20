#include "PutVoxel.h"

/**
* This method will be used to turn off a Voxel in an (x,y,z) coordinate.
*
* @author Reyne Jasson
* @param x	A integer number of the x coordinate intended to put the Voxel
* @param y	A integer number of the y coordinate intended to put the Voxel
* @param z	A integer number of the y coordinate intended to put the Voxel
*
* @param r [0,1] interval defining the red color of the voxel to be drawn
* @param g [0,1] interval defining the green color of the voxel to be drawn
* @param b [0,1] interval defining the blue color of the voxel to be drawn
* @param a [0,1] interval defining the tranparency value of the voxel to be drawn
*
* @date 19/05/2019
*/
PutVoxel::PutVoxel(int x, int y, int z, float r, float g, float b, float a) 
	: m_x(x), m_y(y), m_z(z),
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
void PutVoxel::draw(Sculptor& t) {
	t.setColor(m_r, m_g, m_b, m_a);
	t.putVoxel(m_z, m_y, m_x);

}

PutVoxel::~PutVoxel()
{
}
