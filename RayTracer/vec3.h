#pragma once

#include <iostream>
#include <cmath>

class vec3
{
public:
	vec3() :val{ 0,0,0 } {  }
	vec3(double x, double y, double z): val{ x, y, z } {  }
	inline double x() const { return val[0]; }
	inline double y() const { return val[1]; }
	inline double z() const { return val[2]; }
	
	vec3 operator-() const { return vec3(-val[0], -val[1], -val[2]); }
	double operator[](int i) const { return val[i]; }
	double& operator[](int i) { return val[i]; }

	vec3& operator +=(const vec3& v)
	{
		val[0] += v.val[0];
		val[1] += v.val[1];
		val[2] += v.val[2];
		return *this;
	}
	vec3& operator *=(const double t)
	{
		val[0] *= t;
		val[1] *= t;
		val[2] *= t;
		return *this;
	}
	vec3& operator /=(const double t)
	{
		return *this *= 1 / t;
	}
	inline double length() const
	{
		return sqrt(length_square());
	}
	double length_square() const
	{
		return val[0] * val[0] + val[1] * val[1] + val[2] * val[2];
	}

	friend std::ostream& operator<<(std::ostream& os, const vec3& v);

private:
	double val[3];
};

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