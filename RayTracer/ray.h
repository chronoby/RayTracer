#pragma once

#include "vec3.h"

class ray
{
public:
	ray() {  }
	ray(const vec3& orig, const vec3& dire) 
		: r_origin(orig), r_direction(dire) { }
	inline vec3 origin() const { return r_origin; }
	inline vec3 direction() const { return r_direction; }

private:
	vec3 r_origin;
	vec3 r_direction;
};