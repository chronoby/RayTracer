#include <iostream>
#include <cstdio>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#include "color.h"
#include "sphere.h"
#include "hittable_list.h"
#include "util.h"
#include "camera.h"
#include "vec3.h"

#define PBSTR "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"
#define PBWIDTH 60

void printProgress(double percentage) {
	int val = (int)(percentage * 100);
	int lpad = (int)(percentage * PBWIDTH);
	int rpad = PBWIDTH - lpad;
	printf("\r%3d%% [%.*s%*s]", val, lpad, PBSTR, rpad, "");
	fflush(stdout);
}


vec3 ray_color(const ray& r, const hittable& world, int depth)
{
	hit_record rec;
	if (depth <= 0)
		return color(0.0, 0.0, 0.0);
	if (world.hit(r, 0.001, infinity, rec))
	{
		point3 target = rec.p + rec.normal + random_in_hemisphere(rec.normal);
		return 0.5 * ray_color(ray(rec.p, target - rec.p), world, depth - 1);
	}
	vec3 unit_direction = unit_vector(r.direction());
	auto t = 0.5 * (unit_direction.y() + 1.0);
	return (1.0 - t) * vec3(1.0, 1.0, 1.0) + t * vec3(0.5, 0.7, 1.0);
}

int main()
{
	// image
	const double aspect_ratio = 16.0 / 9.0;
	const int image_width = 400;
	const int image_height = static_cast<int>(image_width / aspect_ratio);
	const int sample_per_pixel = 100;
	const int max_depth = 50;
	
	// world
	hittable_list world;
	world.add(make_shared<sphere>(point3(0, 0, -1), 0.5));
	world.add(make_shared<sphere>(point3(0, -100.5, -1), 100));

	// camera
	camera cam;

	// render
	const char* path = "../Output/Image.png";

	unsigned char* frame = new unsigned char[image_width * image_height * 3];

	for (int j = image_height - 1; j >= 0; --j)
	{
		double v = (double)j / (image_height - 1.0);
		for (int i = 0; i < image_width; ++i)
		{
			color pixel_color(0, 0, 0);
			for (int s = 0; s < sample_per_pixel; ++s)
			{
				auto u = (i + random_double()) / (image_width - 1.0);
				auto v = (j + random_double()) / (image_height - 1.0);
				ray r = cam.get_ray(u, v);
				pixel_color += ray_color(r, world, max_depth);
			}
			write_color(frame, pixel_color, 3 * ((image_height - j - 1) * image_width + i), sample_per_pixel);
		}
		printProgress(((double)image_height - (double)j) / (double)image_height);
	}
	stbi_write_png(path, image_width, image_height, 3, frame, 0);
	std::cout << "Done!" << std::endl;
	return 0;
}