#include "Point.hpp"
#include <iostream>


bool	bsp(Point const a, Point const b, Point const c, Point const point);
bool	isValidPoint(Point const a, Point const b, Point const c);

void	showInOrOut(Point& a, Point& b , Point& c, Point& point)
{
	if (isValidPoint(a, b, c) == false)
	{
		std::cout << "Can't make Triangle" << std::endl;
		return ;
	}
	if (bsp(a, b, c, point))
		std::cout << "Inner Point" << std::endl;
	else
		std::cout << "Not Inner Point" << std::endl;
}


int	main(void)
{

	Point	a(3.0, 3.0);
	Point	b(1.0, 1.0);
	Point	c(5.0, 1.0);

	//Inner Test
	Point	innerPoint(2.0, 1.8);
	showInOrOut(a, b, c, innerPoint);

	//edge Test
	Point	edgePoint(1.0, 1.0);
	showInOrOut(a, b, c, edgePoint);

	//Line Test
	Point	LinePoint(3.0, 1.0);
	showInOrOut(a, b, c, LinePoint);

	//Outer Test
	Point	outPoint(1.5, 2.0);
	showInOrOut(a, b, c, outPoint);
	return (0);
}
