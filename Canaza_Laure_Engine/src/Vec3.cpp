#include "Vec3.h"

#include <math.h>

namespace Vec3
{
	Vec3::Vec3()
	{
		x = 0.f;
		y = 0.f;
		z = 0.f;
	}

	Vec3::Vec3(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	float Vec3::Dot(Vec3 vec1, Vec3 vec2)
	{
		return vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z;
	}

	float Vec3::GetMagnitude(Vec3 vec)
	{
		return sqrtf(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
	}

	Vec3 Vec3::GetNormalized(Vec3 vec)
	{
		float vecMangitude = GetMagnitude(vec);

		if (vecMangitude > epsilon)
		{
			vec.x /= vecMangitude;
			vec.y /= vecMangitude;
			vec.z /= vecMangitude;
		}

		return Vec3(vec);
	}

	void Vec3::Normalize()
	{
		float vecMangitude = GetMagnitude(*this);

		if (vecMangitude > epsilon)
		{
			x /= vecMangitude;
			y /= vecMangitude;
			z /= vecMangitude;
		}
	}

	Vec3 Vec3::operator+(const Vec3 other)
	{
		return Vec3(other.x + x, other.y + y, other.z + z);
	}

	Vec3 Vec3::operator-(const Vec3 other)
	{
		return Vec3(x - other.x, y - other.y, z - other.z);
	}

	Vec3 Vec3::operator*(const float scalar)
	{
		return Vec3(x * scalar, y * scalar, z * scalar);
	}

	bool Vec3::operator==(const Vec3 other)
	{
		float num = other.x - x;
		float num2 = other.y - y;
		float num3 = other.z - z;
		return num * num + num2 * num2 + num3 * num3 < epsilon * epsilon;
	}

	bool Vec3::operator!=(const Vec3 other)
	{
		return !(*this == other);
	}

	Vec3::~Vec3()
	{

	}
}
