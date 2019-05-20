#include "VoxelClass.h"
#include <cstdlib>		// for exit()
#include <iostream>		// for std::cout std::cerr
#include <string>		//for std::string
#include <fstream>		//for std::ofstream
#include <algorithm>	// for std::swap()


/**
* @file VoxelClass.cpp
* @brief this cpp file will contain all required
*functions as well as their usage information to the VoxelClass.
*
* @author Reyne Jasson
*
* @date 01/05/2019
*/


//##########################----Functions for validation----############################

bool Sculptor::validVoxel(int x, int y, int z) {
	if (x < nx && x >= 0) {
		if (y < ny && y >= 0) {
			if (z < nz && z >= 0) {
				return true;
			}
		}
	}
	return false;
}

void Sculptor::validRange(int &x0, int &y0, int &z0, int &x, int &y, int &z) {

	//Make sure the coordinates are within the Voxel space
	if (x < 0) x = 0;
	if (x0 >= nx) x0 = nx - 1;
	if (x0 < 0) x0 = 0;
	if (x >= nx) x = nx - 1;

	if (y < 0) y = 0;
	if (y0 >= ny) y0 = ny - 1;
	if (y0 < 0) y0 = 0;
	if (y >= ny) y = ny - 1;

	if (z < 0) z = 0;
	if (z0 >= nz) z0 = nz - 1;
	if (z0 < 0) z0 = 0;
	if (z >= nz) z = nz - 1;

	//swap if (X0 || Y0 || Z0) >( X || Y || Z)

	if (x < x0) std::swap(x, x0);
	if (y < y0) std::swap(y, y0);
	if (z < z0) std::swap(z, z0);

}

//#######################################################################################

