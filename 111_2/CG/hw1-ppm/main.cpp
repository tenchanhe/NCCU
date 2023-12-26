#include <iostream>
#include <fstream>
//#include "vec3.h"

using namespace std;


int main()
{
	int width = 200;
	int height = 100;

	fstream file;
	file.open("ray.ppm", ios::out);

	file << "P3\n" << width << " " << height << "\n255\n";
	for (int j = height - 1; j >= 0; j--) {
		for (int i = 0; i < width; i++) {
			float r = float(i) / float(width);
			float g = float(j) / float(height);
			float b = 0.2;

			file << int(r * 255) << " " << int(g * 255) << " " << int(b * 255) << "\n";
		}
	}

	return 0;
}
