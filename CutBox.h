#pragma once
#include "FiguraGeometrica.h"

/**
* @file CutBox.h
* @brief this header file will contain all required
*functions as well as their usage information to Cut a Box in the Sculpt.
*
* @author Reyne Jasson
*
* @date 19/05/2019
*/

class CutBox :
	public FiguraGeometrica
{
	int	m_x0, m_y0, m_z0,
		m_x1, m_y1, m_z1;
public:
	CutBox(int x0, int y0, int z0, int x1, int y1, int z1);
	void draw(Sculptor& t);
};

