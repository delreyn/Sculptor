#pragma once
#include "FiguraGeometrica.h"
class PutSphere :
	public FiguraGeometrica
{
	int m_x0, m_y0, m_z0, m_rd;
	float m_r, m_g, m_b, m_a;

public:
	PutSphere(int x0, int y0, int z0, int rd, float r, float g, float b, float a);
	void draw(Sculptor& t);
};

