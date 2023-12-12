#pragma once

#include <iostream>

namespace gmd
{
	class Vector2
	{
	public:
		float X, Y;

		Vector2();
		Vector2(float x, float y);
		Vector2(const gmd::Vector2& rhs);

		bool operator==(const Vector2& rhs) const;
		bool operator!=(const Vector2& rhs) const;
		gmd::Vector2 operator+=(const gmd::Vector2& rhs);
		gmd::Vector2 operator*(const float& rhs) const;
		gmd::Vector2 operator-(const gmd::Vector2& rhs) const;
		gmd::Vector2 operator+(const gmd::Vector2& rhs) const;
		gmd::Vector2 operator*=(const gmd::Vector2& rhs);
		gmd::Vector2 operator/=(const gmd::Vector2& rhs);
		gmd::Vector2 operator/=(const float rhs);
		gmd::Vector2 operator*(const gmd::Vector2& rhs) const;

		friend std::ostream& operator<<(std::ostream& os, const gmd::Vector2& rhs);

	public:
		static const gmd::Vector2 SCREEN_MIDDLE;
	};

	std::ostream& operator<<(std::ostream& os, const gmd::Vector2& rhs);
}