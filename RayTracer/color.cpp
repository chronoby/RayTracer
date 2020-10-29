#include "color.h"
#include "util.h"

void write_color(unsigned char* frame, vec3 pixel_color, int pos, int samples_per_pixel)
{
	auto r = pixel_color.x();
	auto g = pixel_color.y();
	auto b = pixel_color.z();
	
	// Divede the color by the number of samples
	auto scale = 1.0 / samples_per_pixel;
	r = sqrt(scale * r);
	g = sqrt(scale * g);
	b = sqrt(scale * b);
	frame[pos    ] = static_cast<unsigned char>(256 * clamp(r, 0.0, 0.999));
	frame[pos + 1] = static_cast<unsigned char>(256 * clamp(g, 0.0, 0.999));
	frame[pos + 2] = static_cast<unsigned char>(256 * clamp(b, 0.0, 0.999));
}