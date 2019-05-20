#pragma once

#include "VoxelClass.h"
/**
* @file FiguraGeometrica.h
* @brief this header file will contain interface class.
*it is used as the parent class to all the draw classes.
* @author Reyne Jasson
*
* @date 19/05/2019
*/
class FiguraGeometrica
{
public:
	virtual void draw(Sculptor& t) = 0;
};

