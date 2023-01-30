#include "Point.hpp"

Point::Point() 
		: _x(0), _y(0), _z(0) {}

Point::Point(const float x, const float y)
		:_x(x), _y(y), _z(0){}

Point::Point(const float x, const float y, const float z)
		:_x(x), _y(y), _z(z) {}

Point::Point(const Point &rP)
: _x(rP._x), _y(rP._y), _z(rP._z) {}

Point::~Point()
{}

Point& Point::operator=(const Point &rP)
{
	static_cast<void>(&rP);
	return (*this);	
}

float	Point::getX() const
{
	return (_x.toFloat());
}

float	Point::getY() const
{
	return (_y.toFloat());
}

float	Point::getZ() const
{
	return (_z.toFloat());
}

Point Point::operator-(const Point &rP) const
{
	return Point(getX() - rP.getX(),
				getY() - rP.getY(),
				getZ() - rP.getZ());
}
