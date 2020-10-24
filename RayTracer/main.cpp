#include <iostream>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#include "vec3.h"
#include "color.h"
#include "ray.h"

bool hit_sphere(const vec3& center, double radius, const ray& r) {
	vec3 oc = r.origin() - center;
	auto a = dot(r.direction(), r.direction());
	auto b = 2.0 * dot(oc, r.direction());
	auto c = dot(oc, oc) - radius * radius;
	auto discriminant = b * b - 4 * a * c;
	return (discriminant > 0);
}

vec3 ray_color(const ray& r)
{
	if (hit_sphere(vec3(0, 0, -1), 0.5, r))
		return vec3(1, 0, 0);
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

	// camera
	double viewport_height = 2.0;
	double viewport_width = aspect_ratio * viewport_height;
	double focal_length = 1.0;

	auto origin = vec3(0, 0, 0);
	auto horizontal = vec3(viewport_width, 0, 0);
	auto vertical = vec3(0, viewport_height, 0);
	auto lower_left_corner = origin - horizontal / 2 - vertical / 2 - vec3(0, 0, focal_length);

	const char* path = "../Output/Image.png";

	unsigned char* frame = new unsigned char[image_width * image_height * 3];

	for (int j = 0; j < image_height; ++j)
	{
		for (int i = 0; i < image_width; ++i)
		{
			double u = (double)i / (image_width - 1.0);
			double v = (double)j / (image_height - 1.0);
			ray r(origin, lower_left_corner + u * horizontal + v * vertical - origin);

			vec3 pixel_color = ray_color(r);
			write_color(frame, pixel_color, 3 * (j * image_width + i));
		}
	}
	stbi_write_png(path, image_width, image_height, 3, frame, 0);
	return 0;
}