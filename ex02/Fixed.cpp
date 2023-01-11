#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int	Fixed::fractionBit = Fixed::NB_FRACTIONAL_BITS;

Fixed::Fixed() :_fixedPointValue(0)
{}

Fixed::Fixed(const Fixed &rFixed)
{
	_fixedPointValue = rFixed._fixedPointValue;
}

Fixed& Fixed::operator=(const Fixed &rFixed)
{
	_fixedPointValue = rFixed._fixedPointValue;
	return (*this);
}

Fixed::~Fixed()
{}


Fixed::Fixed(const int d)
{
	_fixedPointValue = d << NB_FRACTIONAL_BITS;
}

Fixed::Fixed(const float f)
{
	_fixedPointValue = static_cast<int>(roundf(f * static_cast<float>((1 << NB_FRACTIONAL_BITS))));
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(_fixedPointValue) / static_cast<float>((1 << NB_FRACTIONAL_BITS)));
}

int	Fixed::toInt(void) const
{
	return (_fixedPointValue >> NB_FRACTIONAL_BITS);
}

void	Fixed::displayForFixed(void) const
{
	for (int i = 31; i >= 0; i--)
	{
		int	binary = ((_fixedPointValue >> i) & 1);
		std::cout << binary;
		if (i == NB_FRACTIONAL_BITS)
			std::cout << '\t';
	}
	std::cout << std::endl;
}

void	Fixed::displayForFloat(void) const
{
	int count = 1;
	for (int i = 31; i >= 0; i--)
	{
		int	binary = ((_fixedPointValue >> i) & 1);
		std::cout << binary;
		if (binary && count)
		{
			count = 0;
			std::cout << '\t';
		}
	}
	std::cout << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	/*
	displayForFixed();	
	displayForFloat();
	*/
	return (_fixedPointValue);
}

void	Fixed::setRawBits(int const raw)
{
	_fixedPointValue = raw;
}

std::ostream& operator<<(std::ostream &os, const Fixed &rFixed)
{
	os << rFixed.toFloat();
	return (os);
}

bool	Fixed::operator>(const Fixed &rFixed) const
{
	return (_fixedPointValue > rFixed._fixedPointValue);
}

bool	Fixed::operator<(const Fixed &rFixed) const
{
	return (_fixedPointValue < rFixed._fixedPointValue);
}

bool	Fixed::operator>=(const Fixed &rFixed) const
{
	return (!((*this) < rFixed));
}
	
bool	Fixed::operator<=(const Fixed &rFixed) const
{
	return (!((*this) > rFixed));
}

bool	Fixed::operator==(const Fixed &rFixed) const
{
	return (_fixedPointValue == rFixed._fixedPointValue);
}

bool	Fixed::operator!=(const Fixed &rFixed) const
{
	return (!((*this) == rFixed));
}
	
Fixed	Fixed::operator+(const Fixed &rFixed) const
{
	return (Fixed(*this).toFloat() + rFixed.toFloat());
}

Fixed	Fixed::operator-(const Fixed &rFixed) const
{
	return (Fixed(*this).toFloat() - rFixed.toFloat());
}

Fixed	Fixed::operator*(const Fixed &rFixed) const
{
	return (Fixed((*this).toFloat() * rFixed.toFloat()));
}
	
Fixed	Fixed::operator/(const Fixed &rFixed) const
{
	return (Fixed((*this).toFloat() / rFixed.toFloat()));
}
	
Fixed	Fixed::operator++(int x)
{
	(void)x;
	Fixed	tmp(*this);
	_fixedPointValue++;
	return (tmp);
}
	
Fixed&	Fixed::operator++()
{
	_fixedPointValue++;
	return (*this);
}	

Fixed	Fixed::operator--(int x)
{
	(void)x;
	Fixed	tmp(*this);
	_fixedPointValue--;
	return (tmp);	
}

Fixed&	Fixed::operator--()
{
	_fixedPointValue--;
	return (*this);
}

Fixed& Fixed::min(Fixed &r1, Fixed &r2)
{
	if (r1 < r2)
		return (r1);
	return (r2);
}

const Fixed& Fixed::min(const Fixed &r1, const Fixed &r2)
{
	if (r1 < r2)
		return (r1);
	return (r2);
}
	
Fixed& Fixed::max(Fixed &r1, Fixed &r2)
{
	if (r1 > r2)
		return (r1);
	return (r2);
}
	
const Fixed& Fixed::max(const Fixed &r1, const Fixed &r2)
{
	if (r1 > r2)
		return (r1);
	return (r2);
}

