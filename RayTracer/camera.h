#pragma once

#include "ray.h"

class camera
{
public:
	camera();
	inline ray get_ray(double u, double v) const
	{
		return ray(origin, lower_left_corner + u * horizontal + v * vertical - origin);
	}
private:
	point3 origin;
	point3 lower_left_corner;
	vec3 horizontal;
	vec3 vertical;
};