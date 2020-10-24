#include "color.h"

void write_color(unsigned char* frame, vec3 pixel_color, int pos)
{
	frame[pos    ] = static_cast<unsigned char>(255.999 * pixel_color.x());
	frame[pos + 1] = static_cast<unsigned char>(255.999 * pixel_color.y());
	frame[pos + 2] = static_cast<unsigned char>(255.999 * pixel_color.z());
}