#include "Point.hpp"

float	dotProduct(const Point &a, const Point &b)
{
	return (a.getX() * b.getX() +
			a.getY() * b.getY() +
			a.getZ() * b.getZ()
		   );
}

Point	crossProduct(const Point& a, const Point& b)
{
	float 	new_x = (a.getY() * b.getZ()) - (a.getZ() * b.getY());
	float	new_y = (a.getZ() * b.getX()) - (a.getX() * b.getZ());
	float	new_z = (a.getX() * b.getY()) - (a.getY() * b.getX());
	return (Point(new_x, new_y, new_z));
}


bool	isSameDirectionFromLine(
			const Point& start,
			const Point& end, 
			const Point& oppossite,
			const Point& point
)
{
	Point tmp1 = crossProduct(end - start, point - start);
	Point tmp2 = crossProduct(end - start, oppossite - start);
	return (dotProduct(tmp1, tmp2) > 0);
}


bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	return (isSameDirectionFromLine(a, b, c, point) &
			isSameDirectionFromLine(b, c, a, point) &
			isSameDirectionFromLine(c, a, b, point));
}


bool	isValidPoint(Point const a, Point const b, Point const c)
{
	Point tmp1 = crossProduct(b - a, c - a);
	if (tmp1.getZ() == 0)
		return (false);
	return (true);
}
