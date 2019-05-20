#pragma once
#include "FiguraGeometrica.h"

/**
* @file CutVoxel.h
* @brief this header file will contain all required
* definitions and basic utilities functions for put a Voxel in the sculpture.
*
* @author Reyne Jasson
*
* @date 19/05/2019
*/
class PutVoxel :
	public FiguraGeometrica
{
	int m_x, m_y, m_z;
	float m_r, m_g, m_b, m_a;

public:
	PutVoxel(int x, int y, int z, float r, float g, float b, float a);
	void draw(Sculptor& t);
	~PutVoxel();
};

