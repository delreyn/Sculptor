#pragma once
#include "FiguraGeometrica.h"

/**
* @file CutSphere.h
* @brief this header file will contain all required
* definitions and basic utilities functions for cutan Sphere shaped object in the sculpture.
*
* @author Reyne Jasson
*
* @date 19/05/2019
*/
class CutSphere :
	public FiguraGeometrica
{
	int m_x0, m_y0, m_z0, m_rd;
public:
	CutSphere(int x0, int y0, int z0, int rd);
	void draw(Sculptor& t);
	
};