/**
* This method will be used to generate a dynamically allocated 3D matrix
* intented for the Sculptor Application (default: _nx = _ny =_nz = 20). 
* @author Reyne Jasson
* @param _nx	The sculpture x-axis maximun size 
* @param _ny	The sculpture y-axis maximun size
* @param _nz	The sculpture z-axis maximun size
* @date 01/05/2019
*/
Sculptor::Sculptor(int _nx = 20, int _ny=20, int _nz=20) : r(0.5), g(0.5), b(0.5), a(0.5)
{
	int i;
	
	if (_nx <= 0 || _ny <= 0 || _nz <= 0) std::cout << "Invalid dimensions! setting to 2x2x2 Sculpt";
	if (_nx <= 0) _nx = 2;
	if (_ny <= 0) _ny = 2;
	if (_nz <= 0) _nz = 2;

	nx = _nx;
	ny = _ny;
	nz = _nz;


	v = new Voxel**[_nx];
	v[0] = new Voxel*[_nx*_ny];
	v[0][0] = new Voxel[_nx*_ny*_nz];
	
	if (!(v && v[0] && v[0][0])) {
		std::cerr << "Couldn't allocate 3D Space. exiting... \n";
		std::exit(1);
	}

	
	for (i = 1; i < nz; i++) {
		v[i] = v[i - 1] + ny;
	}
	for (i = 1; i < nz*ny; i++) {
		v[0][i] = v[0][i - 1] + nx;
	}

	for (int i = 0; i < nz; i++) {
		for (int j = 0; j < ny; j++) {
			for (int k = 0; k < nx; k++) {
				v[i][j][k].r = r;
				v[i][j][k].g = g;
				v[i][j][k].b = b;
				v[i][j][k].a = a;
				v[i][j][k].isOn = false;
			}
		}
	}

	
	std::cout << "Sculpt Space sucessfully created! \n";
}
/**
* This method will be used to destroy the 3D matrix and return the allocated memory.
* @author Reyne Jasson
* 
* @date 01/05/2019
*/
Sculptor::~Sculptor(){
	delete[] v[0][0];
	delete[] v[0];
	delete[] v;
	std::cout << "\nSculpt Space sucessfully destroyed \n";
}
/**
* This method will be used to set/change the color and transparency used to put an Voxel.
* @author Reyne Jasson
* @param r	A float number ranging from [0,1] to describe the RED color in the Voxel 
* @param g	A float number ranging from [0,1] to describe the GREEN color in the Voxel
* @param b	A float number ranging from [0,1] to describe the BLUE color in the Voxel
* @param alpha	An float number ranging from [0,1] to describe the transparency of the Voxel
* @date 01/05/2019
*/
void Sculptor::setColor(float r, float g, float b, float alpha) {
	
	if (r < 0) r = 0;
	else if (r > 1) r = 1;

	if (g < 0) g = 0;
	else if (g > 1) g = 1;

	if (b < 0) b = 0;
	else if (b > 1) b = 1;

	if (alpha < 0) alpha = 0;
	else if (alpha > 1) alpha = 1;
	
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = alpha;
	//std::cout << "color set! \n";
}
/**
* This method will be used to put a Voxel in an (x,y,z) coordinate
* with the current drawing colors and transparency values.
* @author Reyne Jasson
* @param z	A integer number of the z coordinate intended to put the Voxel
* @param y	A integer number of the y coordinate intended to put the Voxel
* @param x	A integer number of the x coordinate intended to put the Voxel
* 
* @date 01/05/2019
*/
void Sculptor::putVoxel(int z, int y, int x) {

	if (!validVoxel(x, y, z)) { /*std::cerr << "Invalid Voxel Location! \n";*/ return; }

	v[z][y][x].isOn = true;
	v[z][y][x].r = r;
	v[z][y][x].g = g;
	v[z][y][x].b = b;
	v[z][y][x].a = a;
}
/**
* This method will be used to turn off a Voxel in an (x,y,z) coordinate.
* 
* @author Reyne Jasson
* @param z	A integer number of the z coordinate intended to cut the Voxel
* @param y	A integer number of the y coordinate intended to cut the Voxel
* @param x	A integer number of the x coordinate intended to cut the Voxel
*
* @date 01/05/2019
*/
void Sculptor::cutVoxel(int z, int y, int x) {
	if (!validVoxel(x,y,z)){ 
		//std::cerr << "Invalid Voxel Location! \n";
		return;
	}

	v[z][y][x].isOn = false;
}
/**
* This method will be used to turn on all voxels from x0 to x, y0 to y and z0 to z
* with the current drawing colors and transparency values.
*
* @author Reyne Jasson
*
* @param x0	A integer number of the x-axis starting coordinate  
* @param x1	A integer number of the x-axis final coordinate
* @param y0	A integer number of the y-axis starting coordinate
* @param y1	A integer number of the y-axis final coordinate
* @param z0	A integer number of the z-axis starting coordinate
* @param z1	A integer number of the z-axis final coordinate
*
* @date 01/05/2019
*/
void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1) {
	
	//validRange(x0, y0, z0, x1, y1, z1);

	int i, j, k;
	for (i = z0; i < z1; i++) {
		for (j = y0; j < y1; j++) {
			for (k = x0; k < x1; k++) {
				v[i][j][k].isOn = true;
				v[i][j][k].r = r;
				v[i][j][k].g = g;
				v[i][j][k].b = b;
			}
		}
	}

}
/**
* This method will be used to turn off all Voxels from x0 to x, y0 to y and z0 to z.
* 
* @author Reyne Jasson
*
* @param x0	A integer number of the x-axis starting coordinate
* @param x1	A integer number of the x-axis final coordinate
* @param y0	A integer number of the y-axis starting coordinate
* @param y1	A integer number of the y-axis final coordinate
* @param z0	A integer number of the z-axis starting coordinate
* @param z1	A integer number of the z-axis final coordinate
*
* @date 01/05/2019
*/
void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1) {

	//validRange(x0, y0, z0, x1, y1, z1,nx,ny,nz);

	int i, j, k;
	for (i = z0; i < z1; i++) {
		for (j = y0; j < y1; j++) {
			for (k = x0; k < x1; k++) {
				cutVoxel(i, j, k);
			}
		}
	}

}
/**
* This method will be used to generate an sphere with radius and 
* center point (x,y,z) with the current valus of colors and transparency.
*
* @author Reyne Jasson
*
* @param x	An integer number of the x-axis sphere center coordinate
* @param y	An integer number of the y-axis sphere center coordinate
* @param z	An integer number of the z-axis sphere center coordinate
* @param radius An integer number defining the lenght of the sphere radius
*
* @date 01/05/2019
*/
void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius) {
	int i, j, k;
	float DisX, DisY, DisZ;

	//Verifies if Radius <= distance(center, point)
	for (i = 0; i < nz; i++) {
		DisZ = (static_cast<float>(i - zcenter)) / (static_cast<float>(radius));
		for (j = 0; j < ny; j++) {
			DisY = (static_cast<float>(j - ycenter)) / (static_cast<float>(radius));
			for (k = 0; k < nx; k++) {
				DisX = (static_cast<float>(k - xcenter)) / (static_cast<float>(radius));
				if ((DisX*DisX + DisY * DisY + DisZ * DisZ) <= 1.00) {
					putVoxel(i, j, k);
				}
			}
		}
	}
}
/**
* This method will be used to remove a sphere shaped 3D object with radius and
* center point (x,y,z).
*
* @author Reyne Jasson
*
* @param x	An integer number of the x-axis sphere center coordinate
* @param y	An integer number of the y-axis sphere center coordinate
* @param z	An integer number of the z-axis sphere center coordinate
* @param radius An integer number defining the lenght of the sphere radius
*
* @date 01/05/2019
*/
void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius) {
	int i, j, k;
	double DisX, DisY, DisZ;

	//Verifies if Radius <= distance(center, point)
	for (i = 0; i < nz; i++) {
		DisZ = (static_cast<double>(i - zcenter)) / static_cast<double>(radius);

		for (j = 0; j < ny; j++) {
			DisY = (static_cast<double>(j - ycenter)) / static_cast<double>(radius);

			for (k = 0; k < nx; k++) {
				DisX = (static_cast<double>(k - xcenter)) / static_cast<double>(radius);
				if (((DisX*DisX + DisY * DisY + DisZ * DisZ) <= 1.00)) {
					cutVoxel(i, j, k);
				}
			}
		}
	}
}
/**
* This method will be used to insert an Ellipsoid shaped object with radius (rx,ry,rz)
* and center point (x,y,z).
*
* @author Reyne Jasson
*
* @param x	An integer number of the x-axis sphere center coordinate
* @param y	An integer number of the y-axis sphere center coordinate
* @param z	An integer number of the z-axis sphere center coordinate
* @param rx An integer number defining the lenght of the x-axis sphere radius
* @param ry An integer number defining the lenght of the y-axis sphere radius
* @param rz An integer number defining the lenght of the z-axis sphere radius
*
* @date 01/05/2019
*/
void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz) {

	int i, j, k;
	double DisX, DisY, DisZ;

	//Verifies if Radius <= distance(center, point)
	for (i = 0; i < nz; i++) {
		DisZ = (static_cast<double>(i - zcenter)) / static_cast<double>(rz);
		for (j = 0; j < ny; j++) {
			DisY = (static_cast<double>(j - ycenter)) / static_cast<double>(ry);
			for (k = 0; k < nx; k++) {
				DisX = (static_cast<double>(k - xcenter)) / static_cast<double>(rx);
				if (((DisX*DisX + DisY * DisY + DisZ * DisZ) <= 1.00)) {
					putVoxel(i, j, k);
				}
			}
		}
	}
}
/**
* This method will be used to cut an Ellipsoid shaped object with radius (rx,ry,rz)
* and center point (x,y,z).
*
* @author Reyne Jasson
*
* @param x	An integer number of the x-axis sphere center coordinate
* @param y	An integer number of the y-axis sphere center coordinate
* @param z	An integer number of the z-axis sphere center coordinate
* @param rx An integer number defining the lenght of the x-axis sphere radius
* @param ry An integer number defining the lenght of the y-axis sphere radius
* @param rz An integer number defining the lenght of the z-axis sphere radius
*
* @date 01/05/2019
*/
void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz) {

	int i, j, k;
	double DisX, DisY, DisZ;

	//Verifies if Radius <= distance(center, point)
	for (i = 0; i < nz; i++) {
		DisX = (static_cast<double>(i - zcenter)) / static_cast<double>(rz);
		for (j = 0; j < ny; j++) {
			DisY = (static_cast<double>(j - ycenter)) / static_cast<double>(ry);
			for (k = 0; k < nx; k++) {
				
				DisZ = (static_cast<double>(k - xcenter)) / static_cast<double>(rx);
				if ((DisX*DisX + DisY * DisY + DisZ * DisZ) <= 1.00) {
					cutVoxel(i, j, k);
				}
			}
		}
	}
}

