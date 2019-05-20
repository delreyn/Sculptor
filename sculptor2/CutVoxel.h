#pragma once
#include "FiguraGeometrica.h"

/**
* @file CutVoxel.h
* @brief this header file will contain all required
* definitions and basic utilities functions for cut a Voxel in the sculpture.
*
* @author Reyne Jasson
*
* @date 19/05/2019
*/
class CutVoxel :
	public FiguraGeometrica
{
	int m_x, m_y, m_z;
public:
	CutVoxel(int x, int y, int z);
	void draw(Sculptor& t);

};

