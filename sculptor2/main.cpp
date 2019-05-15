#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

#include "MyResources.h" //Contains all Sculpt headers

using std::cout;
using std::cin;

int main()
{
	std::vector<FiguraGeometrica*> figs;
	std::ifstream ifile("C:/Users/Reyne/Desktop/test.txt", std::ios::in);
	
	std::string part1;
	int nx, ny, nz;
	

	int x, y, z,
		x1, y1, z1,
		rd, rdx, rdy, rdz;
	float r, g, b, a;

	if (!ifile) {
		std::cerr << "Failed to open file. exiting...";
		std::exit(1);
	}

	ifile >> part1 >> nx >> ny >> nz;
	Sculptor S(nx, ny, nz);
	cout << "Sulpture size: " << nx << "x" << ny << "x" << nz << "\n\n";

	//reading the file while the end is not reached 
	while (ifile >> part1) {
		
		if ("putvoxel" == part1) {

			ifile >> x >> y >> z 
				>> r >> g >> b >> a;

			figs.push_back(new PutVoxel(x, y, z, r, g, b, a));
		}
		else if ("cutvoxel" == part1) {
			ifile >> x >> y >> z;

			figs.push_back(new CutVoxel(x, y, z));
		}
		else if ("putbox" == part1) {
			ifile >> x >> x1
				>> y >> y1
				>> z >> z1
				>> r >> g >> b >> a;

			figs.push_back(new PutBox(x, y, z, x1, y1, z1, r, g, b, a));
		}
		else if ("cutbox" == part1) {
			ifile >> x >> x1
				>> y >> y1
				>> z >> z1;

			figs.push_back(new CutBox(x, y, z, x1, y1, z1));

		}
		else if ("putsphere" == part1) {
			ifile >> x >> y >> z
				>> rd
				>> r >> g >> b >> a;

			figs.push_back(new PutSphere(x, y, z, rd, r, g, b, a));
		}
		else if ("cutsphere" == part1) {
			ifile >> x >> y >> z 
				>> rd;
			figs.push_back(new CutSphere(x, y, z, rd));
		}
		else if ("putellipsoid" == part1) {
			ifile >> x >> y >> z
				>> rdx >> rdy >> rdz
				>> r >> g >> b >> a;

			figs.push_back(new PutEllipsoid(x, y, z, rdx, rdy, rdz, r, g, b, a));

			/*cout << part1 << " " << x << " " << y << " " << z << " " << rdx <<" "<<rdy<<" "<<rdz<<" "
				<< r << " " << g << " " << b << " " << a << "\n";*/
		}
		else if ("cutellipsoid" == part1) {
			ifile >> x >> y >> z
				>> rdx >> rdy >> rdz;

			figs.push_back(new CutEllipsoid(x, y, z, rdx, rdy, rdz));

			//cout << part1 << " " << x << " " << y << " " << z << " " << rdx << " " << rdy << " " << rdz << "\n";
		}
		else {
			cout << "Invalid/corrupted file. exiting...\n";
			std::exit(1);
		}
	}

	//using a for-each to interate through the figs vector
	for (auto& fig : figs) {
		fig->draw(S);
		delete fig;
	}

	S.writeOFF("C:/Users/Reyne/Desktop/off.txt");
}
