#include "Fixed.hpp"
#include <iostream>

const int	Fixed::fractionBit = Fixed::NB_FRACTIONAL_BITS;

Fixed::Fixed() :_fixedPointValue(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &rFixed)
{
	std::cout << "Copy constructor called\n";
	_fixedPointValue = rFixed.getRawBits();
}

Fixed& Fixed::operator=(const Fixed &rFixed)
{
	std::cout << "Copy assignment operator called\n";
	_fixedPointValue = rFixed.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}


int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return (_fixedPointValue);
}

void	Fixed::setRawBits(int const raw)
{
	_fixedPointValue = raw;
}
