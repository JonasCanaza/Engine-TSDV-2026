#pragma once

namespace Vec3
{
	const float epsilon = 1e-06f;

	class Vec3
	{
	public:
		float x;
		float y;
		float z;

		Vec3();
		Vec3(float x, float y, float z);

		static float Dot(Vec3 vec1, Vec3 vec2);
		static float GetMagnitude(Vec3 vec);
		static Vec3 GetNormalized(Vec3 vec);
		void Normalize();

		Vec3 operator+(const Vec3 other);
		Vec3 operator-(const Vec3 other);
		Vec3 operator*(const float scalar);
		bool operator==(const Vec3 other);
		bool operator!=(const Vec3 other);

		~Vec3();
	};
}

