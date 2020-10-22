#include <iostream>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

int main()
{
	const int width = 256;
	const int height = 256;

	const char* path = "../Output/Image.png";

	unsigned char* frame = new unsigned char[width * height * 3];
	for (int j = 0; j < height; ++j)
	{
		for (int i = 0; i < width; ++i)
		{
			double r = (double)i / (width - 1.0);
			double g = (double)j / (height - 1.0);
			double b = 0.25;

			auto ir = static_cast<unsigned char>(255.999 * r);
			auto ig = static_cast<unsigned char>(255.999 * g);
			auto ib = static_cast<unsigned char>(255.999 * b);

			frame[3 * (j * height + i)    ] = ir;
			frame[3 * (j * height + i) + 1] = ig;
			frame[3 * (j * height + i) + 2] = ib;
		}
	}
	stbi_write_png(path, width, height, 3, frame, 0);
	return 0;
}