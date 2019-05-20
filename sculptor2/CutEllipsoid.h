#pragma once
#include "FiguraGeometrica.h"

/**
* @file CutEllipsoid.h
* @brief this header file will contain all required
* definitions and basic utilities functions for cut an Ellipsoid in the sculpture.
*
* @author Reyne Jasson
*
* @date 19/05/2019
*/

class CutEllipsoid :
	public FiguraGeometrica
{
	int	m_x0, m_y0, m_z0,
		m_rdX, m_rdY, m_rdZ;
public:
	CutEllipsoid(int x0, int y0, int z0, int rdX, int rdY, int rdZ);
	void draw(Sculptor& t);
};

