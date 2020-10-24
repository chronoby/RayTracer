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