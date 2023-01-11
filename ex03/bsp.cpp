#include "Point.hpp"

float	dotProduct(const Point &a, const Point &b)
{
	return (a.getX() * b.getX() +
			a.getY() * b.getY() +
			a.getZ() * b.getZ()
		   );
}

Point	crossProduct(const Point &a, const Point &b)
{
	float 	new_x = (a.getY() * b.getZ()) - (a.getZ() * b.getY());
	float	new_y = (a.getZ() * b.getX()) - (a.getX() * b.getZ());
	float	new_z = (a.getX() * b.getY()) - (a.getY() * b.getX());
	return (Point(new_x, new_y, new_z));
}


bool	isSameSide(const Point &a, const Point &b, const Point &c,
					const Point &p)
{
	Point tmp1 = crossProduct(b - a, p - a);
	Point tmp2 = crossProduct(b - a, c - a);
	return (dotProduct(tmp1, tmp2) >= 0);
}


bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	return (isSameSide(a, b, c, p) &
			isSameSize(b, c, a, p) &
			isSameSide(c, a, b, p));
}
