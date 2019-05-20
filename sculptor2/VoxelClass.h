#pragma once
#include<string>

/**
* @file VoxelClass.h
* @brief this header file will contain all required
* definitions and basic utilities functions for the Voxel sculpture.
*
* @author Reyne Jasson
*
* @date 01/05/2019
*/


struct Voxel {
	float r, g, b;	// Colors
	float a;		// Transparency
	bool isOn;		// Included or not
};

class Sculptor {
protected:
	Voxel ***v;			// 3D matrix
	int nx, ny, nz;		// Dimensions
	float r, g, b, a;	// Current drawing color
public:
	Sculptor(int _nx, int _ny, int _nz);
	~Sculptor();
	void setColor(float r, float g, float b, float alpha);
	void putVoxel(int z, int y, int x);
	void cutVoxel(int z, int y, int x);
	void putBox(int x0, int x1, int y0, int y1, int z0, int z1);
	void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
	void putSphere(int xcenter, int ycenter, int zcenter, int radius);
	void cutSphere(int xcenter, int ycenter, int zcenter, int radius);
	void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
	void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
	bool validVoxel(int x, int y, int z);
	void validRange(int& x0, int& y0, int& z0, int& x, int& y, int& z);
	void writeOFF(std::string filename);
	void writeVECT(std::string filename);
};
