#pragma once
#include "FiguraGeometrica.h"

/**
* @file CutEllipsoid.h
* @brief this header file will contain all required
* definitions and basic utilities functions for put a sphere shaped object in the sculpture.
*
* @author Reyne Jasson
*
* @date 19/05/2019
*/
class PutSphere :
	public FiguraGeometrica
{
	int m_x0, m_y0, m_z0, m_rd;
	float m_r, m_g, m_b, m_a;

public:
	PutSphere(int x0, int y0, int z0, int rd, float r, float g, float b, float a);
	void draw(Sculptor& t);
};

