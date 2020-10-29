#include <iostream>

#include "vec3.h"

std::ostream& operator<<(std::ostream& os, const vec3& v)
{
	os << v.val[0] << v.val[1] << v.val[2];
	return os;
}

vec3 operator+(const vec3& lhs, const vec3& rhs)
{
	return vec3(lhs.x() + rhs.x(), lhs.y() + rhs.y(), lhs.z() + rhs.z());
}
vec3 operator-(const vec3& lhs, const vec3& rhs)
{
	return vec3(lhs.x() - rhs.x(), lhs.y() - rhs.y(), lhs.z() - rhs.z());
}
vec3 operator*(const vec3& v, double t)
{
	return vec3(t * v.x(), t * v.y(), t * v.z());
}
vec3 operator*(double t, const vec3& v)
{
	return v * t;
}
vec3 operator/(const vec3& v, double t)
{
	return v * (1 / t);
}
double dot(const vec3& lhs, const vec3& rhs)
{
	return lhs.x() * rhs.x() + lhs.y() * rhs.y() + lhs.z() * rhs.z();
}
vec3 cross(const vec3& lhs, const vec3& rhs)
{
	return vec3(lhs.y() * rhs.z() - lhs.z() * rhs.y(),
		lhs.z() * rhs.x() - lhs.x() * rhs.z(),
		lhs.x() * rhs.y() - lhs.y() * rhs.x());
}
vec3 unit_vector(vec3 v)
{
	return v / v.length();
}

vec3 random_unit_vector()
{
	auto a = random_double(0, 2 * pi);
	auto z = random_double(-1, 1);
	auto r = sqrt(1 - z * z);
	return vec3(r * cos(a), r * sin(a), z);
}

vec3 random_in_unit_sphere()
{
	while (true) {
		auto p = vec3::random(-1, 1);
		if (p.length_square() >= 1) continue;
		return p;
	}
}

vec3 random_in_hemisphere(const vec3& normal)
{
	vec3 in_unit_sphere = random_in_unit_sphere();
	if (dot(in_unit_sphere, normal) > 0.0)
		return in_unit_sphere;
	else
		return -in_unit_sphere;
}
