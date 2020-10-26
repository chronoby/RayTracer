#pragma once

#include "hittable.h"

class sphere : public hittable
{
public:
	sphere() {  }
	sphere(vec3 cen, double r) : center(cen), radius(r) {}
	virtual bool hit(const ray& r, double t_min, double t_max, hit_record& rec) const override;
private:
	vec3 center;
	double radius;
};
