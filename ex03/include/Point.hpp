#ifndef _POINT_HPP
#define _POINT_HPP
#include "Fixed.hpp"

class Point
{
private:
	const Fixed _x;
	const Fixed _y;
	const Fixed _z;
public:
	Point();
	Point(const float x, const float y);
	Point(const float x, const float y, const float z);
	Point(const Point &rP);
	~Point();
	Point& 		operator=(const Point &rP);
	
	float		getX() const;
	float		getY() const;
	float		getZ() const;
	Point		operator-(const Point &rP) const;
};
#endif