/*void Sculptor::shell() {
	
	int i, j, k;

	bool ***temp = new bool**[nz];
	temp[0] = new bool*[nz*ny];
	temp[0][0] = new bool[nx*ny*nz];

	if (!(temp && temp[0] && temp[0][0])) {
		std::cerr << "Couldn't optimize by destroying the hidden Voxels: "
				  << "Failed to create the auxiliar matrix \n";
		return;
	}

	for (i = 1; i < nz; i++) {
		temp[i] = temp[i - 1] + ny;
	}
	for (i = 1; i < nz*ny; i++) {
		temp[0][i] = temp[0][i - 1] + nx;
	}

	for (i = 0; i < nz; i++)
		for (j = 0; j < ny; j++)
			for (k = 0; k < nx; k++)
				temp[i][j][k] = v[i][j][k].isOn;

	for (i = 1; i < nz-1; i++)
		for (j = 1; j < ny-1; j++)
			for (k = 1; k < nx-1; k++)
				if (temp[i - 1][j][k] && temp[i + 1][j][k]
					&& temp[i][j - 1][k] && temp[i][j + 1][k]
					&& temp[i][j][k - 1] && temp[i][j][k + 1])  v[i][j][k].isOn = false;

	
	delete[] temp[0][0];
	delete[] temp[0];
	delete[] temp;

}
*/
/**
* This method will be used to save the 3D object to an OFF(Object File Format) file
* with optional optimization by removing hidden voxels.
*
* @author Reyne Jasson
*
* @param filename	A String containing the path and file name of the desired file 
* @param shell	Boolean value used to define if optimization will be used true = yes, false = no (Default: true)
*
* @date 01/05/2019
*/
void Sculptor::writeOFF(std::string filename){
	
	std::ofstream ofile;

	ofile.open(filename);
	int countVox = 0;
	int face=0;
	int nfacs = 0;


	if (!ofile.is_open()) {
		std::cerr << "Fail to save OFF file \n";
		return;
	}

	if (1) {
		//Optimizing writing process by making an copy of voxel sculpture to turn off hidden voxels

		//creating temporary 3D matrix
		bool ***temp = new bool**[nz];
		temp[0] = new bool*[nz*ny];
		temp[0][0] = new bool[nx*ny*nz];

		if (!(temp && temp[0] && temp[0][0])) {
			std::cerr << "Couldn't optimize by destroying the hidden Voxels: "
				<< "Failed to create the auxiliar matrix \n";
			return;
		}

		//Setting up addresses
		for (int i = 1; i < nz; i++) {
			temp[i] = temp[i - 1] + ny;
		}
		for (int i = 1; i < nz*ny; i++) {
			temp[0][i] = temp[0][i - 1] + nx;
		}

		//copying
		for (int i = 0; i < nz; i++)
			for (int j = 0; j < ny; j++)
				for (int k = 0; k < nx; k++)
					temp[i][j][k] = v[i][j][k].isOn;

		//comparing to confirm if an voxel is hidden
		for (int i = 1; i < nz - 1; i++)
			for (int j = 1; j < ny - 1; j++)
				for (int k = 1; k < nx - 1; k++)
					if (temp[i - 1][j][k] && temp[i + 1][j][k]
						&& temp[i][j - 1][k] && temp[i][j + 1][k]
						&& temp[i][j][k - 1] && temp[i][j][k + 1])  v[i][j][k].isOn = false;

		//destroying temp matrix
		delete[] temp[0][0];
		delete[] temp[0];
		delete[] temp;
	}

	ofile << "OFF ";

	for (int i = 0; i < nz; i++)
		for (int j = 0; j < ny; j++)
			for (int k = 0; k < nx; k++)
				if (v[i][j][k].isOn) 
					countVox++;

	ofile << 8 * countVox << " " << 6 * countVox << " 0\n";

	for (int k = 0; k < nz; k++) {
		for (int j = 0; j < ny; j++) {
			for (int i = 0; i < nx; i++) {
				if (v[k][j][i].isOn) {
				  ofile << i - 0.5 << " " << j + 0.5 << " " << k - 0.5 << "\n"
						<< i - 0.5 << " " << j - 0.5 << " " << k - 0.5 << "\n"
						<< i + 0.5 << " " << j - 0.5 << " " << k - 0.5 << "\n"
						<< i + 0.5 << " " << j + 0.5 << " " << k - 0.5 << "\n"
						<< i - 0.5 << " " << j + 0.5 << " " << k + 0.5 << "\n"
						<< i - 0.5 << " " << j - 0.5 << " " << k + 0.5 << "\n"
						<< i + 0.5 << " " << j - 0.5 << " " << k + 0.5 << "\n"
						<< i + 0.5 << " " << j + 0.5 << " " << k + 0.5 << "\n";
				}
			}
		}
	}
	
	for (int i = 0; i < nz; i++) {
		for (int j = 0; j < ny; j++) {
			for (int k = 0; k < nx; k++) {
				if (v[i][j][k].isOn) {
					face = 8 * nfacs;
					ofile << "4 " << face + 0 << " " << face + 3 << " " << face + 2 << " " << face + 1 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << "\n"
						<< "4 " << face + 4 << " " << face + 5 << " " << face + 6 << " " << face + 7 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << "\n"
						<< "4 " << face + 0 << " " << face + 1 << " " << face + 5 << " " << face + 4 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << "\n"
						<< "4 " << face + 0 << " " << face + 4 << " " << face + 7 << " " << face + 3 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << "\n"
						<< "4 " << face + 3 << " " << face + 7 << " " << face + 6 << " " << face + 2 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << "\n"
						<< "4 " << face + 1 << " " << face + 2 << " " << face + 6 << " " << face + 5 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << "\n";
					nfacs++;
				}
			}
		}
	}
	
	ofile.close();
	std::cout << "OFF file sucessfully created! \n";

}
/**
* This method will be used to save the 3D object to an VECT file
* with optional optimization by removing hidden voxels.
*
* @author Reyne Jasson
*
* @param filename	A String containing the path and file name of the desired file
* @param shell	Boolean value used to define if optimization will be used true = yes, false = no (Default: true)
*
* @date 01/05/2019
*/
void Sculptor::writeVECT(std::string filename) {

	int countVox=0;

	std::ofstream ofile;

	ofile.open(filename);

	if (1) {
		//Optimizing writing process by making an copy of voxel sculpture to turn off hidden voxels

		//creating temporary 3D matrix
		bool ***temp = new bool**[nz];
		temp[0] = new bool*[nz*ny];
		temp[0][0] = new bool[nx*ny*nz];

		if (!(temp && temp[0] && temp[0][0])) {
			std::cerr << "Couldn't optimize by destroying the hidden Voxels: "
				<< "Failed to create the auxiliar matrix \n";
			return;
		}

		//Setting up addresses
		for (int i = 1; i < nz; i++) {
			temp[i] = temp[i - 1] + ny;
		}
		for (int i = 1; i < nz*ny; i++) {
			temp[0][i] = temp[0][i - 1] + nx;
		}

		//copying
		for (int i = 0; i < nz; i++)
			for (int j = 0; j < ny; j++)
				for (int k = 0; k < nx; k++)
					temp[i][j][k] = v[i][j][k].isOn;

		//comparing to confirm if an voxel is hidden
		for (int i = 1; i < nz - 1; i++)
			for (int j = 1; j < ny - 1; j++)
				for (int k = 1; k < nx - 1; k++)
					if (temp[i - 1][j][k] && temp[i + 1][j][k]
						&& temp[i][j - 1][k] && temp[i][j + 1][k]
						&& temp[i][j][k - 1] && temp[i][j][k + 1])  v[i][j][k].isOn = false;

		//destroying temp matrix
		delete[] temp[0][0];
		delete[] temp[0];
		delete[] temp;
	}

	if (!ofile.is_open()) {
		std::cerr << "Fail to create VECT file \n";
		return;
	}

	//Countig Voxels
	for (int i = 0; i < nz; i++) 
		for (int j = 0; j < ny; j++)
			for (int k = 0; k < nx; k++) 
				if (v[i][j][k].isOn) countVox++;
			
	//In this aplications is assumed polign is one pixel
	ofile << "VECT ";
	ofile << countVox<<" "<< countVox<<" "<< countVox << "\n";
	
	//wrinting voxels and colors
	for (int i = 0; i < countVox; i++) {
		ofile << "1 ";
	}
	ofile << " ";

	for (int i = 0; i < countVox; i++) {
		ofile << "1 ";
	}
	ofile << " ";

	//Writing coordinates
	for (int i = 0; i < nz; i++)
		for (int j = 0; j < ny; j++)
			for (int k = 0; k < nx; k++)
				if (v[i][j][k].isOn) ofile << i << " " << j << " " << k << "\n";
	
	//Writing Colors(RGB) codes and transparency alpha
	for (int i = 0; i < nz; i++)
		for (int j = 0; j < ny; j++)
			for (int k = 0; k < nx; k++)
				if (v[i][j][k].isOn) 
					ofile << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b <<" "<< v[i][j][k].a << "\n";

	ofile.close(); 
	std::cout << "VECT file sucessfully created! \n";
	
}