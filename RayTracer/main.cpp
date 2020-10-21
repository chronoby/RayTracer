#include <iostream>
#include <fstream>

int main()
{
	const int width = 256;
	const int height = 256;

	std::ofstream outfile("../Output/Image.ppm", std::ios::out);
	outfile << "P3" << std::endl << width << " " << height << std::endl << 255 << std::endl;

	for (int j = height - 1; j >= 0; --j)
	{
		for (int i = 0; i < width; ++i)
		{
			auto r = (double)i / (width - 1);
			auto g = (double)j / (height - 1);
			auto b = 0.25;

			int ir = static_cast<int>(255.999 * r);
			int ig = static_cast<int>(255.999 * g);
			int ib = static_cast<int>(255.999 * b);

			outfile << ir << ' ' << ig << ' ' << ib << std::endl;
		}
	}
	return 0;
}