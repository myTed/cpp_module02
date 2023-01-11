#ifndef _POINT_HPP
#define _POINT_HPP
#include "Fixed.hpp"

class Point
{
private:
	Fixed const _x;
	Fixed const _y;
	Fixed const _z;
public:
	Point();
	Point(const float x, const float y);
	Point(const float x, const float y, const float z);
	Point& Point(const Point &rP);
	Point& operator=(const Point &rP);
	
	float	getX() const;
	float	getY() const;
	float	getZ() const;
	Point operator-(const Point &rP);
	~Point();
};
#endif

