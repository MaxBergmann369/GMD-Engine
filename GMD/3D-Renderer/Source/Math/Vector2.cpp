#include "Vector2.h"

gmd::Vector2::Vector2()
{
	this->X = 0.0f;
	this->Y = 0.0f;
}

gmd::Vector2::Vector2(float x, float y)
{
	this->X = x;
	this->Y = y;
}

gmd::Vector2::Vector2(const gmd::Vector2& rhs)
{
	this->X = rhs.X;
	this->Y = rhs.Y;
}


bool gmd::Vector2::operator==(const Vector2& rhs) const
{
	return(rhs.X == this->X
		&& rhs.Y == this->Y);
}

bool gmd::Vector2::operator!=(const Vector2& rhs) const
{
	return(rhs.X != this->X
		|| rhs.Y != this->Y);
}

gmd::Vector2 gmd::Vector2::operator+=(const gmd::Vector2& rhs)
{
	return gmd::Vector2(this->X += rhs.X, this->Y += rhs.Y);
}

gmd::Vector2 gmd::Vector2::operator*(const float& rhs) const
{
	return gmd::Vector2(this->X * rhs, this->Y * rhs);
}
 
gmd::Vector2 gmd::Vector2::operator-(const gmd::Vector2& rhs) const
{
	return gmd::Vector2(this->X - rhs.X, this->Y - rhs.Y);
}

gmd::Vector2 gmd::Vector2::operator+(const gmd::Vector2& rhs) const
{
	return gmd::Vector2(this->X + rhs.X, this->Y + rhs.Y);
}

gmd::Vector2 gmd::Vector2::operator*=(const gmd::Vector2& rhs)
{
	return gmd::Vector2(this->X *= rhs.X, this->Y *= rhs.Y);
}

gmd::Vector2 gmd::Vector2::operator/=(const gmd::Vector2& rhs) 
{
	return gmd::Vector2(this->X /= rhs.X, this->Y /= rhs.Y);
}

gmd::Vector2 gmd::Vector2::operator/=(const float rhs)
{
	return gmd::Vector2(this->X /= rhs, this->Y /= rhs);
}
gmd::Vector2 gmd::Vector2::operator*(const gmd::Vector2& rhs) const
{
	return gmd::Vector2(this->X * rhs.X, this->Y * rhs.Y);
}


std::ostream& gmd::operator<<(std::ostream& os, const gmd::Vector2& rhs)
{
	os << rhs.X << " x " << rhs.Y << " y ";
	return os;
}

const gmd::Vector2 gmd::Vector2::SCREEN_MIDDLE = gmd::Vector2(1920 / 2, 1080 / 2);